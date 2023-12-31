/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.

 ***************************************************************************************/









// ****************   SETUP *****************
//Call in main setup void
void menusetup() {
  // Initializes and clears the LCD screen
  lcd.begin(16, 2);
  lcd.clear();

  // Creates the byte for the 3 custom characters
  lcd.createChar(0, menuCursor);
  lcd.createChar(1, upArrow);
  lcd.createChar(2, downArrow);
}
// ****************  SETUP END *****************







// ****************  Main Loop *****************

void menu() {

   input();     // function that obtains input value from keypad

   switch (activepage) { // The case that is selected here is dependent on which menu page you are on and where the cursor is.
          case 0:
            mainMenuDraw();
            drawCursor();
            operateMainMenu();
            break;
          case 1:
            menuItem1();
            break;
          case 2:
            menuItem2();
            break;
          case 3:
            menuItem3();
            break;
          case 4:
            menuItem4();
            break;
          case 5:
            menuItem5();
            break;
          case 6:
            menuItem6();
            break;
          case 7:
            menuItem7();
            break;
          case 8:
            menuItem8();
            break;
          case 9:
            menuItem9();
            break;
          case 10:
            menuItem10();
            break;
    }
    
    delay(10);
}
// ****************  Main Loop *****************







// ****************  Functions *****************



void input(){
    

readKey = analogRead(0); // UPDATE CURRENT STATE OF BUTTON 1  
  if(readKey <= 800 && buttonlimit == LOW){                  // PRESS INITIATED
     lcdbutton = readKey;                                    // Store the value of the input detected
     buttonlimit = HIGH;                                     // logic bit that identify that the button has been recorded and to limit repeated commands
    }
    
 if (readKey >= 800 && buttonlimit == HIGH ){
     buttonlimit = LOW;                                      // reset limit bit
      if (lcdbutton < 50) {                                  // determain desired command pressed
        button = 1; // right
      } else if (lcdbutton < 200) {
        button = 2; // up
      } else if (lcdbutton < 400) {
        button = 3; // down
      } else if (lcdbutton < 600) {
        button = 4; // left
      }else if (lcdbutton < 800) {
        button = 5; // select
      }
       activeButton = 1;                          // button value has been updated and will be used to execude command
       delay(10);
      } 
}







// ****************  VOIDS *****************


// This function will generate the 2 menu items that can fit on the screen. They will change as you scroll through your menu. Up and down arrows will indicate your current menu position.
void mainMenuDraw() {
  //Serial.print(menuPage);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(menuItems[menuPage]);
  lcd.setCursor(1, 1);
  lcd.print(menuItems[menuPage + 1]);
  if (menuPage == 0) {
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
  } else if (menuPage > 0 and menuPage < maxMenuPages) {
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
  } else if (menuPage == maxMenuPages) {
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
  }
}



// When called, this function will erase the current cursor and redraw it based on the cursorPosition and menuPage variables.
void drawCursor() {
  for (int x = 0; x < 2; x++) {     // Erases current cursor
    lcd.setCursor(0, x);
    lcd.print(" ");
  }

  // The menu is set up to be progressive (menuPage 0 = Item 1 & Item 2, menuPage 1 = Item 2 & Item 3, menuPage 2 = Item 3 & Item 4), so
  // in order to determine where the cursor should be you need to see if you are at an odd or even menu page and an odd or even cursor position.
  if (menuPage % 2 == 0) {
    if (cursorPosition % 2 == 0) {  // If the menu page is even and the cursor position is even that means the cursor should be on line 1
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
    }
    if (cursorPosition % 2 != 0) {  // If the menu page is even and the cursor position is odd that means the cursor should be on line 2
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
    }
  }
  if (menuPage % 2 != 0) {
    if (cursorPosition % 2 == 0) {  // If the menu page is odd and the cursor position is even that means the cursor should be on line 2
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
    }
    if (cursorPosition % 2 != 0) {  // If the menu page is odd and the cursor position is odd that means the cursor should be on line 1
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
    }
  }
}




