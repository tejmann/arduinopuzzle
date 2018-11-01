//--- include necessary header files ---
#include "U8glib.h"// U8g library
#include "maze.h"    // the maze
#include "blink.h"  // control the led
#include "Buttons.h" // buttons

void setup(void) {
  Serial.begin(9600);
  SetupButtons();
  InitiateLED();
}

void loop(void) {
  //CheckEscape();
  CheckButtons();
  Animate();

  //update graphics
  
}
