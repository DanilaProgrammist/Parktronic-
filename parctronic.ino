#include <LiquidCrystal.h>
#include <NewPing.h> 

const int trig_pin = 10;
const int echo_pin = 11;
const int correct_distance = 500;
const int buzz = 1;
int max_distance = 100;


NewPing sonar(trig_pin, echo_pin, correct_distance);
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  lcd.print("MaxDistance:");
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  find_distance();
}

void find_distance(){
  delay(500);
  double value = int((sonar.ping_cm()));
  if (value < max_distance){
    tone(buzz, 500);
  }
  else if (value > max_distance){
    noTone(buzz);
  }
  show_distance(value);
  return value;
}
double show_distance(double distance){
  lcd.setCursor(9,0);
  lcd.print(distance);
  
  lcd.setCursor(12,1);
  lcd.print(max_distance);
  
}

double change_val(double value){
}
