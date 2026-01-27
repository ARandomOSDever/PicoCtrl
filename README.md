# PS1 controller emulator
This is an emulator for the PS1 digital controller using the RP2040 in USB CDC ACM mode, based on the PicoMemcard POC controller simulator example
You can also use a PicoMemcard board (as the PS1 memory card and controller share the same bus), however if you use a RP2040-Zero you will need to edit CMakeLists.txt. See [Notes](#Notes) for more info. Make sure you desolder the 3.3V line while connecting USB to your PC
## Keybinds
- WASD -- D-Pad
- Q -- L1
- E --  R1
- 1 -- L2
- 3 -- R2
- Enter/Return (0x0A) -- Start
- Backspace (0x08) -- Select
- Arrow keys ("\x1b[y", where y is one of the characters in the parenthesis)
  - Right ("C") -- Circle
  - Down ("B") -- Cross
  - Up ("A") -- Triangle
  - Left ("D") -- Square 
## Notes
- This uses the PicoMemcard pinout for the Pi Pico (DAT = 5, CMD = 6, SEL = 7, CLK = 8 and ACK = 9), if you have a RP2040-Zero you will have to uncomment line 49 of CMakeLists.txt
- This hasn't been tested on real hardware due to me accidentally shorting the 5V line to GND when checking the voltage of a 7805 from a Famiclone (because the DPak 78M05 regulator that I bought for my PSOne didn't arrive yet)  which resulted into PS601 and PS606 to open (and when testing the regulator with 7.5V it outputted 6.5V instead of 5V which means that there's a chance of me frying either the video encoder, the SPU or anything connected to serial)
