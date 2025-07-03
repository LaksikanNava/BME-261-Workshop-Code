const int photoresist_Pin = A2;
const int red_Pin = 9;
const int blue_Pin = 6;
const int green_Pin = 3;

void setup() {
  pinMode(red_Pin, OUTPUT);
  pinMode(green_Pin, OUTPUT);
  pinMode(blue_Pin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int light_Level = analogRead(photoresist_Pin);
  Serial.println(light_Level); 

  if (light_Level > 900) {
    // Bright: Green
    analogWrite(green_Pin, 50);  
    analogWrite(red_Pin, 0);
    analogWrite(blue_Pin, 0);
  } else if (light_Level < 300) {
    // Dark: Red
    analogWrite(red_Pin, 255);
    analogWrite(green_Pin, 0);
    analogWrite(blue_Pin, 0);
  } else {
    // Ambient: Blue
    analogWrite(blue_Pin, 180);  
    analogWrite(red_Pin, 0);
    analogWrite(green_Pin, 0);
  }

  delay(100);
}