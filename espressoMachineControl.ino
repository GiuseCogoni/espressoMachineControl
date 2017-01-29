#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // digital pins to which LCD is connected

int button = 7;    // the pin that the Up pushbutton is attached to
int pumpPin = 2;
float oneEspressoTime = 4000;
float twoEspressoTime = 10000;
float pressLength_milliSeconds = 0;
float pressLength_confirm = 0;

byte cup_p1[8] = {
  B00001,
  B00010,
  B00000,
  B01111,
  B01000,
  B01000,
  B01000,
  B00111
};

byte cup_p2[8] = {
  B01000,
  B10000,
  B00000,
  B11110,
  B01010,
  B01010,
  B01100,
  B10000
};

int optionOne = 100;
int optionTwo = 500; 


//int buttonPushCounter = 0;   // counter for the number of button presses
//int buttonStateUp = 0;         // current state of the button
//int buttonStateDown = 0;         // current state of the button
//int lastButtonState = 0;     // previous state of the button

void setup() {
  pinMode(button, INPUT);
  pinMode(pumpPin, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("Espresso"); 
  lcd.setCursor(2,1);
  lcd.print("machine v1.0"); 
  lcd.createChar(0, cup_p1);
  lcd.createChar(1, cup_p2);
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(0));
  lcd.setCursor(15,0);
  lcd.write(byte(1));
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press button: 1");
  lcd.setCursor(14,0);
  lcd.write(byte(0));
  lcd.setCursor(15,0);
  lcd.write(byte(1));
  lcd.setCursor(0,1);
  lcd.print("Hold button:");
  lcd.setCursor(12,1);
  lcd.write(byte(0));
  lcd.setCursor(13,1);
  lcd.write(byte(1));
  lcd.setCursor(14,1);
  lcd.write(byte(0));
  lcd.setCursor(15,1);
  lcd.write(byte(1));  
}

void loop() {
  while (digitalRead(button) == HIGH ){ 
    delay(100);
    pressLength_milliSeconds = pressLength_milliSeconds + 100;   
  }
  if (pressLength_milliSeconds >= optionTwo){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You've selected:");
      lcd.setCursor(0,1);
      lcd.write(byte(0));
      lcd.setCursor(1,1);
      lcd.write(byte(1)); 
      lcd.setCursor(2,1);
      lcd.write(byte(0));
      lcd.setCursor(3,1);
      lcd.write(byte(1)); 
      lcd.setCursor(5,1);
      lcd.print("cups");
      delay(1500);
      while (digitalRead(button) == HIGH){goto reset;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Press reset to");
      lcd.setCursor(0,1);
      lcd.print("cancel selection");
      delay(3000);
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.print("Confirmed!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Brewing...");
      for (int i = 0; i<16; i++){
        digitalWrite(pumpPin, HIGH);
        lcd.setCursor(i,1);
        lcd.print(char(255));
        delay(twoEspressoTime/15);
      }
      digitalWrite(pumpPin, LOW);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Enjoy your");
      lcd.setCursor(3,1);
      lcd.print("espressos!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Press button: 1");
      lcd.setCursor(14,0);
      lcd.write(byte(0));
      lcd.setCursor(15,0);
      lcd.write(byte(1));
      lcd.setCursor(0,1);
      lcd.print("Hold button:");
      lcd.setCursor(12,1);
      lcd.write(byte(0));
      lcd.setCursor(13,1);
      lcd.write(byte(1));
      lcd.setCursor(14,1);
      lcd.write(byte(0));
      lcd.setCursor(15,1);
      lcd.write(byte(1)); 
      delay(2000); 
      goto reset;
  } 
  else if(pressLength_milliSeconds >= optionOne){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You've selected:");
      lcd.setCursor(0,1);
      lcd.write(byte(0));
      lcd.setCursor(1,1);
      lcd.write(byte(1));
      lcd.setCursor(3,1);
      lcd.print("cup"); 
      delay(1500);
      while (digitalRead(button) == HIGH){goto reset;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Press reset to");
      lcd.setCursor(0,1);
      lcd.print("cancel selection");
      delay(3000);
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.print("Confirmed!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Brewing...");
      for (int i = 0; i<16; i++){
        digitalWrite(pumpPin, HIGH);
        lcd.setCursor(i,1);
        lcd.print(char(255));
        delay(oneEspressoTime/15);
      }
      digitalWrite(pumpPin, LOW);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Enjoy your");
      lcd.setCursor(3,1);
      lcd.print("espresso!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Press button: 1");
      lcd.setCursor(14,0);
      lcd.write(byte(0));
      lcd.setCursor(15,0);
      lcd.write(byte(1));
      lcd.setCursor(0,1);
      lcd.print("Hold button:");
      lcd.setCursor(12,1);
      lcd.write(byte(0));
      lcd.setCursor(13,1);
      lcd.write(byte(1));
      lcd.setCursor(14,1);
      lcd.write(byte(0));
      lcd.setCursor(15,1);
      lcd.write(byte(1)); 
      delay(2000); 
      goto reset;  
  }
  reset:
  pressLength_milliSeconds = 0;
}
