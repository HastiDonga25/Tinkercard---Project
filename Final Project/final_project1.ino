//Hasti Donga
//12 AUGUST 2023
//Final Project

#include <LiquidCrystal.h>
//Initialise the Serial LCD.

int red=8; //The red LED is connected pin 8 of the Arduino.
int green=9; //The green LED is connected pin 9 of the Arduino.
int yellow=10; //The yellow LED is connected pin 10 of the Arduino.
int button1pin = 6; //The SW1 button is connect to pin 6 of the Arduino.
LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpackboard.
int sensorInput;
float temp;
bool start = false;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT); // Set the red pin as an output.
  pinMode(green, OUTPUT); // Set the green pin as an output.
  pinMode(yellow, OUTPUT); // Set the yellow pin as an output.
  pinMode(button1pin, INPUT); // Set the button pin as an input.
  lcd.begin (16,2);  //Initialize the LCD.
}

void loop(){ 
  
  if(digitalRead(button1pin)==HIGH){
   Serial.println("button pressed");
    start=true;
    delay(300);
  }
  if(start){
  Measure_Temp(); // Call the Measure_Temp function.
  Display_Temp(); // Call the Display_Temp function.
  Display_Color(); // Call the Display_Color function.
  }
}

void  Measure_Temp(){
  sensorInput = analogRead(A0);
  temp = (float)sensorInput/1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;
}

void Display_Temp()
{
  lcd.setCursor(0,0);
  Serial.print("Temp. in Celcius: ");
  Serial.print(temp);
  Serial.println();
  lcd.print("Temp. in Celcius: ");
  lcd.setCursor(5,1);
  lcd.print(temp);
  delay(500);
}

void Display_Color()
{
  if(temp < 0)
  {
    digitalWrite(red,HIGH);
  }
  else
  {
    digitalWrite(red,LOW);
  }
  if(temp>0 && temp<100)
  {
    digitalWrite(green,HIGH);
  }
   else
  {
    digitalWrite(green,LOW);
  }
  if(temp>100)
  {
    digitalWrite(yellow,HIGH);
  }
   else
  {
    digitalWrite(yellow,LOW);
  }
    
}