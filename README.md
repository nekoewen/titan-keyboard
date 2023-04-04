# The Titan
The Titan is a QMK-powered keyboard for playing video games, particularly but not exclusively fighting games. The design mixes in bits of the Sega Saturn controller (hence I named it after one of Saturn’s moons) and Hitbox controllers.

![A photo of a completed Titan, with DSA keycaps](https://github.com/nekoewen/titan-keyboard/blob/main/titan.jpg)
![A diagram of the default Titan layout from KLE](https://github.com/nekoewen/titan-keyboard/blob/02daede569e61ab964b96894a5e86afcfc06a7ef/titan%20default%20layout.png)

## Bill of Materials
- Pro Micro (or a compatible microcontroller, such as an Elite-C, BIT-C, KB2040, etc.) with headers
- 17x 1N4148 through-hole diodes
- 17x key switches (MX or Choc)
- 17x keycaps; 15 should be 1u, and two should be 1.5u
- 9x M2 standoffs
- 18x M2 screws
- 4 or more adhesive rubber feet
- 2-pin reset switch (optional; 3x6x2mm DIP-2P switch, the same kind used on the Corne keyboard)
- EC11 encoder switch with knob (optional)
- WS2182B LED strip and 3 wires (optional)

## Tools
- Soldering iron with solder
- Wire clippers
- Wire stripper (if including an LED strip)
- Screwdriver
- Diode bending tool (optional; I use [this one](https://www.thingiverse.com/thing:4332520))

## Build Guide
1. Begin with the diodes. Bend the leads, insert them through the holes (the cathode is marked with a black line and should go on the square pad, so that the line on the diode matches the one printed on the PCB). Solder each diode, then use clippers to remove the excess leads.
2. Take your Pro Micro and flash the firmware (see below). I recommend doing this before soldering it just in case you got a bad board.
3. Solder the Pro Micro and its header pins to the underside of the board, with the Pro Micro’s components facing the board. You may want to use your clippers to trim off the excess part of the headers. If you’re adding a reset switch, put it into the PCB and solder its pins.
4. If you’re going to use an EC11 encoder, solder it in place now. If you wait until you've soldered the switches, the top plate will being in the way will make it incredibly difficult to get the EC11 in place.
5. From here you should be able to test the keyboard’s functionality. If you plug it in, it should register as a Titan keyboard, and you can use tweezers or a similar metal object to make contact on the switch pads to create the equivalent of keystrokes. If any of the keys don’t work, check to make sure you have the diodes soldered and facing the right direction, and also that the Pro Micro’s pins are all soldered in.
6. Use screws to attach the standoffs to the top plate. It's a bit easier to do this step now.
7. Put the top plate in place, and start pushing switches in place, though the plate and into the PCB so that each switch’s two leads go through the corresponding holes in the PCB. I like to put switches in the corners, solder them in place, and then fill in the rest of the switches. Once you’ve soldered all of the switches, I recommend testing the keyboard again to be sure that you have in fact soldered all of them. Once that’s done you can go ahead and put on the keycaps.
8. If you’re including an LED strip for pretty lights, use 3 wires to solder the pads on the PCB to the corresponding ones on the strip. Be sure the DIn lead is going to LED DAT on the board, as they won’t work if you attach it to DOut on the LED strip. If you plug it into your computer now, it should light up!
9. Flip the keyboard over, put the bottom plate in place (the placement of the screws make it so you need to orient it correctly), and use more screws to secure it in place.
10. Finally, put some adhesive rubber feet on the bottom. You’re done!

## Firmware
You can find a .hex file of the default Titan firmware in this repository. If you don’t have any need to customize the layout, you can just download this and flash it to your Pro Micro.
1. Install [QMK Toolbox](https://github.com/qmk/qmk_toolbox) if you haven’t already.
2. Open titan_default.hex.
3. Click the “Auto-Flash” checkbox.
4. Plug the Pro Micro into your computer.
5. Bridge the GND and RST pins with a metal object (or if it’s already soldered in place, press the reset switch).
6. QMK Toolbox should automatically flash the firmware for you!

If you want to customize the firmware:
1. Copy the “titan” folder from the firmware folder here into the “keyboards” folder of your [QMK installation](https://docs.qmk.fm/#/newbs_getting_started). You can modify the files in this folder as desired.
2. Open a terminal window (for your OS if you’re using macOS or Linux, or [QMK MSYS](https://msys.qmk.fm/) if you’re using Windows).
3. Navigate to the QMK folder (typically `cd qmk_firmware`).
4. Type “`make titan:default`” (or replace “default” with the name of your new keymap) and it should compile.
5. Type “`make titan:default:flash`" (or replace flash with “`dfu`”) to flash it.

If you're using a KB2040 or similar controller, you'll need to use QMK's [Converters](https://github.com/qmk/qmk_firmware/blob/4020674163fc80914059c4c9c3be5c0ae00bd150/docs/feature_converters.md) feature, so for example compiling and flashing for a KB2040 would go as follows:

`qmk flash -c -kb titan -km default -e CONVERT_TO=kb2040`
