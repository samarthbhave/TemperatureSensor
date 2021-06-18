#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);


const int RELAY1=9; //Lock Relay or motor
const int RELAY2=8; //Lock Relay or motor
//int motorPin1 = 9;
//int motorPin2 = 8; 
int SetPoint=30;
void setup() {
  // put your setup code here, to run once:
  //pinMode(motorPin1,OUTPUT);
  //pinMode(motorPin2,OUTPUT);
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);  
   // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature Sensor Test");  
  lcd.setCursor(0,1); //Move coursor to second Line
  lcd.print("Temp. Controller");
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,LOW);       //Turn off Relay
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  double Temperature = ((5.0/1024.0) * analogRead(A0)) * 100;  //10mV per degree 0.01V/C. Scalling

  lcd.setCursor(0,0);
  lcd.print("Temperature:");    //Do not display entered keys
  lcd.print(Temperature);
  



//Display Set point on LCD
  lcd.setCursor(0,1);
  lcd.print("Set Point:");
  lcd.print(SetPoint);
  lcd.print("C   ");

//Check Temperature is in limit
if(Temperature > SetPoint)
{
   digitalWrite(RELAY1,LOW);  //Turn off heater
   digitalWrite(RELAY2,LOW);
   
}
else
{
  digitalWrite(RELAY1,HIGH);    //Turn on heater
  digitalWrite(RELAY2,HIGH);
}

  delay(100); //Update at every 100mSeconds

}
