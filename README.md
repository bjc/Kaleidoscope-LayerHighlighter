# Kaleidoscope-LayerHighlighter

Highlight keys defined in a layer while it's locked with an LED
effect.

## Using the extension
```c++
#include <Kaleidoscope-LayerHighlighter.h>

enum { PRIMARY, FUNCTION, NUMPAD, MYLAYER }; // layers

/*
 * Layer definitions, etc.,.
 */

LayerHighlighter myLayerHighlighter(MYLAYER);

KALEIDOSCOPE_INIT_PLUGINS(myLayerHighlighter);

void setup() {
  Kaleidoscope.setup();

  myLayerHighlighter.color = CRGB(160, 160, 0); // yellow
  myLayerHighlighter.lockHue = 100; // green(ish)
}
```

## Plugin methods

Instances of this plugin provide the following instance variables:

### construction

Instantiate this plugin with the layer value to which it applies.

### `.color`
A CRGB value that specifies the color of the LEDs for keys defined
within the layer.

### `.lockHue`
A color hue, normalized from 0-255, specifying the breathing LED color
of any keys defined to lock the layer.

## CREDITS
This was basically just a minor modification of the
[Kaleidoscope-NumPad][NumPad] library, by Jesse Vincent.

[NumPad]: https://github.com/keyboardio/Kaleidoscope-NumPad
