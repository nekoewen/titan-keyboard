# The Titan

The Titan is a keyboard for playing video games, particularly but not exclusively fighting games. The design mixes in bits of the Sega Saturn controller (hence I named it after one of Saturn’s moons) and Hitbox controllers.

## Bill of Materials
- Pro Micro (or a compatible microcontroller, such as an Elite-C, BIT-C, KB2040, etc.) with headers
- 17 through-hole diodes
- 17 key switches (MX or Choc)
- 17 keycaps; 15 should be 1u, and two should be 1.5u
- M2 standoffs
- M2 screws
- Adhesive rubber feet
- 2-pin tactile reset switch (optional)
- EC11 encoder switch with knob (optional)
- WS2182B LED strip (optional)

## Build Guide
1. Begin with the diodes. Bend the leads, insert them through the holes (the cathode is marked with a black line and should go on the square pad). Solder each diode, then use clippers to remove the excess leads.
2. Take your Pro Micro and flash the firmware (see below). I recommend doing this before soldering it just in case you got a bad board.
3. Solder the Pro Micro and its header pins to the underside of the board, with the Pro Micro’s components facing you. If you’re adding a reset switch, put it into the PCB and solder its pins.
4. From here you should be able to test the keyboard’s functionality. If you plug it in, it should register as a Titan keyboard, and you can use tweezers or a similar metal object to make contact on the switch pads to create the equivalent of keystrokes. If any of the keys don’t work, check to make sure you have the diodes soldered and facing the right direction, and also that the Pro Micro’s pins are all soldered in.
5. If you’re going to use an EC11 encoder, solder it in place now.
6. Put the top plate in place, and start pushing switches in place, though the plate and into the PCB so that each switch’s two leads go through the corresponding holes in the PCB. I like to put switches in the corners, solder them in place, and then fill in the rest of the switches. Once you’ve soldered all of the switches, I recommend testing the keyboard again to be sure that you have in fact soldered all of them. Once that’s done you can go ahead and put on the keycaps.
7. If you’re including an LED strip for pretty lights, use 3 wires to solder the pads on the PCB to the corresponding ones on the strip. Be sure the Dx lead is going to Dx on the board, as they won’t work if you get it backwards. If you plug it into your computer now, it should light up!
8. Use the standoffs and screws to attach the top plate to the bottom plate.
9. Finally, put some adhesive rubber feet on the bottom. You’re done!

## Firmware
You can find a .hex file of the default Titan firmware in this repository. If you don’t have any need to customize the layout, you can just download this and flash it to your Pro Micro.
7. Install QMK Toolbox if you haven’t already.
8. Open titan_default.hex.
9. Click the “Auto-Flash” checkbox.
10. Plug the Pro Micro into your computer.
11. Bridge the GND and RST pins with a metal object (or if it’s already soldered in place, press the reset switch).
12. QMK Toolbox should automatically flash the firmware for you!

If you do want to customize the firmware:
6. Copy the “titan” folder from the firmware folder here into the “keyboards” folder of your QMK installation. You can modify the files in this folder as desired.
7. Open a terminal window (for your OS if you’re using macOS or Linux, or QMK MSYS if you’re using windows).
8. Navigate to the QMK folder (typically cd qmk_firmware).
9. Type “make titan:default” (or replace “default” with the name of your new keymap) and it should compile.
10. Type “make titan:default:flash (or replace flash with “dfu”) to flash it.
