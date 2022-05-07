int stateswitch1, stateswitch2, stateswitch3;

#include <Keyboard.h>

#define KEY_F13  0xF0 // 0x68 + 0x88
#define KEY_F14 0xF1 // 0x69 + 0x88
#define KEY_F15 0xF2 // 0x6A + 0x88
#define KEY_F16 0xF3 // 0x6B + 0x88
#define KEY_F17 0xF4 // 0x6C + 0x88
#define KEY_F18 0xF5 // 0x6D + 0x88
#define KEY_F19 0xF6
#define KEY_F20 0xF7
#define KEY_F21 0xF8
#define KEY_F22 0xF9
#define KEY_F23 0xFA
#define KEY_F24 0xFB

#define redbtn1 8
#define redbtn2 6
#define redbtn3 4
#define redbtn4 2

#define greenbtn1 10
#define greenbtn2 16
#define greenbtn3 A0
#define greenbtn4 9

#define blackbtn1 15
#define blackbtn2 A1

#define switch1 A3
#define switch2 14
#define switch3 7

void setup() {
  pinMode(redbtn1, INPUT_PULLUP);
  pinMode(redbtn2, INPUT_PULLUP);
  pinMode(redbtn3, INPUT_PULLUP);
  pinMode(redbtn4, INPUT_PULLUP);

  pinMode(greenbtn1, INPUT_PULLUP);
  pinMode(greenbtn2, INPUT_PULLUP);
  pinMode(greenbtn3, INPUT_PULLUP);
  pinMode(greenbtn4, INPUT_PULLUP);

  pinMode(blackbtn1, INPUT_PULLUP);
  pinMode(blackbtn2, INPUT_PULLUP);

  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);

  stateswitch1 = digitalRead(switch1);
  stateswitch2 = digitalRead(switch2);
  stateswitch3 = digitalRead(switch3);

  Serial.begin(9600);
  Keyboard.begin();

}

void loop() {
    
  if (digitalRead(redbtn1) == 0) {
    Keyboard.write(KEY_F24);
    delay(100);
  }
  else if (digitalRead(redbtn2) == 0) {
    Keyboard.write(KEY_F23);
    delay(100);
  }
  else if (digitalRead(redbtn3) == 0) {
    Keyboard.write(KEY_F21);
    delay(100);
  }
  else if (digitalRead(redbtn4) == 0) {
    Keyboard.write(KEY_F20);
    delay(100);
  }
  
  else if (digitalRead(blackbtn1) == 0) {
    Keyboard.write(KEY_F19);
    delay(100);
  }
  else if (digitalRead(blackbtn2) == 0) {
    Keyboard.write(KEY_F18);
    delay(100);
  }
  
  else if (digitalRead(greenbtn1) == 0) {
    Keyboard.write(KEY_F17);
    delay(100);
  }

  
  else if (digitalRead(greenbtn2) == 0) {
    Keyboard.write(KEY_F16);
    delay(100);
  }
  
  else if (digitalRead(greenbtn3) == 0) {
    Keyboard.write(KEY_F15);
    delay(100);
  }
  else if (digitalRead(greenbtn4) == 0) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(0xF7);
    Keyboard.releaseAll();
    delay(100);
  }

  else if(digitalRead(switch1) != stateswitch1){
    stateswitch1 = digitalRead(switch1);
    Keyboard.write(KEY_F14);
  }
  else if(digitalRead(switch2) != stateswitch2){
    stateswitch2 = digitalRead(switch2);
    Keyboard.write(KEY_F13);
  }
  else if(digitalRead(switch3) != stateswitch3){
    stateswitch3 = digitalRead(switch3);
       Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(0xF8);
    Keyboard.releaseAll();
  }
  
  delay(100);
}
