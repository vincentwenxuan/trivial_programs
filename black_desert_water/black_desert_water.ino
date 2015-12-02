#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  // set the position to left-top corner(which is the [0,0])
  delay(3000);
  
  while(1){
      Keyboard.write('0');
      delay(300);
      Keyboard.write('0');
      delay(300);   
      Keyboard.write('0');
      delay(300);  
      Keyboard.write('0');
      delay(300);  
     
      delay(22000);
      Keyboard.write('r');
      delay(300);
      Keyboard.write('r');
      delay(300);   
      Keyboard.write('r');
      delay(300);  
      Keyboard.write('r');
      delay(300);  
  }
  

}






