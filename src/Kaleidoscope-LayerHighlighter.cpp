#include "Kaleidoscope-LayerHighlighter.h"
#include "LEDUtils.h"
#include "layers.h"
#include "Kaleidoscope-LEDControl.h"

#include <Kaleidoscope.h>

byte LayerHighlighter::row = 255, LayerHighlighter::col = 255;

kaleidoscope::EventHandlerResult LayerHighlighter::onSetup(void) {
  return kaleidoscope::EventHandlerResult::OK;
}

kaleidoscope::EventHandlerResult LayerHighlighter::afterEachCycle() {
  if (!Layer.isOn(layer))
    return kaleidoscope::EventHandlerResult::OK;

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(layer, r, c);

      if (k == LockLayer(layer)) {
        row = r;
        col = c;
      }

      if ((k != layer_key) || (k == Key_NoKey)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return kaleidoscope::EventHandlerResult::OK;

  cRGB lock_color = breath_compute(lockHue);
  LEDControl.setCrgbAt(row, col, lock_color);

  return kaleidoscope::EventHandlerResult::OK;
}