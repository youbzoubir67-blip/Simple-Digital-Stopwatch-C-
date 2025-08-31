# Simple Digital Stopwatch (Arduino)

A minimal stopwatch using `millis()` for timing and Serial output for display.
Buttons provide **Start/Stop** and **Reset**. Easy to extend to a 7-seg module.

## Hardware
- Arduino Uno/Nano
- Push Button 1 (Start/Stop) → D2
- Push Button 2 (Reset) → D3 (both to GND with INPUT_PULLUP)

## Build
- Open `src/stopwatch.ino` and upload
- Open Serial Monitor @ 115200 baud

## License
MIT
