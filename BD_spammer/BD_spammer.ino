
#define BUTTON_LEFT 1
#define BUTTON_RIGHT 3
#include "Keyboard.h"
#include "Mouse.h"


void setup() {
  // put your setup code here, to run once:


  Mouse.begin();
  Keyboard.begin();
  pinMode(5,INPUT_PULLUP);  
}

void loop() {
  // put your main code here, to run repeatedly:
   if (digitalRead(5)==LOW){
      Keyboard.write('r');
      delay(50);
   }
}
