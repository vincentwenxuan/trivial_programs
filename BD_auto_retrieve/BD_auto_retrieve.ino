
#define BUTTON_LEFT 1
#define BUTTON_RIGHT 3


#include "calibration_macro.h"
#include "mouse_util.h" 
 
bool flips = true;

void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
  delay(4000);
  
}

void loop() {
  //Set this here to indicate 
  int storage_item_index = 9;
  
   //cancel current task
  Keyboard.write(' ');
  delay(4000);
  
  if (flips == true){
      //left and right step 
      Keyboard.write('a');
      delay(1000);
      Keyboard.write('d');
      delay(1000);
      flips = false;
   }else{
      //left and right step 
      Keyboard.write('d');
      delay(1000);
      Keyboard.write('a');
      delay(1000);
      flips == true;
   }
  
  real_retrieve (storage_item_index);
  //do retrieve once an hour
  for(int i = 0; i < 10; i++){
    real_feed();
    //delay 5mins
    for(int i=0; i < 300; i++){  
      delay(1000);
    }
    
  }
  

}

void real_feed(){
   move_to_restore();
   mouse_real_click(BUTTON_LEFT);
   delay(1000);
   
   move_to_confirm();
   mouse_real_click(BUTTON_LEFT);
   delay(1000);
   
   move_to_work();
   mouse_real_click(BUTTON_LEFT);
   delay(1000);
   
   Keyboard.write('0');
   delay(1000); 


}


void real_retrieve(int item_index){

  
  
  //enter storage
  Keyboard.write('r');
  delay(2000);
  Keyboard.write('r');
  delay(2000);
  Keyboard.write('r');
  delay(2000);
      
  move_to_store();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);
  
  //put bag item into store
  move_to_bagitem();
  mouse_real_click(BUTTON_RIGHT);
  delay(1000);
  
  Keyboard.write('f');
  delay(1000);
  
  Keyboard.write(' ');
  delay(1000);
  
  //begin crafting
  move_to_craft();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);
  
  move_to_heat();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);
  
  move_to_selectitem(item_index);
  mouse_real_click(BUTTON_RIGHT);
  delay(1000);
  
  move_to_craft_confirm();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);
 
}


void mouse_real_click(int button_index){
  delay(400); 
  pinMode(button_index, OUTPUT);
  delay(20);
  digitalWrite(button_index, LOW); 
  delay(150);
  pinMode(button_index, INPUT);
  delay(400);
}
