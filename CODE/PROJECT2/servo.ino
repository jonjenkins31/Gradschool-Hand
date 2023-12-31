
/***************************************************************************************
 * 
    Notes   : This code controls the animation of the servo. 
              Servo 1-4 connected to PWM Pins

 ***************************************************************************************/


// ****************   SETUP *****************
//Call in main setup void
void servosetup() {
  myservo1.attach(servo1);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(servo2);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(servo3);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(servo4);  // attaches the servo on pin 9 to the servo object
  opengrip();


}
// ****************  SETUP END *****************



// ****************  Main Void *****************

void servo() {
   servonewState = servotask;      // Get current button state.

if (servooldState != servonewState) {    // Check if state changed from high to low (button press).

    switch (servotask) {                    // The case that is selected here is dependent on which menu page you are on and where the cursor is.
          case 0:
            opengrip();
            break;
          case 1:
            grip1();
            break;
          case 2:
            grip2();
            break;
          case 3:
            grip3();
            break;
         
        }
        // Set the last-read button state to the old state.
  servooldState = servonewState;
     }

}




  // ****************  Sub Void *****************

  void opengrip(){
     
      
     myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);                       // waits 15 ms for the servo to reach the position
      
      myservo1.write(50);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(70);              // Servo 2 ( Base Close)
      delay(500);                       // waits 15 ms for the servo to reach the position

      myservo3.write(100);              // Servo 3 ( Fingertip Open)
      myservo4.write(100);              // Servo 4 ( Base Open)


  }

  void grip1(){               // water bottle
     myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);                       // waits 15 ms for the servo to reach the position

    
      myservo1.write(25);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(60);              // Servo 2 ( Base Close)
     
     delay(500);                       // waits 15 ms for the servo to reach the position

      myservo3.write(50);              // Servo 3 ( Fingertip Open)
      myservo4.write(80);              // Servo 4 ( Base Open)
   }

  void grip2(){
     
      myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
      
      
      
      myservo1.write(60);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(60);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(60);              // Servo 3 ( Fingertip Open)
      myservo4.write(60);              // Servo 4 ( Base Open)
  }

  void grip3(){
     myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
      
      myservo1.write(10);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(30);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(90);              // Servo 4 ( Base Open)
  }


  void grip4(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
       myservo1.write(20);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(45);              // Servo 2 ( Base Close)
      delay(500);                       // waits 15 ms for the servo to reach the position

      myservo3.write(75);              // Servo 3 ( Fingertip Open)
      myservo4.write(95);              // Servo 4 ( Base Open)

  }


  void grip5(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
       myservo1.write(20);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(55);              // Servo 2 ( Base Close)
      delay(500);                       // waits 15 ms for the servo to reach the position

      myservo3.write(85);              // Servo 3 ( Fingertip Open)
      myservo4.write(95);              // Servo 4 ( Base Open)
  }



  void grip6(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
      myservo1.write(15);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(45);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(90);              // Servo 4 ( Base Open)
  }



  void grip7(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
 myservo1.write(2);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(30);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(90);              // Servo 4 ( Base Open)
  }






  void grip8(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
       myservo1.write(20);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(40);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
  }





  void grip9(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
myservo1.write(25);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(15);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(90);              // Servo 3 ( Fingertip Open)
      myservo4.write(80);              // Servo 4 ( Base Open)
  }










  void grip10(){
       myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(80);              // Servo 2 ( Base Close)
      
      myservo3.write(70);              // Servo 3 ( Fingertip Open)
      myservo4.write(70);              // Servo 4 ( Base Open)
      
     delay(500);  
     
myservo1.write(30);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
      myservo2.write(15);              // Servo 2 ( Base Close)
      delay(500);  
      myservo3.write(90);              // Servo 3 ( Fingertip Open)
      myservo4.write(80);              // Servo 4 ( Base Open)
  }
