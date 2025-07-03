const int buttonPin = 12; 
const int ledPin = 10;    
int buttonState = 0;

int buttonMode = 0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(200);  // Sampling time

  int buttonState1 = digitalRead(buttonPin);
  if(buttonState1 == HIGH && buttonState1 == LOW){
    buttonState = HIGH;
  }
  int buttonState = buttonState1;
  
  if (buttonState == HIGH && buttonMode < 4) {
    buttonMode = buttonMode + 1;
  } 
  
  if (buttonState == HIGH && buttonMode == 4) {
    buttonMode = 0;
  }

  if (buttonMode == 0) {
    analogWrite(ledPin, 0);         // OFF
  } else if (buttonMode == 1) {
    analogWrite(ledPin, 0.2*255);        // 20%
  } else if (buttonMode == 2) {
    analogWrite(ledPin, 0.4*255);       // 40%
  } else if (buttonMode == 3) {
    analogWrite(ledPin, 255);       // 100%
  }
  Serial.println(buttonMode);
}