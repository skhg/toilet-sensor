// setup screen
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
//setup screen



#define trigPin 1
#define echoPin 0

#define minDuration 400
#define maxDuration 1800

#define sleepDelay 500
#define flushDelay 100

//setup screen
const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

const byte ALL[] = {
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111};
const byte EX[] = {
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
  B00010000,
  B00000000};
const byte A[] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110};
const byte B[] = {
  B01111000,
  B01001000,
  B01001000,
  B01110000,
  B01001000,
  B01000100,
  B01000100,
  B01111100};
const byte C[] = {
  B00000000,
  B00011110,
  B00100000,
  B01000000,
  B01000000,
  B01000000,
  B00100000,
  B00011110};
const byte D[] = {
  B00000000,
  B00111000,
  B00100100,
  B00100010,
  B00100010,
  B00100100,
  B00111000,
  B00000000};
const byte E[] = {
  B00000000,
  B00111100,
  B00100000,
  B00111000,
  B00100000,
  B00100000,
  B00111100,
  B00000000};
const byte F[] = {
  B00000000,
  B00111100,
  B00100000,
  B00111000,
  B00100000,
  B00100000,
  B00100000,
  B00000000};
const byte G[] = {
  B00000000,
  B00111110,
  B00100000,
  B00100000,
  B00101110,
  B00100010,
  B00111110,
  B00000000};
const byte H[] = {
  B00000000,
  B00100100,
  B00100100,
  B00111100,
  B00100100,
  B00100100,
  B00100100,
  B00000000};
const byte I[] = {
  B00000000,
  B00111000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000,
  B00000000};
const byte J[] = {
  B00000000,
  B00011100,
  B00001000,
  B00001000,
  B00001000,
  B00101000,
  B00111000,
  B00000000};
const byte K[] = {
  B00000000,
  B00100100,
  B00101000,
  B00110000,
  B00101000,
  B00100100,
  B00100100,
  B00000000};
const byte L[] = {
  B00000000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00111100,
  B00000000};
const byte M[] = {
  B00000000,
  B00000000,
  B01000100,
  B10101010,
  B10010010,
  B10000010,
  B10000010,
  B00000000};
const byte N[] = {
  B00000000,
  B00100010,
  B00110010,
  B00101010,
  B00100110,
  B00100010,
  B00000000,
  B00000000};
const byte O[] = {
  B00000000,
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000};
const byte P[] = {
  B00000000,
  B00111000,
  B00100100,
  B00100100,
  B00111000,
  B00100000,
  B00100000,
  B00000000};
const byte Q[] = {
  B00000000,
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000110,
  B00111110,
  B00000001};
const byte R[] = {
  B00000000,
  B00111000,
  B00100100,
  B00100100,
  B00111000,
  B00100100,
  B00100100,
  B00000000};
const byte S[] = {
  B00000000,
  B00111100,
  B00100000,
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  B00000000};
const byte T[] = {
  B00000000,
  B01111100,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00000000};
const byte U[] = {
  B00000000,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000};
const byte V[] = {
  B00000000,
  B00100010,
  B00100010,
  B00100010,
  B00010100,
  B00010100,
  B00001000,
  B00000000};
const byte W[] = {
  B00000000,
  B10000010,
  B10010010,
  B01010100,
  B01010100,
  B00101000,
  B00000000,
  B00000000};
const byte X[] = {
  B00000000,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B00000000};
const byte Y[] = {
  B00000000,
  B01000100,
  B00101000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00000000};
const byte Z[] = {
  B00000000,
  B00111100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00111100,
  B00000000};
const byte EMPTY[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};
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
//end screen



enum fillStates {
  EMPTYING,
  FILLING,
  FULL,
  FULL_SLEEP
};

fillStates newState(long now, long prev, fillStates currentState);

enum fillStates currentState = FULL;
long prevDuration = minDuration;
long currentDelay = flushDelay;
long cyclesInCurrentMode = 0;
long cyclesSinceLastPulse = 0;

