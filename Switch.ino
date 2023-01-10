#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

#define przekaz1 2  
#define przekaz2 3
#define przekaz3 4
#define radio1 5
#define radio2 6

LiquidCrystal_I2C lcd(0x3F, 20, 4); 

byte antenna1[] = {
  B00000,
  B01000,
  B01010,
  B00100,
  B11011,
  B11000,
  B11100,
  B11110
};

void setup ()
{
  lcd.init();                    
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("ANTENNA SWITCH");
  lcd.setCursor(5,1);
  lcd.print("SQ9WIS");
  
  delay(2000);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.write(1);
  lcd.setCursor(1,0);
  lcd.print("-");
  lcd.setCursor(4,0);
  lcd.print("Radio -");
  lcd.setCursor(4, 1);
  lcd.print("B R A K");  

  Serial.begin(9600);
  
  pinMode(przekaz1, OUTPUT); 
  pinMode(przekaz2, OUTPUT);
  pinMode(przekaz3, OUTPUT);
  pinMode(radio1, OUTPUT);
  pinMode(radio2, OUTPUT);
  
  digitalWrite(przekaz1, HIGH);
  digitalWrite(przekaz2, HIGH);
  digitalWrite(przekaz3, HIGH);
  digitalWrite(radio1, HIGH);
  digitalWrite(radio2, HIGH);

  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  lcd.createChar(1 , antenna1);


}
void loop()

{

  if (digitalRead(10) == LOW){ 
   digitalWrite(przekaz1, LOW);
   digitalWrite(przekaz2, HIGH);
   digitalWrite(przekaz3, HIGH); 
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.write(1);
   lcd.setCursor(1,0);
   lcd.print("1");
   lcd.setCursor(3,1);
   lcd.print("DIPOL 20M");
  }
  
  if (digitalRead(11) == LOW){
   digitalWrite(przekaz1, HIGH);
   digitalWrite(przekaz2, LOW);
   digitalWrite(przekaz3, HIGH);
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.write(1);
   lcd.setCursor(1,0);
   lcd.print("2");
   lcd.setCursor(3,1);
   lcd.print("DIPOL 40M");
  }
  
  if (digitalRead(12) == LOW){
   digitalWrite(przekaz1, HIGH);
   digitalWrite(przekaz2, HIGH);
   digitalWrite(przekaz3, LOW);
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.write(1);
   lcd.setCursor(1,0);
   lcd.print("3");
   lcd.setCursor(3,1);
   lcd.print("DIPOL 80M");
  }
 
  if (digitalRead(8) == LOW){
   digitalWrite(radio1, LOW);
   digitalWrite(radio2, HIGH);
   lcd.backlight();
   lcd.setCursor(4,0);
   lcd.print("Radio 1");

  }
  if (digitalRead(9) == LOW){
   digitalWrite(radio1, HIGH);
   digitalWrite(radio2, LOW);
   lcd.backlight();
   lcd.setCursor(4,0);
   lcd.print("Radio 2");
  }
  
 }
