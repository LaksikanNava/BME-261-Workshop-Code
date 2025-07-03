#include <Servo.h>

Servo myservo1; // Position servo on pin 11
Servo myservo2; // Continuous rotation servo on pin 9
int input = 0; 

void setup() {
  Serial.begin(9600);
  myservo1.attach(11); // Setup for position servo
  myservo2.attach(9);  // Setup for rotation servo
  Serial.println("Enter 'P <angle>' for position servo or 'R <speed>' for rotation servo:");
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
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() > 0) {
      char type = input.charAt(0); // 'P' or 'R'
      int value = input.substring(2).toInt(); // parse number after space

      if (type == 'P' || type == 'p') {
        posServo(value);
      } else if (type == 'R' || type == 'r') {
        rotServo(value);
      } else {
        Serial.println("Invalid input. Use 'P <angle>' or 'R <speed>'");
      }
    }
  }
}
