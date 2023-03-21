#define trigPin 7 // define trig pin
#define echoPin 6 // define echo pin
long duration, cm, inches; // variables for distance measurement
void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(trigPin, OUTPUT); // set trig pin as output
  pinMode(echoPin, INPUT); // set echo pin as input
  
}
void loop() {
  digitalWrite(trigPin, LOW); // reset trig pin
  delayMicroseconds(2); // wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // send 10 microsecond pulse to trigger sensor
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure time for echo to return
  cm = (duration/2) / 29.1; // calculate distance in cm
  inches = (duration/2) / 74; // calculate distance in inches
  Serial.print(cm);
  Serial.print("cm\t");
  Serial.print(inches);
  Serial.println("inches");
  delay(500); // wait for 500 milliseconds before taking next measurement
  if(inches<3){
  delay(1000);
  }
}  