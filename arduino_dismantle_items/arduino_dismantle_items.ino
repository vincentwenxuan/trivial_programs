//#define DESKTOP_PC
#define ALIEN

#include "calibration_macro.h"
#include "mouse_util.h"

void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
}

void loop() {
  // set the position to left-top corner(which is the [0,0])
  delay(3000);
  
  for(int i = 0; i<48; i++){
    
      move_to_item(i);
      Mouse.click(MOUSE_RIGHT);
      delay(30);
      Mouse.click(MOUSE_RIGHT);
      delay(ACTION_DELAY);
      
      move_to_disman();
      Mouse.click(MOUSE_LEFT);
      delay(30);
      Mouse.click(MOUSE_LEFT);      
      delay(DISMANTLE_DELAY);
      
      move_to_ok();
      Mouse.click(MOUSE_LEFT);
      delay(ACTION_DELAY);
  
  
  }
  
 
  // let it die
  while(1){
    delay(500);
  }
  
}






