#include "Keyboard.h"
#include "Mouse.h"

#include "calibration_macro.h"
#include "mouse_util.h"

//port that are used
#define BUTTON_LEFT 1
#define BUTTON_RIGHT 3

#define EN_FEED_ONLY 4
#define EN_RETRIEVE 5
#define EN_SQUIZER 6
#define EN_SPAMMER 7

enum Task_type{
  HEAT,
  HEAT_M,
  WOODCUT,
  CRUSH,
  BLEND
  } task;


  bool flips = true;
  int storage_item_index1;
  int storage_item_index2;

  void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
  delay(4000);
  pinMode(EN_RETRIEVE,INPUT_PULLUP);
  pinMode(EN_SQUIZER,INPUT_PULLUP);
  pinMode(EN_SPAMMER,INPUT_PULLUP);
  pinMode(EN_FEED_ONLY,INPUT_PULLUP);

  //Set task configuration here
  set_task_index(HEAT, 4, 51);
}


void loop() {

  if (digitalRead(EN_FEED_ONLY)==LOW){
      do_feed_worker(1);
  }

  if (digitalRead(EN_SPAMMER)==LOW){
      do_spammer();
  }

  if (digitalRead(EN_SQUIZER)==LOW){
      do_squizer();
  }

  else if (digitalRead(EN_RETRIEVE)==LOW){
      do_retrieve();
  }
}


void set_task_index(Task_type task_assigned,int index1,int index2){
  storage_item_index1 = index1 ;
  storage_item_index2 = index2 ;
  task = task_assigned;
}


void do_retrieve(){
    //retrieve
    cancel_step_left_right();

    if (task == BLEND){
      real_blend (storage_item_index1,storage_item_index2);
    }
    else if(task == HEAT_M){
      real_heat_multiple (storage_item_index1,storage_item_index2);
    }
    else{
      real_retrieve(storage_item_index1);
    }
      do_feed_worker(6);
  }


  void cancel_step_left_right(){
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
}


void do_spammer(){
  Keyboard.write('r');
  delay(50);
}


void do_feed_worker(int feed_times){
    for(int i = 0; i < feed_times; i++){
      real_feed();
      //delay 5mins
      for(int i=0; i < 300; i++){
        delay(1000);
    }
}
}


void do_squizer(){
    pinMode(1, OUTPUT);
    delay(10);
    digitalWrite(1, LOW);
    delay(280);
    pinMode(1, INPUT);
    delay(260);
    pinMode(3, OUTPUT);
    delay(10);
    digitalWrite(3, LOW);
    delay(240);
    pinMode(3, INPUT);
    delay(250);
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

void open_storage_craft_menu(){
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
}

void real_retrieve(int item_index){
  open_storage_craft_menu();

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


void real_heat_multiple(int item_index1,int item_index2){
  
  open_storage_craft_menu();

  move_to_heat();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);

  move_to_selectitem(item_index1);
  mouse_real_click(BUTTON_RIGHT);
  delay(1000);

  move_to_selectitem(item_index2);
  mouse_real_click(BUTTON_RIGHT);
  delay(1000);

  move_to_craft_confirm();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);

}



void real_blend(int item_index1,int item_index2){
  open_storage_craft_menu();
  
  move_to_blend();
  mouse_real_click(BUTTON_LEFT);
  delay(1000);

  move_to_selectitem(item_index1);
  mouse_real_click(BUTTON_RIGHT);
  delay(1000);

  move_to_selectitem(item_index2);
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
