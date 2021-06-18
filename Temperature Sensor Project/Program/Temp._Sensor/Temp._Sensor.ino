# include "LiquidCrystal.h"         
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float temp;                                   // to include LM 35 sensor
const int RELAY1_Hot_fan=9;                   //Lock Relay or motor
const int RELAY2_Cool_fan=8;                  //Lock Relay or motor
//int Hot_Temp = 35;
//int Cool_Temp = 20;
//int Neutral_Temp = 24;

void setup() 
{
  Serial.begin(9600);
  pinMode(RELAY1_Hot_fan,OUTPUT);
  pinMode(RELAY2_Cool_fan,OUTPUT); 
  analogReference(INTERNAL);
  lcd.begin (16,2);                            // the codes written here is to run the programme once
  lcd.setCursor(0, 0);
  lcd.print("   Temperature   ");      
  lcd.setCursor(0, 1);
  lcd.print("   Sensor   ");
  digitalWrite(RELAY1_Hot_fan,LOW);
  delay(2000);
  digitalWrite(RELAY2_Cool_fan,LOW);          //Turn off Relay
  delay(2000);
  lcd.clear();                                //Let system settle
}
void loop() 
{
  temp = analogRead(A0);                     //temp = temp * 0.48828125;  //temp=temp*(5.0/1023.0)*100;
  temp=temp*1100/(1024*10);
  lcd.print(" TEMP: ");
  lcd.print(temp);
  lcd.println("*C");
  delay(100);                              //Let system settle
  lcd.clear(); 
  if (temp >= 30)
  {
      lcd.setCursor(0, 0);
      lcd.print(" TEMP: ");
      lcd.print(temp);
      lcd.println("*C");
      lcd.setCursor(0, 1);
      lcd.print("   Hot           ");
      digitalWrite(RELAY1_Hot_fan,LOW);     //Turn off Heater
      delay(100);
      digitalWrite(RELAY2_Cool_fan,HIGH);   //Turn on Cooler
      delay(100);
  }
  else if (temp <= 20 || temp <= 24)
  {
     lcd.setCursor(0, 0);
     lcd.print(" TEMP: ");
     lcd.print(temp);
     lcd.println("*C");
     lcd.setCursor(0, 1);
     lcd.print("   Cool            ");
     digitalWrite(RELAY1_Hot_fan,HIGH);     //Turn on Heater
     delay(100);
     digitalWrite(RELAY2_Cool_fan,LOW);     //Turn off Cooler
     delay(100);
  }
  else if (temp == 24 || temp <=30)
  {
     lcd.setCursor(0, 0);
     lcd.print(" TEMP: ");
     lcd.print(temp);
     lcd.println("*C");
     lcd.setCursor(0, 1);
     lcd.print("   Neutral      ");
     digitalWrite(RELAY1_Hot_fan,LOW);      //Turn off Heater
     delay(100);
     digitalWrite(RELAY2_Cool_fan,LOW);     //Turn off Cooler
     delay(100);
  }
  delay(100);                               //Update at every 100mSeconds
}
