#include "mouse_util.h"

void move_to_pos(int des_x, int des_y){
// util function that move a mouse to a certain position
  //reset position to 0,0
  reset_pos();
  
  // decide the max loop number
  int x_100 = des_x / 100; 
  int y_100 = des_y / 100; 
  int num_total = 0;
  if (x_100 >= y_100) {
    num_total = x_100+1;
  }
  else{
    num_total= y_100+1;
  }
  
  // loop to get to the des position
  int rest_x = des_x;
  int rest_y = des_y;
  int move_this_x = 0;
  int move_this_y = 0;
  
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

void move_to_disman(){  
  move_to_pos(DISMAN_BUTTON_X,DISMAN_BUTTON_Y);
}

void move_to_ok(){  
  move_to_pos(OK_BUTTON_X,OK_BUTTON_Y);
}


void move_to_item(int item_count){
  // item_x, item_y indicate the position of item (0~6, 0~8)
  int item_x = item_count % 6;
  int item_y = item_count / 6;
  int item_pos_x = LEFT_TOP_ITEM_X + item_x * ITEM_INCREMENT;
  int item_pos_y = LEFT_TOP_ITEM_Y + item_y * ITEM_INCREMENT;
  
  move_to_pos(item_pos_x,item_pos_y);
  
}

