 // .ino (arduino) file

//--- include necessary header files ---
#include "blink.h"  // blink the led
#include "Point.h" // class for point
#include "Debug.h" // Prints  to Serial Monitor
#include "Maze.h"  // maze 
#include "Buttons.h" // buttons
#include "Drawing.h" // graphics

#include "U8glib.h"// LCD library

//---- Main ----
void setup(void) {
  Serial.begin(9600); // Only used for debugging
  ResetMaze();        // initialize position & facing direction
  SetupDrawing();     // Get screen size, horiz vs vert ratio
  SetupButtons();     // Setup pushbutton I/O pin modes to input with internal pullup resistor
}

void loop(void) {
  CheckEscape();  // Have user reached any of the maze edges?
  CheckButtons(); // Handle user pushbuttons
  Animate();      // Compute animation variables

  // This u8g loop updates the screen (calling DrawMaze multiple times if necessary)
  u8g.firstPage();
  do {
    DrawMaze();   // Draw the maze (incorporating the animation parameters)
  } while ( u8g.nextPage() );
}
