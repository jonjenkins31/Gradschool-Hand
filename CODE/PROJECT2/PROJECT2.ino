#include <Arduino.h>

/*********************************************************************

    Name    : LCD Button Shield Menu
    Author  : Jonathan Jenkins
    Created : June 14, 2016
    Last Modified: June 14, 2016
    Version : 1.0
    
Key Information:
  - Revision 1.0
  - Board : Arduino nano
  
 Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.
*********************************************************************/


 // **************** INCLUDE NECESSARY LIBRARIES *****************

#include <SPI.h>
#include <Wire.h>
#include <Servo.h>




// **************** GENERAL VARIABLES *****************

// INITIATE CONSTANT INTEGERS
// constants won't change. They're used here to set pin numbers:
  const int fsrPin = A2; //  the FSR and 10K pulldown
  const int HALLpin = A1; // input pullup
  const int Temppin = A3; // input pullup
  const int pixel = 4 ;


  
 // INITIATE VARIABLES (GLOBAL)
 // variables will change:
  int SerialSensorMore = true; // PUSH BUTTON 1 --- ARM 
  int forceMeasured = 0; // PUSH BUTTON 1 --- ARM 
  int tempmeasured = 0; // PUSH BUTTON 1 --- ARM 
  int force2measured= 0; // PUSH BUTTON 1 --- ARM 
  int force1measured = 0; // PUSH BUTTON 1 --- ARM 
   int pixelLT = 0;
    int pixelRT = 0 ;



// ****************SERVO *****************

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

// INITIATE CONSTANT INTEGERS
// constants won't change. They're used here to set pin numbers:
  const int servo1 = 13; //  the FSR and 10K pulldown
  const int servo2 = 12; // input pullup
  const int servo3 = 11; // input pullup
  const int servo4 = 3;

 // INITIATE VARIABLES 
 // variables will change:
int pos = 0;    // variable to store the servo position
int servooldState=0;
int servonewState=0;
int servotask=0;



// ****************Menu *****************


// You can have up to 10 menu items in the menuItems[] array below without having to change the base programming at all. Name them however you'd like. Beyond 10 items, you will have to add additional "cases" in the switch/case
// section of the operateMainMenu() function below. You will also have to add additional void functions (i.e. menuItem11, menuItem12, etc.) to the program.
String menuItems[] = {"ITEM 1", "ITEM 2", "finger tip", "Med Wide", "Large Wide", "L GRIP", "T GRIP", "L DIAMETER", "S DIAMETER", "PINCH"};
String submenuItems[] = {"Sub Menu 1", "Sub Menu 2", "Sub Menu 3", "Sub Menu 4", "Sub Menu 5", "Sub Menu 6", "Sub Menu 7", "Sub Menu 8", "Sub Menu 9", "Sub Menu 10"};

// Navigation button variables
int readKey;

// Menu control variables
int menuPage = 0;
int maxMenuPages = 8 ; // amount f menu items -2
int cursorPosition = 0;

// Creates 3 custom characters for the menu display
byte downArrow[8] = {
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b10101, // * * *
  0b01110, //  ***
  0b00100  //   *
};

byte upArrow[8] = {
  0b00100, //   *
  0b01110, //  ***
  0b10101, // * * *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100  //   *
};

byte menuCursor[8] = {
  B01000, //  *
  B00100, //   *
  B00010, //    *
  B00001, //     *
  B00010, //    *
  B00100, //   *
  B01000, //  *
  B00000  //
};

#include <Wire.h>
#include <LiquidCrystal.h>

// Setting the LCD shields pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  int activepage=0;
    int activeButton;
    int button=0;
  int buttonlimit;
 int lcdbutton=1000;







// ****************SETUP *****************
void setup() {
  Serial.begin(9600); 
  Serial.println();
  Serial.println("Starting...");
  menusetup(); 
  servosetup(); 
  Serial.println("READY");
  delay(100);
}
// ****************End SETUP ***********************




// ****************  Main Loop *****************

void loop() {
  menu();   // function that controls changing arm state   
  servo();
  delay(100);
}

// **************** End Main Loop *****************
