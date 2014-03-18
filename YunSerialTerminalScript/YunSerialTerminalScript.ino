/*
  Arduino Yun USB-to-Serial

 Allows you to use the Yun's 32U4 processor as a
 serial terminal for the linino processor.

 The circuit:
 * Arduino Yun

 created March 2013
 by Massimo Banzi
 modified by Cristian Maglie
 
 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/YunSerialTerminal

 
 18/03/2014
 modified by Ithos for the instructables example.


 */
void setup() {
  Serial.begin(9600);      // open serial connection via USB-Serial
  Serial1.begin(9600);     // open serial connection to Linino
}

void loop() {

  if (Serial.available()) {          // got anything from USB-serial?
    char c = (char)Serial.read();    // read from USB-serial
    Serial1.write(c);                  // write to Linino
  }

  if (Serial1.available()) {          // got anything from Linino?
    char c = (char)Serial1.read();    // read from Linino
    Serial.write(c);                  // write to USB-serial
  }

}
