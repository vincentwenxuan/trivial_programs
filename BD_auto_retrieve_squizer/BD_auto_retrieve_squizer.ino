
#define BUTTON_LEFT 1
#define BUTTON_RIGHT 3
#include "Keyboard.h"
#include "Mouse.h"

#include "calibration_macro.h"
#include "mouse_util.h" 

enum Task_type{
  HEAT,
  WOODCUT,
  CRUSH
} task;
 
bool flips = true;
int storage_item_index;

void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
  delay(4000);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  //Set this here to indicate 
  storage_item_index = 1;
  task = HEAT;

}

void loop() {
  if (digitalRead(6)==LOW){
    pinMode(1, OUTPUT);
    delay(20);
    digitalWrite(1, LOW); 
    delay(400);
    pinMode(1, INPUT);
    delay(500);
    pinMode(3, OUTPUT);
    delay(20);
    digitalWrite(3, LOW); 
    delay(400);
    pinMode(3, INPUT);
    delay(500);      
  }
  
  else if (digitalRead(5)==LOW){
     //cancel current task
    Keyboard.write(' ');
    delay(4000);
    
    if (flips == true){
        //left and right step 
        Keyboard.write('a');
        delay(1000);
        Keyboard.write('d');
        delay(100);
        flips = false;
     }else{
        //left and right step 
        Keyboard.write('d');
        delay(1000);
        Keyboard.write('a');
        delay(100);
        flips == true;
     }
    
    real_retrieve (storage_item_index);
    //do retrieve once an hour
    int feed_times = 9;
    if (task == WOODCUT){
      feed_times = 6;
    }
    for(int i = 0; i < feed_times; i++){
      real_feed();
      //delay 5mins
      for(int i=0; i < 300; i++){  
        delay(1000);
      }
      
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
  
  if(task == HEAT) move_to_heat();
  if(task == WOODCUT)move_to_woodcut();
  if(task == CRUSH)move_to_crush();
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
