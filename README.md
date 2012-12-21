Welcome to Pianocade!

# Controls

## Keyboard
Most of the buttons on the Pianocade are set up in the layout of a standard piano keyboard. Normally, these buttons sound notes. When held on power-up, the keyboard will be transposed to the key of the held note.

## Joystick
### Joystick Left
Shift keyboard one octave down. With left coin button, decrease the arp speed two-fold.
### Joystick Right
Shift keyboard one octave up. With left coin button, increase the arp speed two-fold.
### Joystick Up
Pitch bend current note up. With left coin button, increase the arp speed by a small amount.
### Joystick Down
Pitch bend current note down. With left coin button, decrease the arp speed by a small amount.

## Player select buttons
These buttons select sound bank. They can be combined into as chords, for a total of 15 sound banks.
### Player 1 + Left Coin Button
Cycle through the different arpeggiator orders

## Coin buttons
### Left Coin Button
acts as "shift" key to access secondary functions
### Right Coin Button
hold the currently sounding notes. With left coin button, clear currently held notes

# Arpeggiator
The Pianocade is monophonic: only one note sounds at a time. When multiple notes are sounded simultaneously, the Pianocade arpeggiates them (switches between them quickly). Both the rate and the order of arpeggiation can be set on a per-patch basis.

The available arpeggiation orders are: ascending, descending, random, ping-pong, order pressed
These can be changed for the current patch by pressing the LEFT COIN button and the PLAYER 1 button simultaneously

The arpeggiation speed can be adjusted by holding the LEFT COIN button and moving the joystick left and right (to halve or double the speed) or up and down (to fine adjust the speed faster or slower)

Upon receiving a MIDI clock start signal, the Pianocade's internal arpeggiator will be turned off, and the Pianocade will instead listen for a MIDI clock signal. Receiving a MIDI clock stop signal will re-engage the internal arpeggiator clock.
