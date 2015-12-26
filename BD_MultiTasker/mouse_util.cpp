#include "mouse_util.h"
#include "Keyboard.h"
#include "Mouse.h"
void move_to_pos(double des_x, double des_y){
// util function that move a mouse to a certain position
  //reset position to 0,0
  reset_pos();

  // decide the max loop number
  int x_100 = des_x / 100;
  int y_100 = des_y / 100;
  double num_total = 0;
  if (x_100 >= y_100) {
    num_total = x_100+1;
  }
  else{
    num_total= y_100+1;
  }

  // loop to get to the des position
  double rest_x = des_x;
  double rest_y = des_y;
  double move_this_x = 0;
  double move_this_y = 0;

  for (int i =0; i<num_total;i++){

    if (rest_x > 100) {
        move_this_x = 100;
        rest_x -= 100;
    }
    else if(rest_x >= 0 && rest_x <= 100 ){
        move_this_x = rest_x;
        rest_x = 0;
    }
    else{
        move_this_x = 0;
    }

    if (rest_y > 100) {
        move_this_y = 100;
        rest_y -= 100;
    }
    else if(rest_y >= 0 && rest_y <= 100 ){
        move_this_y = rest_y;
        rest_y = 0;
    }
    else{
        move_this_y = 0;
    }

    Mouse.move(move_this_x, move_this_y, 0);
    delay(ACTION_DELAY);
  }



}


void reset_pos(){
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
  Mouse.move(-100, -100, 0);
  delay(ACTION_DELAY);
}

void move_to_restore(){
  move_to_pos(RESTORE_BUTTON_X,RESTORE_BUTTON_Y);
}

void move_to_confirm(){
  move_to_pos(CONFIRM_BUTTON_X,CONFIRM_BUTTON_Y);
}

void move_to_work(){
  move_to_pos(WORK_BUTTON_X,WORK_BUTTON_Y);
}

void move_to_store(){
  move_to_pos(STORE_BUTTON_X,STORE_BUTTON_Y);
}

void move_to_craft(){
  move_to_pos(CRAFT_BUTTON_X,CRAFT_BUTTON_Y);
}

void move_to_heat(){
  move_to_pos(HEAT_BUTTON_X,HEAT_BUTTON_Y);
}

void move_to_woodcut(){
  move_to_pos(WOODCUT_BUTTON_X,WOODCUT_BUTTON_Y);
}

void move_to_crush(){
  move_to_pos(CRUSH_BUTTON_X,CRUSH_BUTTON_Y);
}

void move_to_blend(){
  move_to_pos(BLEND_BUTTON_X,BLEND_BUTTON_Y);
}

void move_to_craft_confirm(){
  move_to_pos(CRAFT_CONFIRM_BUTTON_X,CRAFT_CONFIRM_BUTTON_Y);
}

void move_to_bagitem(){
  move_to_pos(BAG_ITEM_X,BAG_ITEM_Y);
}

void move_to_storeitem(int index){

  int x_index = index % 8;
  int y_index = index / 8;

  double increment_x = 15.1;
  double increment_y = 14.7;

  double start_x = 285.0;
  double start_y = 97.0;

  double des_x = start_x + increment_x * (double)x_index;
  double des_y = start_y + increment_y * (double)y_index;

  if (x_index==2) des_x+=5;
  if (x_index==3) des_x+=4;
  if (x_index==4) des_x+=3;

  move_to_pos(des_x,des_y);

}


void move_to_selectitem(int index){

  int x_index = index % 8;
  int y_index = index / 8;

  double increment_x = 15.1;
  double increment_y = 14.4;

  double start_x = 425.0;
  double start_y = 110.0;

  double des_x = start_x + increment_x * (double)x_index;
  double des_y = start_y + increment_y * (double)y_index;

  if (x_index==4) des_x-=4;
  if (x_index==5) des_x-=4;

  move_to_pos(des_x,des_y);

}


