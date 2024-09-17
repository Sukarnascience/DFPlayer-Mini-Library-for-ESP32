# DFPlayer Mini Library for ESP32

## Table of Contents
1. [Introduction](#introduction)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Installation](#installation)
5. [Example Usage](#example-usage)
6. [Connections](#connections)
7. [Troubleshooting](#troubleshooting)
8. [Images](#images)
9. [License](#license)
10. [Acknowledgments](#acknowledgments)
11. [Contributing](#contributing)
12. [Version History](#version-history)

## Introduction
The DFPlayer Mini is a compact and affordable MP3 player module that can be used with Arduino and ESP32 boards. This library provides a streamlined and easy-to-use interface specifically for the ESP32 platform, allowing for efficient MP3 playback and control.

## Hardware Requirements
- ESP32 board (e.g., ESP32 DevKitC, ESP32 WROVER, etc.)
- DFPlayer Mini module
- MicroSD card with MP3 files
- Speaker or headphones
- Jumper wires

## Software Requirements
- Arduino IDE (version 1.8.x or later)
- ESP32 board support package (version 1.0.4 or later)
- [DFRobotDFPlayerMini Library](https://github.com/DFRobot/DFRobotDFPlayerMini) (for reference and usage)

## Installation
### Install DFPlayer Mini Library
1. **Download the Library**: Clone or download the DFPlayer Mini library from [DFRobot's GitHub repository](https://github.com/DFRobot/DFRobotDFPlayerMini).
2. **Extract the Library**: Unzip the downloaded file if necessary.
3. **Add to Arduino IDE**:
   - Open the Arduino IDE.
   - Navigate to `Sketch > Include Library > Add .ZIP Library`.
   - Select the extracted `.zip` file and click `Open`.

### Add ESP32 Support
1. **Open Arduino IDE**.
2. **Navigate to** `File > Preferences`.
3. **Add the URL** `https://dl.espressif.com/dl/package_esp32_index.json` to the "Additional Boards Manager URLs" field.
4. **Go to** `Tools > Board > Boards Manager`.
5. **Search for** `esp32` and click `Install`.

## Example Usage
The following example code demonstrates how to use the DFPlayer Mini library to play MP3 files on an ESP32 board. Ensure that your MP3 files are named and organized correctly on your TF card as specified below.

```cpp
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

// Define the serial port for communication with the DFPlayer Mini
#define FPSerial Serial2

// Create an instance of the DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;

// Function to print detailed messages from the DFPlayer Mini
void printDetail(uint8_t type, int value) {
  // Handle messages based on type
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
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30); // Set volume value. From 0 to 30
}

void loop() {
  // Example usage: Play sound file 1 for 5 seconds
  playSound(1, 5);

  // Add more code here to play other sound files or implement other functionality
}
```

**Important: MP3 File Organization**

1. **Create a Folder**: On your TF card (microSD card), create a folder named `mp3` in the root directory.
2. **Organize MP3 Files**: Place your MP3 files inside this `mp3` folder. Name the files in the format `0001.mp3`, `0002.mp3`, `0003.mp3`, and so on.

**Example Directory Structure:**

```
/mp3
  /0001.mp3
  /0002.mp3
  /0003.mp3
```

Ensure that you follow this naming and directory structure, as the DFPlayer Mini expects to find MP3 files in this specific format.

## Connections
Connect the DFPlayer Mini module to the ESP32 as follows:
- **VCC**: Connect to 5V on the ESP32 board
- **GND**: Connect to GND on the ESP32 board
- **RX**: Connect to TX on the ESP32 board (Serial2)
- **TX**: Connect to RX on the ESP32 board (Serial2)
- **SPK1**: Connect to speaker or headphones
- **SPK2**: Connect to speaker or headphones (optional)

## Troubleshooting
- **Ensure Proper Connections**: Verify that the DFPlayer Mini is correctly connected to the ESP32.
- **Check SD Card**: Ensure the microSD card is inserted and contains MP3 files in the correct directory and format.
- **Verify Audio Output**: Confirm that the speaker or headphones are properly connected.
- **Reset Module**: If the DFPlayer Mini is unresponsive, try resetting it by pressing the reset button.

## Images
### Circuit Diagram
Here is the circuit diagram for connecting the DFPlayer Mini to the ESP32:

![Circuit Diagram](https://github.com/Sukarnascience/DFPlayer-Mini-Library-for-ESP32/blob/main/ESP32%20COnnections%20with%20amplifier.jpg)

**Credits**: The circuit diagram was created by Techiesms. For further details, refer to their [YouTube video](https://www.youtube.com/watch?v=cHGcoPfpP_w&t=135s).

## License
This library is released under the MIT License.

## Acknowledgments
This library is based on the [DFRobotDFPlayerMini Library](https://github.com/DFRobot/DFRobotDFPlayerMini) by DFRobot. Thanks to DFRobot for the original code and contributions.

## Contributing
Contributions to this library are welcome. Please submit pull requests to this repository.

## Version History
- **1.0.0**: Initial release
