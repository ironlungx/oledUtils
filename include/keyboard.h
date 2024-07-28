#pragma once 

#include <Arduino.h>
#include <U8g2lib.h>

#define ACTION_LEFT 0
#define ACTION_RIGHT 1
#define ACTION_UP 2
#define ACTION_DOWN 3
#define ACTION_SEL 4

namespace keyboard {
  void render_keyboard(int pX, int pY, String text, U8G2 u8g2);
  String keyboard(U8G2 u8g2, std::function<int(void)> doInput);
}
