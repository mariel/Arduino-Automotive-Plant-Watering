// Include the Servo library
#include <Servo.h>
#define SensorPin A0

float sensorValue = 0;
float tempValue = 0;

// Declare the Servo pin
int servoPin = 3;
// Create a servo object
Servo Servo1;
void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    tempValue = tempValue + analogRead(A1);
    delay(1);
  }
  sensorValue = sensorValue / 100.0;
  tempValue = tempValue / 100.0;
  Serial.print("Temperatura este: ");Serial.print(tempValue);Serial.print("\n");
  delay(30);

  if ( sensorValue > 850.0)
  {
    Serial.print("Planta are nevoie de apa( "); Serial.print(sensorValue); Serial.print(")\n");
    Servo1.write(90);
    delay(2000);
    Servo1.write(0);
  }
  else {
    Serial.print("Planta NU are nevoie de apa( "); Serial.print(sensorValue); Serial.print(")\n");
  }

}