void setup() {  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //setup screen
  for (byte i = 2; i <= 13; i++){
    pinMode(i, OUTPUT);
  }  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
 //end screen
}

void loop() {
  if(cyclesSinceLastPulse > currentDelay){
    sense();
    cyclesSinceLastPulse = 0;
  }else{
    cyclesSinceLastPulse++;
  }

  updateDisplay();
  
}

void updateDisplay() {
  if(inRange(prevDuration)){
    byte toDraw[8];

    int range = maxDuration - minDuration;

    int offset = prevDuration - minDuration;

    int fillLevel = range - offset;
    
    double rounded = (double)fillLevel/range * 64;
    buildDots(toDraw, rounded);
    drawScreen(toDraw);
    
  }else if(isEmpty(prevDuration)){
    drawScreen(X);
  }else if(isFull(prevDuration)){
    drawScreen(TICK);
  }
}

void sense() {
  long duration = pulse();

  Serial.println(duration);

  fillStates nextState = newState(duration, prevDuration, currentState);

  if(nextState != currentState){
      switch(nextState) {
        case EMPTYING: break;
        case FILLING: break;
        case FULL: break;
        case FULL_SLEEP: break;
      }
  }

  currentState = nextState;
  prevDuration = duration;
}

fillStates newState(long now, long prev, fillStates currentState) {

  switch(currentState) {
    case EMPTYING:
      // if EMPTYING and level is now higher than previous level
      // go to FILLING mode
      if(isHigher(now, prev)) {
        return FILLING;
      }
      break;
    case FILLING:
      // if FULL or SLEEP MODE or FILLING and level is now lower than previous level
      // go to EMPTYING mode
      if(isLower(now, prev)) {
        return EMPTYING;
      }
      // if FILLING and level now exceeds the max level
      // go to FULL mode
      else if(isFull(now)) {
        return FULL;
      }
      break;
    case FULL:
      // if FULL and entered state more than 30 seconds ago and is still full
      // go to sleep mode 
      if(isFull(now) && cyclesInCurrentMode > 30000) {
        return FULL_SLEEP;
      }
      // if FULL or SLEEP MODE or FILLING and level is now lower than previous level
      // go to EMPTYING mode
      else if(isLower(now, prev)) {
        return EMPTYING;
      }
      break;
    case FULL_SLEEP:
      // if FULL or SLEEP MODE or FILLING and level is now lower than previous level
      // go to EMPTYING mode
      if(isLower(now, prev)) {
        return EMPTYING;
      }
      break;
  }

  return currentState;
}

bool inRange(long duration) {
  return !isEmpty(duration) && !isFull(duration);
}

bool isEmpty(long duration) {
  return duration > maxDuration;
}

bool isFull(long duration) {
  return duration < minDuration;
}

bool isLower(long now, long prev) {
  return now > prev && inRange(now);
}

bool isHigher(long now, long prev) {
  return now <= prev && inRange(now);
}

long pulse() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}



//setup screen

void buildDots(byte *screen, int count) {
  byte ROWS[] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000};

  byte FILLER[] = {
    B00000000, 
    B10000000,
    B11000000,
    B11100000,
    B11110000,
    B11111000,
    B11111100,
    B11111110,
    B11111111};

  int done = 0;
  int row = 0;
  
  while(done < count){

    if(count - done >=8){
      ROWS[8 - row] = FILLER[8];
      done += 8;
    }else{
      ROWS[8 - row] = FILLER[count - done];
      done = count;
    }

    row++;
  }

  copyScreenContents(ROWS, screen);
}

void copyScreenContents(byte *source, byte *dest) {
  for(int i=0; i<8; i++){
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
          
          delayMicroseconds(100);       // uncoment deley for diferent speed of display
          //delayMicroseconds(1000);
          //delay(10);
          //delay(100);
          
          digitalWrite(col[a], 1);      // reset whole column
        }
        digitalWrite(rows[i], LOW);     // reset whole row
        // otherwise last row will intersect with next row
    }
}
//end screen
