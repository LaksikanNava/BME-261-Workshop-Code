#include <Servo.h>

Servo myservo1; // Position servo on pin 11
Servo myservo2; // Continuous rotation servo on pin 9
int input = 0; 

void setup() {
  Serial.begin(9600);
  myservo1.attach(11); // Setup for position servo
  myservo2.attach(9);  // Setup for rotation servo
  Serial.println("Enter angle for position servo or speed for rotation servo:");
}

void posServo(int angle) {
  // Clamp angle between 0 and 180
  angle = constrain(angle, 0, 180);
  myservo1.write(angle);
  Serial.print("Position servo moved to: ");
  Serial.println(angle);
}

void rotServo(int speedPercent){
    // Clamp speed percentage between -100 and 100
  speedPercent = constrain(speedPercent, -100, 100);

  // Map speedPercent to servo pulse range (0-180)
  // 0% -> 93 (stop), +100% -> 180, -100% -> 0
  int servoSignal = map(speedPercent, -100, 100, 0, 180);
  myservo2.write(servoSignal);


  Serial.print("Rotation servo speed set to: ");
  Serial.print(speedPercent);
  Serial.print("% (mapped to signal: ");
  Serial.print(servoSignal);
  Serial.println(")");
  
}

void loop() {
  if (Serial.available()>0) {
   String inputString = Serial.readStringUntil('\n'); // Read input as string
   input = inputString.toInt(); 
   //posServo(input); 
   rotServo(input); 
  }
  
}
