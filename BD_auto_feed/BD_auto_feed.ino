

#include "calibration_macro.h"
#include "mouse_util.h" 
 
 
 void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
  delay(4000);
}

void loop() {
  // put your main code here, to run repeatedly:

 move_to_restore();
 delay(1000);
 Mouse.press(MOUSE_RIGHT);
 delay(100);
 Mouse.release();
 delay(1000);
 
 move_to_confirm();
 delay(1000);
 Mouse.press(MOUSE_RIGHT);
 delay(100);
 Mouse.release();
 delay(1000);
 
 move_to_work();
 delay(1000);
 Mouse.press(MOUSE_RIGHT); 
 delay(100);
 Mouse.release();
 delay(5000); 
 
 Keyboard.write('0');
 delay(1000); 
 
 for (int i=1; i < 5; i++){
   delay(10000);
   delay(10000);
   delay(10000);
   delay(10000);
   delay(10000);
   delay(10000);
 }
}
