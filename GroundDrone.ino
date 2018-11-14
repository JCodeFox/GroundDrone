/*
  LiquidCrystal Library - Custom Characters

  Demonstrates how to add custom characters on an LCD  display.
  The LiquidCrystal library works with all LCD displays that are
  compatible with the  Hitachi HD44780 driver. There are many of
  them out there, and you can usually tell them by the 16-pin interface.

  This sketch prints "I <heart> Arduino!" and a little dancing man
  to the LCD.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K potentiometer:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
   10K poterntiometer on pin A0

  created 21 Mar 2011
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 7 Nov 2016
  by Arturo Guadalupi

  Based on Adafruit's example at
  https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/LiquidCrystalCustomCharacter

  Also useful:
  http://icontexto.com/charactercreator/

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte frame1[8] = {
  0b00100,
  0b10110,
  0b01100,
  0b01010,
  0b00010,
  0b01011,
  0b00110,
  0b00101
};

byte frame2[8] = {
  0b00010,
  0b01011,
  0b00110,
  0b00110,
  0b00001,
  0b10101,
  0b00011,
  0b00011
};

byte frame3[8] = {
  0b00001,
  0b10101,
  0b00011,
  0b10010,
  0b10000,
  0b11010,
  0b10001,
  0b01001
};

byte frame4[8] = {
  0b10000,
  0b11010,
  0b10001,
  0b10001,
  0b01000,
  0b01101,
  0b11000,
  0b11000
};

byte frame5[8] = {
  0b01000,
  0b01101,
  0b11000,
  0b10100,
  0b00100,
  0b10110,
  0b01100,
  0b01010
};

byte frame6[8] = {
  0b00100,
  0b10110,
  0b01100,
  0b01100,
  0b00010,
  0b01011,
  0b00110,
  0b00110
  };

byte frame7[8] = {
  0b00010,
  0b01011,
  0b00110,
  0b00101,
  0b00001,
  0b10101,
  0b00011,
  0b10010
};

byte frame8[8] = {
  0b00001,
  0b10101,
  0b00011,
  0b00011,
  0b10000,
  0b11010,
  0b10001,
  0b10001
};

byte frame9[8] = {
  0b10000,
  0b11010,
  0b10001,
  0b01001,
  0b01000,
  0b01101,
  0b11000,
  0b10100
};

byte frame10[8] = {
  0b01000,
  0b01101,
  0b11000,
  0b11000,
  0b00100,
  0b10110,
  0b01100,
  0b01100
};
const int frames=10;
int frame=0;

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, frame1);
  lcd.createChar(1, frame2);
  lcd.createChar(2, frame3);
  lcd.createChar(3, frame4);
  lcd.createChar(4, frame5);
  lcd.createChar(5, frame6);
  lcd.createChar(6, frame7);
  lcd.createChar(7, frame8);
  lcd.createChar(8, frame9);
  lcd.createChar(9, frame10);
  // set the cursor to the top left
  lcd.setCursor(0, 0);

}

void loop() {
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  frame++;
  if(frame>=10){
    frame=frames;
  }
  for(int y=0;y<2;y++){
      for(int x=0;x<16;x++){
        // set the cursor to the bottom row, 5th position:
        lcd.setCursor(x, y);
        // draw the little man, arms down:
        lcd.write(byte(frame));
      }
  }
  delay(delayTime);
}
