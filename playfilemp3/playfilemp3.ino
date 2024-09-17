#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

// Define the serial port for communication with the DFPlayer Mini
#define FPSerial Serial2

// Create an instance of the DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;

// Function to print detailed messages from the DFPlayer Mini
void printDetail(uint8_t type, int value) {
  // ... (same implementation as before)
}

// Function to play a specific sound file with a given duration
void playSound(int soundNumber, int duration) {
  myDFPlayer.play(soundNumber);
  delay(duration * 1000); // Convert duration from seconds to milliseconds
}

void setup() {
  FPSerial.begin(9600);
  Serial.begin(115200);

  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(FPSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30); // Set volume value. From 0 to 30
}

void loop() {
  // Example usage: Play sound file 1 for 5 seconds
  playSound(2, 5);

  // Add more code here to play other sound files or implement other functionality
}
