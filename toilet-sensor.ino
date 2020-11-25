#include <movingAvg.h>

// User-defined configuration

// Milliseconds ping time when the cistern is full
#define top 450

// Milliseconds ping time when the cistern is empty
#define bottom 1900

// Milliseconds between pings
#define sense_delay 0

// Milliseconds between display updates
#define display_delay 20




// Fixed system configuration

// 8x8 LED pin locations
#define ROW_1 8
#define ROW_2 5
#define ROW_3 10
#define ROW_4 4
#define ROW_5 A1
#define ROW_6 11
#define ROW_7 A3
#define ROW_8 13
#define COL_1 A2
#define COL_2 6
#define COL_3 7
#define COL_4 12
#define COL_5 9
#define COL_6 A0
#define COL_7 A4
#define COL_8 A5

// Ultrasound sensor pin locations
#define trigPin 1
#define echoPin 0





const byte rows[] = {
  ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

const byte EMPTY[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
const byte X[] = {
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001
};
const byte TICK[] = {
  B00000000,
  B00000001,
  B00000010,
  B00000100,
  B10001000,
  B01010000,
  B00100000,
  B00000000
};

int cyclesSinceLastPulse = 0;
int cyclesSinceLastDisplayUpdate = 0;
int displayedValue = 0;

movingAvg SLOW_AVG(1000);
movingAvg FAST_AVG(50);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //setup screen
  for (byte i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  SLOW_AVG.begin();
  FAST_AVG.begin();
}

void loop() {
  int previousSlowAvgValue = SLOW_AVG.getAvg();

  if (cyclesSinceLastPulse > sense_delay) {
    long duration = sense();
    FAST_AVG.reading(duration);
    SLOW_AVG.reading(duration);

    print_info(duration, FAST_AVG, SLOW_AVG);

    cyclesSinceLastPulse = 0;
  } else {
    cyclesSinceLastPulse++;
  }

  bool flushing;

  if (SLOW_AVG.getAvg() != previousSlowAvgValue) {
    flushing = SLOW_AVG.getAvg() > previousSlowAvgValue;
  }

  if (cyclesSinceLastDisplayUpdate > display_delay) {
    if (flushing) {
      displayedValue = FAST_AVG.getAvg();
    } else {
      displayedValue = SLOW_AVG.getAvg();
    }
    cyclesSinceLastDisplayUpdate = 0;
  } else {
    cyclesSinceLastDisplayUpdate++;
  }

  updateDisplay(displayedValue);
}

void updateDisplay(long duration) {
  if (inRange(duration)) {
    drawFillLevel(duration);
  } else if (isEmpty(duration)) {
    drawScreen(EMPTY);
  } else if (isFull(duration)) {
    drawScreen(TICK);
  }
}

void drawFillLevel(long duration) {
  int range = bottom - top;
  double relativeFill = bottom - duration;
  double fractionalFill = (double)relativeFill / range;
  int filledPixels = fractionalFill * 64;

  byte toDraw[8];
  buildDots(toDraw, filledPixels);
  drawScreen(toDraw);
}

void print_info(long duration, movingAvg avg_short, movingAvg avg_long) {
  Serial.print(duration);
  Serial.print(",");
  Serial.print(avg_short.getAvg());
  Serial.print(",");
  Serial.println(avg_long.getAvg());
}

bool inRange(long duration) {
  return !isEmpty(duration) && !isFull(duration);
}

bool isEmpty(long duration) {
  return duration > bottom;
}

bool isFull(long duration) {
  return duration < top;
}

long sense() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void buildDots(byte *screen, int count) {
  byte ROWS[] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  };

  byte FILLER[] = {
    B00000000,
    B10000000,
    B11000000,
    B11100000,
    B11110000,
    B11111000,
    B11111100,
    B11111110,
    B11111111
  };

  // Fill rows bottom to top, as a real toilet does
  for (int i = 7; i >= 0; i--) {
    if (count >= 8) {
      ROWS[i] = FILLER[8];
      count = count - 8;
    } else {
      ROWS[i] = FILLER[count];
      count = 0;
    }
  }

  copyScreenContents(ROWS, screen);
}

void copyScreenContents(byte *source, byte *dest) {
  for (int i = 0; i < 8; i++) {
    dest[i] = source[i];
  }
}

void  drawScreen(const byte buffer2[])
{
  // Turn on each row in series
  for (byte i = 0; i < 8; i++)        // count next row
  {
    digitalWrite(rows[i], HIGH);    //initiate whole row
    for (byte a = 0; a < 8; a++)    // count next row
    {
      // if You set (~buffer2[i] >> a) then You will have positive
      digitalWrite(col[a], (~buffer2[i] >> a) & 0x01); // initiate whole column

      delayMicroseconds(50);       // uncoment deley for diferent speed of display

      digitalWrite(col[a], 1);      // reset whole column
    }
    digitalWrite(rows[i], LOW);     // reset whole row
    // otherwise last row will intersect with next row
  }
}
