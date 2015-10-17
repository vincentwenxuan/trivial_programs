#ifndef CALIBRATION_MACRO_H
#define CALIBRATION_MACRO_H

#ifdef ALIEN

const int  DISMAN_BUTTON_X = 69;
const int  DISMAN_BUTTON_Y = 144;

const int OK_BUTTON_X = 250;
const int OK_BUTTON_Y = 160;

const int LEFT_TOP_ITEM_X = 422;
const int LEFT_TOP_ITEM_Y = 41;
const int ITEM_INCREMENT = 12;

const int ACTION_DELAY = 50;
const int DISMANTLE_DELAY = 3000;

#elif DESKTOP_PC

const int  DISMAN_BUTTON_X = 70;
const int  DISMAN_BUTTON_Y = 144;

const int OK_BUTTON_X = 253;
const int OK_BUTTON_Y = 159;

const int LEFT_TOP_ITEM_X = 422;
const int LEFT_TOP_ITEM_Y = 41;
const int ITEM_INCREMENT = 12;

const int ACTION_DELAY = 50;
const int DISMANTLE_DELAY = 3000;

#else 

const int  DISMAN_BUTTON_X = 70;
const int  DISMAN_BUTTON_Y = 144;

const int OK_BUTTON_X = 253;
const int OK_BUTTON_Y = 159;

const int LEFT_TOP_ITEM_X = 422;
const int LEFT_TOP_ITEM_Y = 41;
const int ITEM_INCREMENT = 12;

const int ACTION_DELAY = 50;
const int DISMANTLE_DELAY = 3000;

#endif 

#endif
