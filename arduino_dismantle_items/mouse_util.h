#ifndef MOUSE_UTIL_H
#define MOUSE_UTIL_H

#include "calibration_macro.h"
#include <Arduino.h>

void move_to_pos(int des_x, int des_y);
void reset_pos();
void move_to_disman();
void move_to_ok();
void move_to_item(int item_count);


#endif