void operateMainMenu() {
    
    if (activeButton == 1){
        activeButton = 0;

switch (button) {
     
      case 0: // When button returns as 0 there is no action taken
        activeButton = 0;
        button = 0;
        break;
      
      case 5:  // This case will execute if the "select" button is pressed
        activeButton = 0;
        button = 0;

        switch (cursorPosition) { // The case that is selected here is dependent on which menu page you are on and where the cursor is.
          case 0:
            activepage=1;
            Serial.println("submenu 1");

            break;
          case 1:
            activepage=2;
            Serial.println("submenu 2");
            break;
          case 2:
            activepage=3;
            Serial.println("submenu 3");
            break;
          case 3:
            activepage=4;
            Serial.println("submenu 4");
            break;
          case 4:
            activepage=5;
            Serial.println("submenu 5");
            break;
          case 5:
            activepage=6;
            Serial.println("submenu 6");
            break;
          case 6:
            activepage=7;
            Serial.println("submenu 7");
            break;
          case 7:
            activepage=8;
            Serial.println("submenu 8");
            break;
          case 8:
            activepage=9;
            Serial.println("submenu 9");
            break;
          case 9:
            activepage=10;
            Serial.println("submenu 10");
            break;
        }

        break;
        
      case 2:    // This case will execute if the "up" button is pressed
        activeButton = 0;
        button = 0;
        if (menuPage == 0) {
          cursorPosition = cursorPosition - 1;
          cursorPosition = constrain(cursorPosition, 0, ((sizeof(menuItems) / sizeof(String)) - 1));
        }
        if (menuPage % 2 == 0 and cursorPosition % 2 == 0) {
          menuPage = menuPage - 1;
          menuPage = constrain(menuPage, 0, maxMenuPages);
        }

        if (menuPage % 2 != 0 and cursorPosition % 2 != 0) {
          menuPage = menuPage - 1;
          menuPage = constrain(menuPage, 0, maxMenuPages);
        }

        cursorPosition = cursorPosition - 1;
        cursorPosition = constrain(cursorPosition, 0, ((sizeof(menuItems) / sizeof(String)) - 1));

        mainMenuDraw();
        drawCursor();
        break;

        
      case 3: // This case will execute if the "down" button is pressed
        activeButton = 0;
        button = 0;
        if (menuPage % 2 == 0 and cursorPosition % 2 != 0) {
          menuPage = menuPage + 1;
          menuPage = constrain(menuPage, 0, maxMenuPages);
        }

        if (menuPage % 2 != 0 and cursorPosition % 2 == 0) {
          menuPage = menuPage + 1;
          menuPage = constrain(menuPage, 0, maxMenuPages);
        }

        cursorPosition = cursorPosition + 1;
        cursorPosition = constrain(cursorPosition, 0, ((sizeof(menuItems) / sizeof(String)) - 1));
        mainMenuDraw();
        drawCursor();
        break;
    }
  }

}











// ****************  VOIDS *****************




void menuItem1() { // Function executes when you select the 1st item from main menu

     lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Sub Menu 1");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
         grip1();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
  }






void menuItem2() { // Function executes when you select the 2nd item from main menu
  lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Sub Menu 2");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip2();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
  }

     


void menuItem3() { // Function executes when you select the 3rd item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Finger tip");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip3();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}

void menuItem4() { // Function executes when you select the 4th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Med Wide");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip4();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}

void menuItem5() { // Function executes when you select the 5th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Large Wide");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip5();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}

void menuItem6() { // Function executes when you select the 6th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("loose grip");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip6();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}

void menuItem7() { // Function executes when you select the 7th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Tight Grip");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip7();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}

void menuItem8() { // Function executes when you select the 8th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Large Diameter");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip8();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}



void menuItem9() { // Function executes when you select the 9th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Small diameter");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip9();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
}






void menuItem10() { // Function executes when you select the 10th item from main menu
lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("FLAT PINCH");

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        grip10();
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
         opengrip();
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
  }
