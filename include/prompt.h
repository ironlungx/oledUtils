#pragma once

#include <Arduino.h>
#include <U8g2lib.h>

#define ACTION_LEFT 0
#define ACTION_RIGHT 1
#define ACTION_UP 2
#define ACTION_DOWN 3
#define ACTION_SEL 4

#define LCDWidth u8g2->getDisplayWidth()
#define ALIGN_CENTER(t) ((LCDWidth - (u8g2->getUTF8Width(t))) / 2)
#define ALIGN_RIGHT(t) (LCDWidth - u8g2->getUTF8Width(t))
#define ALIGN_LEFT 0

namespace prompt {
  bool confirm(U8G2 *u8g2, std::function<int(void)> doInput,
               const char *message = "Confirm?", bool state = false);
}
