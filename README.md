# rotary-media

A basic rotary encoder volume control.

This project uses a rotary encoder and an Arduino to create a basic cross-platform hardware volume control.

## Hardware setup

The hardware setup is as easy as connecting the clock, direction, and button pins of the rotary encoder to pins 2-4 respectively on the Arduino as well as the VCC and GND pins (3.3v or 5v both work for my encoder).

## Running the program

Once the Arduino and encoder are wired up, configure the serial port in `index.ts` and run the code with `npm start`. The program should connect to the Arduino and start manipulating the volume and mute options of the local computer.
