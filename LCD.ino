// Include the LCD library
#include <LiquidCrystal.h>
// Include the Servo library
#include <Servo.h>
#define SensorPin A0
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
float sensorValue = 0;
float tempValue = 0;

// Declare the Servo pin
int servoPin = 9;
// Create a servo object
Servo Servo1;
void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  Serial.begin(9600);
}
void loop() {
  //To have an average from the both sensors
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    tempValue = tempValue + analogRead(A1);
    delay(1);
  }
  sensorValue = sensorValue / 100.0;
  tempValue = tempValue / 100.0;
  //Displaying the results
  Serial.print("Temperatura este: ");Serial.print(tempValue);Serial.print("\n");
  lcd.setCursor(0, 0);
  lcd.print("Temp is: ");
  lcd.print(tempValue);
  delay(30);
  //Choosing a moisture value I rotate the servo.
  if ( sensorValue > 850.0)
  {
    Serial.print("Planta are nevoie de apa( "); Serial.print(sensorValue); Serial.print(")\n");
    lcd.setCursor(0, 1);
    lcd.print("Plant needs water       ");
    Servo1.write(90);
    delay(2000);
    Servo1.write(0);
  }
  else {
    Serial.print("Planta NU are nevoie de apa( "); Serial.print(sensorValue); Serial.print(")\n");
    lcd.print("Plant doesn't need water");
  }

}
