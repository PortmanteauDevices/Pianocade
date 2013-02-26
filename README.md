# Pianocade

## Controls

### Keyboard
Most of the buttons on the Pianocade are set up in the layout of a standard piano keyboard. Normally, these buttons sound notes. When held on power-up, the keyboard will be transposed to the key of the held note.

### Joystick
#### Joystick Left
Shift keyboard one octave down. With left coin button, decrease the arp speed two-fold.
#### Joystick Right
Shift keyboard one octave up. With left coin button, increase the arp speed two-fold.
#### Joystick Up
Pitch bend current note up. With left coin button, increase the arp speed by a small amount.
#### Joystick Down
Pitch bend current note down. With left coin button, decrease the arp speed by a small amount.

### Player select buttons
These buttons select sound bank. They can be combined into as chords, for a total of 15 sound banks.
#### Player 1 + Left Coin Button
Cycle through the different arpeggiator orders

*NOTE: on some units this will be Player 4 + Left Coin Button. This will be fixed in the first firmware update, coming soon.*

### Coin buttons
#### Left Coin Button
Acts as "shift" key to access secondary functions
#### Right Coin Button
Hold the currently sounding notes. With left coin button, clear currently held notes

## Arpeggiator
The Pianocade is monophonic: only one note sounds at a time. When multiple notes are sounded simultaneously, the Pianocade arpeggiates them (switches between them quickly). Both the rate and the order of arpeggiation can be set on a per-patch basis.

The available arpeggiation orders are: ascending, descending, random, ping-pong, order pressed
These can be changed for the current patch by pressing the LEFT COIN button and the PLAYER 1 button simultaneously

The arpeggiation speed can be adjusted by holding the LEFT COIN button and moving the joystick left and right (to halve or double the speed) or up and down (to fine adjust the speed faster or slower)

Upon receiving a MIDI clock start signal, the Pianocade's internal arpeggiator will be turned off, and the Pianocade will instead listen for a MIDI clock signal. Receiving a MIDI clock stop signal will re-engage the internal arpeggiator clock.

## Sound bank settings
### Default settings
"x" is button pressed, with the Player 1 button being the leftmost position

* x000 - 50% square wave
* 0x00 - 25% square wave
* 00x0 - 12.5% square wave
* 000x - Simple volume envelope on 50% square wave
* xx00 - "Violin"; slow attack, slow decay
* x0x0 - "Piano"; fast attack, slow fade during sustain, fast decay
* x00x - Tremolo (slow)
* 0xx0 - Tremolo (fast)
* 0x0x - Echo on release
* 00xx - Super Mario Bros. Coin (Actual effect is B5)
* xxx0 - Super Mario Bros. Coin on release (Actual effect is B5)
* xx0x - SMB jump (Actual effect is A4 for small Mario and D4 for Super Mario)
* x0xx - Zelda get item (Actual effect is F5)
* 0xxx - Zelda magic rod (Actual effect is C#4)
* xxxx - SMB stomp (Actual effect is A4)
