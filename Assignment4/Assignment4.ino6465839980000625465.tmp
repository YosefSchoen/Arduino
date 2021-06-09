#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int patternNum = 0;
int lightNum = 0;
int scalar = 1;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Please Select");
  lcd.setCursor(0, 1);
  lcd.print("Pattern 1, 2, or 3");
  while(Serial.available() == 0) {}
  patternNum = Serial.read();
  patternNum = patternNum - 48;
  lcd.clear();
}

void loop() {
  
  switch(patternNum) {
  case 1:
    ExerciseOne();
    break;
    
  case 2:
    ExerciseTwo();
    break;
    
  case 3:
    ExerciseThree();
    break;
    
  }
  delay(500);
  lcd.clear();
}


void ExerciseOne() {
  printLight(lightNum);
  lightNum++;
  if(lightNum > 6) {lightNum = 0;}
}


void ExerciseTwo() {
  printLight(lightNum);
  lightNum += scalar;
  
  if(lightNum == 6) {scalar = -1;}
  if(lightNum == 0) {scalar = 1;}

}

void ExerciseThree() {
  printLight(lightNum);
  printLight(6 - lightNum);
  lightNum++;
  if(lightNum > 3) {lightNum = 0;}
}


void printLight(int i) {
  lcd.setCursor(2*i, 0);
  lcd.print("^");
  lcd.setCursor(2*i, 1);
  lcd.print("*");
  lcd.setCursor(2*i, 2);
  lcd.print("|");
  lcd.setCursor(2*i, 4);
  lcd.print("|");
  lcd.setCursor((2*i)+1, 4);
  lcd.print(i + 1);

  return;
}
