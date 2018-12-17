# toilet-sensor
An Arduino-based toilet cistern monitor.

## Idea
Sometimes the toilet needs an extra flush, and the cistern takes a while to fill up. How full is it? How long should I wait? 

These are important questions.

Finally, we have an answer.

![Installed sensor](docs/installed.jpg "Installed sensor")

## Materials required
Electronics:
* 1 Arduino [Leonardo](https://www.amazon.co.uk/gp/product/B00CXFJYPM/ref=oh_aui_detailpage_o01_s03?ie=UTF8&psc=1)
* 1 8x8 LED matrix
* 1 HC-SR04 Ultrasonic distance sensor
* [Ribbon cable](https://www.amazon.de/gp/product/B076CLY8NH/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1)
* [Jumper pin connectors](https://www.amazon.de/gp/product/B01MRSUEHD/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1)
* 1 Ethernet cable
* 1 [Mini breadboard](https://www.amazon.de/gp/product/B01M9CHKO4/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1)
* 1 USB power supply

Other:
* 1 Small plastic box
* Double-sided sticky tape
* Cardboard
* Small screws
* Drill and assorted bits
* Various small pliers, screwdriver, common tools

## Construction
This was done in 2 parts, with the sensor adapter and the display module built seperately

### Sensor
Within the toilet cistern I found that there were 2 removable plastic clips which hold a protective plate onto it's front. Each of these had a small pre-existing hole bored through it, which was ideal for mounting the sensor in the right direction. To this plastic clip I attached an angled piece of metal, and the mini breadboard on the other end. The sensor sits here facing downward and "secured" by a tie-wrap. I cut open an Ethernet cable and used 4 of the inner wires to connect the breadboard.

<img src="docs/sensor-1.jpg" width="425" title="Sensor adapter"> <img src="docs/sensor-2.jpg" width="425" title="Installed - close up"> <img src="docs/sensor-3.jpg" width="425" title="Installed - wider view">



## Installation

## Code
See the full Arduino C++ code in [toilet-sensor.ino](toilet-sensor.ino). 

## Circuit
![Circuit diagram](docs/wiring.jpg "Circuit diagram")

This can also be viewed in the [Fritzing](http://fritzing.org/) software using the [diagram.fzz](diagram.fzz) file. 

## Calibration
Once the sensor and display are installed, the readings must be calibrated, since we don't know exactly how high or low the water level will be in comparison to our test runs. This can be done very easily by capturing the serial output of the Arduino and exporting it to a spreadsheet.

![Flush graph](docs/flush-graph.png "Flush graph")

Due to the confined space within the cistern and the natural movement of the water as it refills, the data at the start and end of the refill cycle is quite noisy. Ideally this would be solved by taking higher frequency measurements and smoothing for an average value, but this can come later.

For simplicity we can take this example and take the `top` value as `400` and the `bottom` value as `1900`. These values are configured at the top of the code file.

## References
These tutorials and guides proved useful during the project

* [Programming 8x8 LED Matrix](https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a)
* [Simple Arduino and HC-SR04 Example](https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/)
