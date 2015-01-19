#include <HSBColor.h>

// - - - - -
// DmxSerial - A hardware supported interface to DMX.
// DmxSerialRecv.ino: Sample DMX application for retrieving 3 DMX values:
// address 1 (red) -> PWM Port 9
// address 2 (green) -> PWM Port 6
// address 3 (blue) -> PWM Port 5
// 
// Copyright (c) 2011 by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// 
// Documentation and samples are available at http://www.mathertel.de/Arduino
// 25.07.2011 creation of the DmxSerial library.
// 10.09.2011 fully control the serial hardware register
//            without using the Arduino Serial (HardwareSerial) class to avoid ISR implementation conflicts.
// 01.12.2011 include file and extension changed to work with the Arduino 1.0 environment
// 28.12.2011 changed to channels 1..3 (RGB) for compatibility with the DmxSerialSend sample.
// 10.05.2012 added some lines to loop to show how to fall back to a default color when no data was received since some time.
// - - - - -

#include <DMXSerial.h>

// Constants for demo program
const int RedPin   =   9;  // PWM output pin for Red Light.
const int GreenPin =  10;  // PWM output pin for Green Light.
const int BluePin  =  11;  // PWM output pin for Blue Light.

int rbg_array[3];

int dmxAddress = 19; //1,2,3  4,5,6  7 8 9     10 11 12,        13, 14, 15     16 17 18,  19 20 21   22 23 24

void setup () {
  DMXSerial.init(DMXReceiver);
 
  // set some default values
  DMXSerial.write(1, 0);
  DMXSerial.write(2, 0);
  DMXSerial.write(3, 0);
  
  // enable pwm outputs
  pinMode(RedPin,   OUTPUT); // sets the digital pin as output
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin,  OUTPUT);
  
}

void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    // read recent DMX values and set pwm levels 
    analogWrite(RedPin,   DMXSerial.read(dmxAddress));
    analogWrite(GreenPin, DMXSerial.read(dmxAddress+1));
    analogWrite(BluePin,  DMXSerial.read(dmxAddress+2));

  } else {
    
    float b1 = float(millis())/810.0f;   
    float h1 = float(millis())/5060.0f;
    float s1 = float(millis())/1460.0f;  
  
    float hue = perlinNoise1D(h1);
    float sat = perlinNoise1D(s1);
    float val = perlinNoise1D(b1);
    
    H2R_HSBtoRGBfloat(hue, sat, val, rbg_array);
        
    analogWrite(RedPin,   rbg_array[0]);
    analogWrite(GreenPin, rbg_array[1]);
    analogWrite(BluePin,  rbg_array[2]);
    
  } // if
}

