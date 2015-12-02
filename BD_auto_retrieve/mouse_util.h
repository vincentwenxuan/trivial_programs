#ifndef MOUSE_UTIL_H
#define MOUSE_UTIL_H

#include "calibration_macro.h"
#include <Arduino.h>

void move_to_pos(double des_x, double des_y);
void reset_pos();
void move_to_restore();
void move_to_confirm();
void move_to_work();
void move_to_store();
void move_to_craft();
void move_to_heat();
void move_to_craft_confirm();
void move_to_storeitem(int index);
void move_to_bagitem();
void move_to_selectitem(int index);

#endif

