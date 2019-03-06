#include <LiquidCrystal.h>
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(8,9, 4,5,6,7);
int pin = A1;
float temp =0;
float celsius =0;
bool check =false;


void setup() {
  Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.print("Tempature :");
}

void loop () {
   if(check){
    lcd.clear();
    lcd.print("Tempature :");
    check=false;
   }
temp = analogRead(pin); 
Serial.println(temp);
celsius = temp/2; 
if(celsius>=30.0){
  lcd.setCursor(0,1);
  lcd.print("WARNING!High Temperature"); 
  check =true;
}else{
  lcd.setCursor(2,1);
lcd.print((int)celsius);
lcd.print(" Celsius"); 
}
delay(1000); 
  
}
