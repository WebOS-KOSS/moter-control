#include <ESP32_Servo.h>
Servo servo;

int value = 0;

const int X = 36;
const int Y = 39;
const int moter = 26;

void setup() {
  Serial.begin(115200);
  servo.attach(moter);
  //pinMode(SW_P,INPUT_PULLUP);
}
 
void loop() {
/*
  Serial.print("Axis_X: ");
  Serial.println(analogRead(X));

  Serial.print("Axis_Y: ");
  Serial.println(analogRead(Y));
*/

  
  if (analogRead(X) > 4000 && value < 180){
    Serial.println("창문 열기");
    value += 1;
  }
  else if (analogRead(X) < 100 && value > 0){
    Serial.println("창문 닫기");
    value -= 1;
  }
  
  
  if (analogRead(Y) > 4000){
    Serial.println("블라인드 닫기");
  }
  else if (analogRead(Y) < 100){
    Serial.println("블라인드 열기");
  }
  servo.write(value);
  delay(10);
}
