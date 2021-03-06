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

void setup() {
  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}

void loop() {
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setInvert(false);
  myDisplay.print("PAPA MAMA LERA ");
  delay(6000);

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