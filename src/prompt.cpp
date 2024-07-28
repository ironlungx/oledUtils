#include "prompt.h"
#include "textUtils.hpp"


bool prompt::confirm(U8G2 *u8g2, std::function<int(void)> doInput,
                     const char *message, bool state) {
  while (true) {
    u8g2->clearBuffer();

    u8g2->setFont(u8g2_font_7x13_tr);
    textUtils::wordWrap(u8g2, message, 2, 12);

    if (state) {
      u8g2->drawButtonUTF8(42, 50,
                           U8G2_BTN_INV | U8G2_BTN_SHADOW1 | U8G2_BTN_HCENTER |
                               U8G2_BTN_BW1,
                           0, 2, 2, "Yes");

      u8g2->drawButtonUTF8(84, 50,
                           U8G2_BTN_SHADOW1 | U8G2_BTN_HCENTER | U8G2_BTN_BW1,
                           0, 2, 2, "No");
    } else {
      u8g2->drawButtonUTF8(42, 50,
                           U8G2_BTN_SHADOW1 | U8G2_BTN_HCENTER | U8G2_BTN_BW1,
                           0, 2, 2, "Yes");

      u8g2->drawButtonUTF8(84, 50,
                           U8G2_BTN_INV | U8G2_BTN_SHADOW1 | U8G2_BTN_HCENTER |
                               U8G2_BTN_BW1,
                           0, 2, 2, "No");
    }
    u8g2->sendBuffer();
    int action = doInput();

    if (action != ACTION_SEL) {
      state = !state;
    } else {
       return state;
    }
    delay(100);
  }
}
