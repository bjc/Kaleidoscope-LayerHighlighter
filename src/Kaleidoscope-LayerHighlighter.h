#pragma once

#include <Kaleidoscope.h>

class LayerHighlighter : public kaleidoscope::Plugin {
 public:
  LayerHighlighter(uint8_t l): color(CRGB(160, 0, 0)), lockHue(170), layer(l) {}

  cRGB color;
  uint8_t lockHue;

  kaleidoscope::EventHandlerResult onSetup(void);
  kaleidoscope::EventHandlerResult afterEachCycle();

 private:
  const uint8_t layer;
  static byte row, col;
};
