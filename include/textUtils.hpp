#pragma once

#include <Arduino.h>
#include <U8g2lib.h>

namespace textUtils {
inline void wordWrap(U8G2 *u8g2, const char *msg, int xloc, int yloc /*bottom*/) {
  int dspwidth = u8g2->getDisplayWidth(); // display width in pixels
  int strwidth = 0;                       // string width in pixels
  char glyph[2];
  glyph[1] = 0;
  for (const char *ptr = msg, *lastblank = NULL; *ptr; ++ptr) {
    while (xloc == 0 && (*msg == ' ' || *msg == '\n'))
      if (ptr == msg++)
        ++ptr; // skip blanks and newlines at the left edge
    glyph[0] = *ptr;
    strwidth += u8g2->getStrWidth(glyph); // accumulate the pixel width
    if (*ptr == ' ')
      lastblank = ptr; // remember where the last blank was
    else
      ++strwidth;       // non-blanks will be separated by one additional pixel
    if (*ptr == '\n' || // if we found a newline character,
        xloc + strwidth >
            dspwidth) { // or if we ran past the right edge of the display
      int starting_xloc = xloc;
      // print to just before the last blank, or to just before where we got to
      while (msg < (lastblank ? lastblank : ptr)) {
        glyph[0] = *msg++;
        xloc += u8g2->drawStr(xloc, yloc, glyph);
      }
      strwidth -= xloc - starting_xloc; // account for what we printed
      yloc += u8g2->getMaxCharHeight(); // advance to the next line
      xloc = 0;
      lastblank = NULL;
    }
  }
  while (*msg) { // print any characters left over
    glyph[0] = *msg++;
    xloc += u8g2->drawStr(xloc, yloc, glyph);
  }
}
} // namespace textUtils
