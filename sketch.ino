/* Basic example code for MAX7219 LED dot matrix display with Arduino. More info: https://www.makerguides.com */

// Include the required Arduino libraries:
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection:
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Setup for software SPI:
// #define DATAPIN 2
// #define CLK_PIN 4
// MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);



int i = 0;
textEffect_t texteffect[] =
{
  PA_PRINT,
  PA_SCAN_HORIZ,
  PA_SCROLL_LEFT,
  PA_WIPE,
  PA_SCROLL_UP_LEFT,
  PA_SCROLL_UP,
  PA_OPENING_CURSOR,
  PA_GROW_UP,
  PA_MESH,
  PA_SCROLL_UP_RIGHT,
  PA_BLINDS,
  PA_CLOSING,
  PA_RANDOM,
  PA_GROW_DOWN,
  PA_SCAN_VERT,
  PA_SCROLL_DOWN_LEFT,
  PA_WIPE_CURSOR,
  PA_DISSOLVE,
  PA_OPENING,
  PA_CLOSING_CURSOR,
  PA_SCROLL_DOWN_RIGHT,
  PA_SCROLL_RIGHT,
  PA_SLICE,
  PA_SCROLL_DOWN
};
char *texteffect_s[] =
{
  "PRINT",
  "SCAN_HORIZ",
  "SCROLL_LEFT",
  "WIPE",
  "SCROLL_UP_LEFT",
  "SCROLL_UP",
  "OPENING_CURSOR",
  "GROW_UP",
  "MESH",
  "SCROLL_UP_RIGHT",
  "BLINDS",
  "CLOSING",
  "RANDOM",
  "GROW_DOWN",
  "SCAN_VERT",
  "SCROLL_DOWN_LEFT",
  "WIPE_CURSOR",
  "DISSOLVE",
  "OPENING",
  "CLOSING_CURSOR",
  "SCROLL_DOWN_RIGHT",
  "SCROLL_RIGHT",
  "SLICE",
  "SCROLL_DOWN"
};

void setup() {
  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setPause(1000);
  myDisplay.setSpeed(100);
  // Clear the display:
  myDisplay.displayClear();
  //myDisplay.displayScroll("PAPA MAMA LERA", PA_LEFT, PA_SCROLL_LEFT, 100);
  //myDisplay.displayText("Papa Mama LERA", PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
//   myDisplay.setTextAlignment(PA_CENTER);
//   myDisplay.setInvert(false);
//   myDisplay.displayScroll("PAPA MAMA LERA", PA_LEFT, PA_SCROLL_LEFT, 100);
//   delay(6000);
  if (myDisplay.displayAnimate()) {
    if (i < sizeof(texteffect)) {
      i++;
    }
    else {
      i = 0;
    }
    myDisplay.displayText(texteffect_s[i], myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
    myDisplay.displayReset();
  }

  //myDisplay.setTextAlignment(PA_LEFT);
//   myDisplay.print("PAPA");
//   delay(6000);
  //myDisplay.setTextAlignment(PA_RIGHT);
//  myDisplay.print("MAMA");
//  delay(6000);
  //myDisplay.setTextAlignment(PA_CENTER);
  //myDisplay.setInvert(true);
  //myDisplay.print("Invert");
  //delay(2000);
  //myDisplay.setInvert(false);
  //myDisplay.print(1234);
  //delay(2000);
}