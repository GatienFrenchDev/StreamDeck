#include <Keyboard.h>

#define btn6 2

void setup() {
  pinMode(btn6, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  if(digitalRead(btn6)==0){
    Keyboard.press('z');
    Keyboard.release('z');
  }
  delay(100);
}
