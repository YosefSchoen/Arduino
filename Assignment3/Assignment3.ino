String user;
String expr;
char exprArray[3];
int x;
int y;
int z = 0;
char op;


//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

void loop()
{
  Serial.println("what is your name");
  lcd.setCursor(0,0);
  lcd.print("what is your name");
  
  while(Serial.available() == 0) {}
  user = Serial.readString();
  
  Serial.println("Hello " + user);
  lcd.setCursor(0,1);
  lcd.print("Hello " + user);
  
  Serial.println("type a math problem to be solved");
  lcd.setCursor(0,2);
  lcd.print("type a math problem");
  lcd.setCursor(0,3);
  lcd.print("to be solved");
  
  while(Serial.available() == 0) {}
  expr = Serial.readString();
  expr = removeWhitespace(expr);
  Serial.println(expr);

  getXOpY(expr, x, op, y);
  Serial.println(op);
  if(op == '+') {z = x + y;}
  else if (op == '-') {z = x - y;}
  else if (op == '*') {z = x * y;}
  else if (op == '/' && y != 0) {z = x / y;}
  else { Serial.println("ERROR"); }
  
  Serial.print("the answer is ");
  Serial.print(z);
  Serial.println("");
  lcd.setCursor(0,3);
  lcd.print("the answer is " + z);
 
 
}



void getXOpY(String expr, int &x, char &op, int &y) {
for (int i = 0; i < expr.length(); i++) {
    if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
      x = expr.substring(0, i).toInt();
      op = expr[i];
      y = expr.substring(i+1, expr.length()).toInt();
    }
  }
}


String removeWhitespace(String str) {
  String newStr = "";
  for(int i = 0; i < str.length(); i++) {
    if(str[i] != ' ') {
      newStr = newStr + str[i];
    }
}
  return newStr;
}
  
  
  
