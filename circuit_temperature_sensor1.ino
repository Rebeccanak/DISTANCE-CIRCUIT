#include <Servo.h>
Servo myservo; // create servo object
int tempPin = A0; // analog pin for temperature sensor
int servoPin = 3; // digital pin for servo motor
int temperature;
void setup() {
  myservo.attach(servoPin); // attach servo to pin
  Serial.begin(9600); // initialize serial communication
}
void loop() {
  temperature = analogRead(tempPin); // read temperature sensor value
  temperature = (5.0 * temperature * 100.0) / 1024.0; // convert sensor value to Celsius
  if (temperature > 30) { // if temperature is greater than 30 degrees Celsius
    myservo.write(90); // move servo to 90 degrees
    delay(1000); // wait for servo to move.
  }
  delay(1000); // it waits for 1 second before taking next temperature reading
}