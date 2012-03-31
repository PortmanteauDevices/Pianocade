#include "pianocade.h"

const uint8_t prescaler[TOTAL_NOTES] PROGMEM = {0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010};
//const uint8_t prescaler[TOTAL_NOTES] PROGMEM = {0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001};

const uint16_t note_freq[TOTAL_NOTES] PROGMEM = {30577, 28861, 27241, 25712, 24269, 22907, 21621, 20407, 19262, 18181, 17160, 16197, 15288, 14430, 13620, 12855, 12134, 11453, 10810, 10203, 9630, 9090, 8580, 8098, 61155, 57723, 54483, 51425, 48539, 45814, 43243, 40816, 38525, 36363, 34322, 32395, 30577, 28861, 27241, 25712, 24269, 22907, 21621, 20407, 19262, 18181, 17160, 16197, 15288, 14430, 13620, 12855, 12134, 11453, 10810, 10203, 9630, 9090, 8580, 8098, 7644, 7214, 6809, 6427, 6066, 5726, 5404, 5101, 4815, 4544, 4289, 4049, 3821, 3607, 3404, 3213, 3033, 2862, 2702, 2550, 2407, 2272, 2144, 2024, 1910, 1803, 1702, 1606, 1516, 1431, 1350, 1275, 1203, 1135, 1072, 1011, 955, 901, 850, 803, 757, 715, 675, 637, 601, 567, 535, 505, 477, 450, 425, 401, 378, 357, 337, 318, 300, 283, 267, 252, 238, 224, 212, 200, 189, 178, 168, 158};

const uint8_t bend_depth[TOTAL_NOTES] PROGMEM = {110, 104, 98, 93, 88, 83, 78, 74, 70, 66, 62, 58, 55, 52, 49, 46, 44, 41, 39, 37, 35, 33, 31, 29, 221, 208, 197, 186, 175, 165, 156, 147, 139, 131, 124, 117, 110, 104, 98, 93, 88, 83, 78, 74, 70, 66, 62, 58, 55, 52, 49, 46, 44, 41, 39, 37, 35, 33, 31, 29, 28, 26, 25, 23, 22, 21, 20, 18, 17, 16, 15, 15, 14, 13, 12, 12, 11, 10, 10, 9, 9, 8, 8, 7, 7, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const uint8_t sine_table[32] PROGMEM = {0, 0, 1, 1, 2, 3, 5, 6, 8, 9, 10, 12, 13, 14, 14, 15, 15, 15, 14, 14, 13, 12, 10, 9, 8, 6, 5, 3, 2, 1, 1, 0};
const uint8_t saw_table[32] PROGMEM = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15};
uint8_t wave_counter = 0;

uint8_t chord[MAXCHORD];
uint8_t chord_length = 0;

uint16_t all_notes[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint16_t held_notes[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t held_flag = 0;
uint8_t held_state = 0;
uint8_t held_changed = 0;
uint8_t last_held_state = 0;
uint8_t debounce_held = 0;
uint8_t debounce_held_count = 0;
uint8_t pinread = 0;

uint8_t lastnote = 0;

uint8_t octave = 5;
uint8_t octave_flag = 0;

uint8_t arp_count = 0;
volatile uint8_t arp_speed = 12;
volatile uint8_t arp_pos = 0;

int8_t bend_step = 0;
//volatile int16_t bend_depth = 0;
uint8_t autobend_counter = 0;
int8_t autobend_step = 0;
void (*autobend)(void) = &autobend_return;

uint8_t last_control = 0;
uint8_t control = 0;
uint8_t debounce_control = 0;
uint8_t debounce_control_count = 0;

uint32_t last_notes_pressed = 0b0;
uint32_t notes_pressed = 0b0;
uint32_t debounce_notes = 0b0;
uint8_t debounce_notes_count = 0;

uint8_t volume = 0b1111;
uint8_t duty_cycle = 1;

int8_t shift = 0;
uint8_t current_envelope = 0;
uint8_t last_envelope = 0;
uint8_t muteflag = 0;


void (*arpeggio[ARPMODES])(void) = {&ascending, &descending, &random_arp};
uint8_t arp_mode;

void (*notegen_a)(void) = &square_a;
void (*notegen_b)(void) = &square_b;

uint8_t table_delay = 0;
uint8_t table_timer = 0;
uint8_t table_pos = 0;

uint8_t start_volume;
uint8_t start_duty_cycle;
uint8_t table[32];
uint8_t jump_on_release;
uint8_t jump_flag;
uint8_t retrigger_flag;

uint8_t pinreadbuffer;

const uint8_t PROGMEM banked_start_volume[15] = {0xF, 0xF, 0x0, 0xF, 0xB, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x3};
const uint8_t PROGMEM banked_arp_mode[15] = {0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
const uint8_t PROGMEM banked_arp_speed[15] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 120, 120, 120, 120, 120};
const uint8_t PROGMEM banked_retrigger_flag[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
const uint8_t PROGMEM banked_start_duty_cycle[15] = {1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const uint8_t PROGMEM banked_table[15][32] = {
  {  // BANK 0, 50% square
    0x70, 0, // 0
    0, 0, // 1
    0, 0, // 2
    0, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK 1, 25% square
    0x70, 0, // 0
    0, 0, // 1
    0, 0, // 2
    0, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK 2, "Violin"
    0x11, 0x03, // 0
    0x70, 0, // 1
    0x21, 0x03, // 2
    0x72, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },  
  {  // BANK 3, 12.5% square
    0x70, 0, // 0
    0, 0, // 1
    0, 0, // 2
    0, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK 4, "Piano"
    0x11, 0, // 0
    0x70, 6, // 1
    0x21, 0x02, // 2
    0x72, 7, // 3
    0x21, 0x0F, // 4
    0x0F, 0x0F, // 5
    0x74, 4, // 6
    0, 0, // 7
    0x77, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0x21, 0, // E
    0x7E, 0, // F
  },
  { // BANK 5, Tremolo (fast)
    0x22, 0, // 0
    0x70, 2, // 1
    0x12, 0, // 2
    0x72, 2, // 3
    0x70, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  { // BANK 6, Mario coin (on release)
    0x70, 0, // 0
    0x5C, 0, // 1
    0x21, 0x02, // 2
    0x72, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK 7, Game Boy envelope
    0x21, 0x01, // 0
    0x70, 0, // 1
    0, 0, // 2
    0, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  { // BANK 8, Tremolo (slow)
    0x21, 0x1, // 0
    0x70, 5, // 1
    0x11, 0x1, // 2
    0x72, 5, // 3
    0x70, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK 9, Echo on release
    0x70, 0, // 0
    0x21, 0x02, // 1
    0x71, 5, // 2
    0x13, 0, // 3
    0x71, 4, // 4
    0x30, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  { // BANK A, Mario jump
    0x57, 0x02, // 0
    0x41, 0x04, // 1
    0x3B, 0x01, // 2
    0xA8, 0, // 3
    0x21, 0, // 4
    0x73, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  { // BANK B, Mario coin
    0x05, 0, // 0
    0x5C, 0, // 1
    0x21, 0x02, // 2
    0x72, 0, // 3
    0, 0, // 4
    0, 0, // 5
    0, 0, // 6
    0, 0, // 7
    0, 0, // 8
    0, 0, // 9
    0, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK C, Zelda get item
    0, 0x01, // 0
    0x21, 0, // 1
    0xA9, 0x11, // 2
    0, 0, // 3
    0x71, 2, // 4
    0x21, 0, // 5
    0xA8, 0x11, // 6
    0, 0, // 7
    0x21, 0, // 8
    0x74, 1, // 9
    0xA9, 0x01, // A
    0x21, 0x01, // B
    0x7B, 10, // C
    0x21, 0, // D
    0x30, 0, // E
    0x30, 0, // F
  },
  {  // BANK D, Zelda magic rod
    0, 0, // 0
    0xA8, 0, // 1
    0x71, 7, // 2
    0x26, 0x5B, // 3
    0xA8, 0, // 4
    0x74, 2, // 5
    0x13, 0x5B, // 6
    0xA8, 0, // 7
    0x77, 2, // 8
    0x73, 1, // 9
    0x30, 0, // A
    0, 0, // B
    0, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  },
  {  // BANK E, SMB stomp
    0, 0, // 0
    0xA8, 0x36, // 1
    0xA8, 0x39, // 2
    0xA9, 0x3C, // 3
    0xA8, 0x3F, // 4
    0x30, 0x01, // 5
    0xAA, 0x33, // 6
    0xA8, 0x37, // 7
    0x00, 0x38, // 8
    0xA9, 0x39, // 9
    0xA8, 0x3C, // A
    0xA8, 0x3F, // B
    0x30, 0, // C
    0, 0, // D
    0, 0, // E
    0x30, 0, // F
  }
};
const uint8_t PROGMEM banked_jump_flag[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
const uint8_t PROGMEM banked_jump_on_release[15] = {0xF, 0xF, 0x2, 0xF, 0xE, 0xF, 0x1, 0x0, 0xF, 0x1, 0xF, 0xF, 0xF, 0xF, 0xF};
  
uint8_t table_localdata[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t table_nextflag;
void (*table_command[16])(uint8_t argument) = {
  &pause, // 0
  &volumeup, // 1 
  &volumedown, // 2
  &setvolume, // 3
  &setdutycycle, // 4
  &setnote, // 5
  &shiftoctave, // 6
  &jumpto, // 7
  &shiftbend, // 8
  &setbend, // 9
  &shiftnote // A
};

USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface =
	{
		.Config =
			{
				.StreamingInterfaceNumber = 1,

				.DataINEndpointNumber      = MIDI_STREAM_IN_EPNUM,
				.DataINEndpointSize        = MIDI_STREAM_EPSIZE,
				.DataINEndpointDoubleBank  = false,

				.DataOUTEndpointNumber     = MIDI_STREAM_OUT_EPNUM,
				.DataOUTEndpointSize       = MIDI_STREAM_EPSIZE,
				.DataOUTEndpointDoubleBank = false,
			},
	};

    uint16_t midi_notes[10] = {0,0,0,0,0,0,0,0,0,0};
    uint8_t midi_changed = 0;
    uint8_t midi_new = 0;
    uint8_t midi_hasnotes = 0;

int main(void) {
    SetupHardware();
	
  (CLKPR = 0x80, CLKPR = (0)); // Set clock to 16MHz (for TEENSY BOARD)
    
  // Set DDR pins to output
  DDR_DAC = 0b1111;
  
  // Internal pull-ups
  PORT_CONTROL |= 0b11111111; // controls
  PORT_NOTES0 |= 0b11111111; // Notes C0-G0
  PORT_NOTES1 |= 0b11111111; // Notes G#0-D#1
  PORT_NOTES2 |= 0b11111111; // Notes E1-B1
    
  TCCR2A = 0b00000010; //CTC mode, all pins detached
  TCCR2B = 0; // Stopped; when started, will set to clk/256
  OCR2A = 255; // Overflow level
  TIMSK2 = 0b010;

  
  TCCR1A = 0b00000000;
  TCCR1B = 0b00000000; //Prescaler value

  TIMSK1 = 0b110; //Enable output compare B and A interrupt on timer 1
  
  TCCR0A = 0b10; // CTC
  TCCR0B = 0b101; // clk/1024
  OCR0A = 10; // Volume timer
  TIMSK0 = 0b10;
    
  load_settings(0);
  sei();

  for(;;) {
      	MIDI_Device_USBTask(&Keyboard_MIDI_Interface);
		USB_USBTask();
		
		MIDI_EventPacket_t ReceivedMIDIEvent;
   /*     while (MIDI_Device_ReceiveEventPacket(&Keyboard_MIDI_Interface, &ReceivedMIDIEvent)){
            if(ReceivedMIDIEvent.CableNumber == 0 && (ReceivedMIDIEvent.Data1 & 0xF) == MIDICHANNEL){
                if ((ReceivedMIDIEvent.Command == (0x90 >> 4)) && (ReceivedMIDIEvent.Data3 > 0)){
                    midi_notes[ReceivedMIDIEvent.Data2/12] |= (1 << (ReceivedMIDIEvent.Data2 % 12));
                    midi_changed = 1;
                    midi_new = !midi_hasnotes;
                    midi_hasnotes = 1;
                }
                else if (ReceivedMIDIEvent.Command == (0x80 >> 4) || ((ReceivedMIDIEvent.Command == (0x90 >> 4)) && (ReceivedMIDIEvent.Data3 == 0))){
                    midi_notes[ReceivedMIDIEvent.Data2/12] &= ~(1 << (ReceivedMIDIEvent.Data2 % 12));
                    midi_changed = 1;
                    midi_hasnotes = 0;
                    midi_new = 0;
                    for(int octave_count = 0; octave_count < 10; ++octave_count){
                        if(midi_notes[octave_count]){
                            midi_hasnotes = 1;
                            break;  
                        } 
                    }
                }
            }
        }*/
		
    // BEGIN ANALOGUE SETTINGS
    // This section is for future expansion, allowing analogue adjustment of arp_speed
    OCR2A = arp_speed + 10;
    // END ANALOGUE SETTINGS
  
 
    // BEGIN READ ALL NOTES AND CONTROLS
    
    control = (~PIN_CONTROL);
    
    pinreadbuffer = (~PIN_NOTES0);
    notes_pressed = pinreadbuffer;
    
    pinreadbuffer = (~PIN_NOTES1);
    notes_pressed |= ((uint32_t)pinreadbuffer << 8);
    
    pinreadbuffer = (~PIN_NOTES2);
    notes_pressed |= ((uint32_t)pinreadbuffer << 16);
    // END READ ALL NOTES AND CONTROLS
  
    //BEGIN DEBOUNCE
    if(notes_pressed == debounce_notes){
      debounce_notes_count++;
    } else {
      debounce_notes_count = 0;
      debounce_notes = notes_pressed;
    }
  
    if(control == debounce_control){
      debounce_control_count++;
    } else {
      debounce_control_count = 0;
      debounce_control = control;
    }
  
/*    pinread = PIND;
    if( debounce_held == !((pinread >> 7) & 1)){
      if(++debounce_held_count > HELD_DEBOUNCE){
        held_state = debounce_held;
      };
    } else {
      debounce_held_count = 0;
      debounce_held = !((pinread >> 7) & 1);
    }*/
    // END DEBOUNCE
  
    // BEGIN PROCESS HOLD BUTTON
    if( (held_state != last_held_state)){
      last_held_state = held_state;
      if(held_state){
        if(held_flag || notes_pressed){ // This OR condition ensures that a hold condition is only engaged if notes are pressed
          held_flag = !held_flag;
          held_changed = 1;
          if(held_flag){
            held_notes[octave] |= (uint16_t)(notes_pressed & 0b111111111111);
            held_notes[octave + 1] |= (uint16_t)(notes_pressed >> 12);
          } else {
            memset(held_notes, 0, 20);      
          }
        }
      }
    }
    // END PROCESS HOLD BUTTON 
  
    // BEGIN PROCESS CONTROL SEQUENCES
    if((last_control != control) && (debounce_control_count > CONTROL_DEBOUNCE)){
      last_control = control;
    
      if(control & 0b10000000) {
        if(octave) {
          octave--;
          octave_flag = 1;
        }
      }
      if(control & 0b01000000) {
        if(octave < 9) { // SET TO 8 FOR 24 KEYS
          octave++;
          octave_flag = 1;
        }
      }
      autobend = &autobend_return;
      if(control & 0b00100000) {
        autobend = &autobend_up;
        //arp_mode = (arp_mode + 1) % ARPMODES;
        //if(duty_cycle > 1) duty_cycle--;
      }
      if(control & 0b00010000) {
        autobend = &autobend_down;
        //arp_mode = (arp_mode + ARPMODES - 1) % ARPMODES;
        //if(duty_cycle < 3) duty_cycle++;
      }
      if (control & 0b00001111) {
        last_envelope |= (control & 0b1111);
        current_envelope = last_envelope - 1;
        load_settings(current_envelope);
      } else {
        last_envelope = 0;
      }
    }
    // END PROCESS CONTROL SEQUENCES

    // BEGIN PROCESS NOTES
    if( ( (last_notes_pressed != notes_pressed) && (debounce_notes_count > NOTES_DEBOUNCE)) || octave_flag || held_changed || midi_changed){
      chord_length = 0;
    
      if(held_flag && held_state){ // if the held button is pressed, add the currently pressed notes to the hold
        held_notes[octave] |= (uint16_t)(notes_pressed & 0b111111111111);
        held_notes[octave + 1] |= (uint16_t)(notes_pressed >> 12);
      }
      memcpy(all_notes, held_notes, 20);
      if(midi_hasnotes){
          for(int i = 0; i < 10; ++i){
              all_notes[i] |= midi_notes[i];
          }
      }
      all_notes[octave] |= (uint16_t)(notes_pressed & 0b111111111111);
      all_notes[octave + 1] |= (uint16_t)(notes_pressed >> 12);

      if(notes_pressed || held_flag || midi_hasnotes){ // Checks if any notes are pressed
        for(int octave_count = 0; octave_count < 10; ++octave_count){
          if(all_notes[octave_count]){
            for(int key_count = 0; key_count < 12; ++key_count){
              if( (all_notes[octave_count] >> key_count) & 1 ){
                chord[chord_length] = key_count + 12*octave_count;    
                // If it is newly pressed...
                if( ((octave_count == octave) && !((last_notes_pressed >> key_count) & 1)) || ((octave_count == octave+1) && !((last_notes_pressed >> (key_count+12)) & 1)) ){
                  arp_pos = chord_length; // ... adjust arpeggiation index to current note
                  arp_count = 0; // ... reset arpeggiation counter (do we actually want this?)
                  shift = 0;
                  TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]); // ... change the prescaler value to prevent "ghosting"
                }
              
                chord_length++;
              }
            }
          }
        }
        if(chord_length > 1){ // It's a real chord
          TCCR2B = 0b00000110; // Start arpeggiator clock: Prescaler at clk/256
        } else { // It's only a single note
          arp_pos = 0; // Move arpeggiator to first position
          TCCR2B = 0; // Stop arpeggiator clock
          shift = 0;
          TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
          if(last_notes_pressed) {noteOff(lastnote);}
          lastnote = MIDI_NOTE;
          if(chord_length){
             noteOn(MIDI_NOTE);
          }
          arp_count = 0;
        }
        if((!last_notes_pressed || midi_new) && !held_flag){ // If no notes were pressed before, begin the attack phase
          shift = 0;
          TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
          new_note();
        }
      } else if (!octave_flag) { // No notes are pressed, so start the release phase, stop last note, etc
        // ENVELOPE: RELEASE NOTE
        shift = 0;
        TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
        if(jump_flag) table_pos = jump_on_release << 1;
        table_delay = 0;
        table_timer = TABLE_SPEED;
        noteOff(lastnote);
        TCCR2B = 0;
      }
      last_notes_pressed = notes_pressed;
      octave_flag = 0;
      held_changed = 0;
      midi_changed = 0;
    }
    // END PROCESS NOTES
  
  }
}

// Arpeggiator timer
ISR(TIMER2_COMPA_vect){
    if(arp_count++ > 128){
       (*arpeggio[arp_mode])();
    }
}

// BEGIN NOTE GENERATION
// Note generator -- set high according to current volume state
ISR(TIMER1_COMPA_vect){
  notegen_a();
}

// More note generator -- bring low at COMPB interrupt, according to duty cycle
ISR(TIMER1_COMPB_vect){
  notegen_b();
}
// END NOTE GENERATION

// Utility clock: table, pitch autobend
ISR(TIMER0_COMPA_vect){
  sei();
  autobend();
  if(++table_timer > TABLE_SPEED && table_pos < 32){
    table_timer = 0;
  	if(table_delay){
  		--table_delay;
  	} else {
  	  do{
            (*table_command[HINIBBLE(table[table_pos])])(LONIBBLE(table[table_pos]));
  	  } while(table_nextflag);
  	}
  }
}
// BEGIN NOTE GENERATION METHODS
void square_a(){
  OCR1A = pgm_read_word(&note_freq[CURRENT_NOTE]) + (autobend_step + bend_step)*pgm_read_byte(&bend_depth[CURRENT_NOTE]);
  OCR1B = (OCR1A >> duty_cycle) ;
  TCNT1 = 0;
  PORT_DAC = muteflag ? 0 : volume;
}

void square_b(){
  PORT_DAC = 0b0;
}

void wave_a(){
  OCR1A = pgm_read_word(&note_freq[CURRENT_NOTE]) + (autobend_step + bend_step)*pgm_read_byte(&bend_depth[CURRENT_NOTE]);
  OCR1B = (OCR1A >> 1) ;
  TCNT1 = 0;
  PORT_DAC = volume ? pgm_read_byte(&saw_table[++wave_counter & 0b11111]) : 0;
}

void wave_b(){
  PORT_DAC = volume ? pgm_read_byte(&saw_table[++wave_counter & 0b11111]) : 0;
}
// END NOTE GENERATION METHODS

// BEGIN PITCH BEND METHODS
void autobend_down(){
  if(++autobend_counter > BEND_SPEED){
    autobend_counter = 0;
    if(autobend_step == BEND_MAX){
      return;
    }
    autobend_step++;
  }
}

void autobend_up(){
  if(++autobend_counter > BEND_SPEED){
    autobend_counter = 0;
    if(autobend_step == -BEND_MAX){
      return;
    }
    autobend_step--;
  }
}

void autobend_return(){
  if(++autobend_counter > BEND_SPEED){
    autobend_counter = 0;
    if(autobend_step > 0){
      --autobend_step;
    } else if (autobend_step < 0){
      ++autobend_step;
    }
  }
}
// END PITCH BEND METHODS 

// BEGIN ENVELOPE METHODS
void mute(){
  volume = 0;
  TCCR1B = 0;
  muteflag=1;
}
// END ENVELOPE METHODS

// BEGIN ARPEGGIO METHODS
void ascending(){
      noteOff(lastnote);
      arp_pos++;
      arp_pos %= chord_length;
      shift = 0;
      TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
      noteOn(MIDI_NOTE);
      lastnote = MIDI_NOTE;
      arp_count = 0;
      if(retrigger_flag) new_note();
}

void descending(){
      noteOff(lastnote);
      shift = 0;
      TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
      noteOn(MIDI_NOTE);
      lastnote = MIDI_NOTE;
      arp_count = 0;
      if(arp_pos){
        arp_pos--;
      } else {
        arp_pos = chord_length - 1;
      }
      if(retrigger_flag) new_note();
}

void random_arp(){
      noteOff(lastnote);
      
      //TODO: replace rand with something better (that gives a return value between 0 and chord_length-1, exclusive)
      arp_pos = (arp_pos + 1 + (rand() % (chord_length-1))) % chord_length;
      shift = 0; 
      TCCR1B = pgm_read_byte(&prescaler[CURRENT_NOTE]);
      noteOn(MIDI_NOTE);
      lastnote = MIDI_NOTE;
      arp_count = 0;
      if(retrigger_flag) new_note();
}
// END ARPEGGIO METHODS

// BEGIN MIDI METHODS
void noteOn(unsigned char note){
  MIDI_TX(144,note,127);
}

void noteOff(unsigned char note){
  MIDI_TX(128,note,127);
}

void MIDI_TX(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity) {
  /*Serial.print(MIDICommand);
  Serial.print(MIDIPitch);
  Serial.print(VELOCITY);*/
  
      uint8_t Channel = 0;

  	{
  		MIDI_EventPacket_t MIDIEvent = (MIDI_EventPacket_t)
  			{
  				.CableNumber = 0,
  				.Command     = (MIDICommand >> 4),

  				.Data1       = MIDICommand | Channel,
  				.Data2       = MIDIPitch,
  				.Data3       = velocity,
  			};

  		MIDI_Device_SendEventPacket(&Keyboard_MIDI_Interface, &MIDIEvent);
  		MIDI_Device_Flush(&Keyboard_MIDI_Interface);
  	}
  
}
// END MIDI METHODS

// BEGIN TABLE METHODS
void pause(uint8_t waittime){
  table_delay += waittime;
  table_nextflag = (++table_pos % 2);
}

void volumeup(uint8_t increment){
  volume = (volume + increment < 16) ? volume + increment : 0b1111;
  table_nextflag = (++table_pos % 2);
}

void volumedown(uint8_t increment){
  volume = (increment > volume) ? 0 : (volume - increment);
  table_nextflag = (++table_pos % 2);
}

void setvolume(uint8_t level){
  volume = level;
  table_nextflag = (++table_pos % 2);
}

void setdutycycle(uint8_t level){
  duty_cycle = (level % 3) + 1;
  table_nextflag = (++table_pos % 2);
}

void shiftnote(uint8_t interval){
  shift += (interval-7);
  table_nextflag = (++table_pos % 2);
}

void setnote(uint8_t interval){
  shift = (interval-7);
  table_nextflag = (++table_pos % 2);
}

void shiftoctave(uint8_t interval){ // NEEDS IMPROVEMENT
  shift+= 12*interval;
  table_nextflag = (++table_pos % 2);
}

void jumpto(uint8_t landing_index){ // With a second argument of 0, repeat forever
  if(table[table_pos+1]){
    table_nextflag = 1;
    if(table_localdata[table_pos >> 1] == table[table_pos+1]){
      table_localdata[table_pos >> 1] = 0;
      table_pos+=2;
    } else {
      ++table_localdata[table_pos >> 1];
      table_pos = 2*landing_index;
    }
  } else {
    table_nextflag = 0;
    table_pos = 2*landing_index;
  }
}

void shiftbend(uint8_t increment){
  bend_step += (increment-7);
  table_nextflag = (++table_pos % 2);  
}

void setbend(uint8_t increment){
  bend_step = (increment-7);
  table_nextflag = (++table_pos % 2);
}
// END TABLE METHODS

void load_settings(uint8_t bank){
  mute();
  start_volume = pgm_read_byte(&(banked_start_volume[bank]));
  start_duty_cycle = pgm_read_byte(&(banked_start_duty_cycle[bank]));
  memcpy_P(table, &(banked_table[bank]), 32);

  jump_on_release = pgm_read_byte(&(banked_jump_on_release[bank]));
  jump_flag = pgm_read_byte(&(banked_jump_flag[bank]));

  arp_mode = pgm_read_byte(&(banked_arp_mode[bank])) % ARPMODES;
  arp_speed = pgm_read_byte(&(banked_arp_speed[bank]));
  retrigger_flag = pgm_read_byte(&(banked_retrigger_flag[bank]));
  if(notes_pressed || held_flag || midi_hasnotes) new_note();
}

void new_note(){
  shift = 0;
  table_pos = 0;
  volume = start_volume;
  duty_cycle = start_duty_cycle;
  memset(table_localdata,0,16);
  table_timer = TABLE_SPEED;
  muteflag = 0;
}

void SetupHardware(void)
{
	/* Disable watchdog if enabled by bootloader/fuses */
	MCUSR &= ~(1 << WDRF);
	// wdt_disable();

	/* Disable clock division */
	//clock_prescale_set(clock_div_1);

	/* Hardware Initialization */
	USB_Init();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= MIDI_Device_ConfigureEndpoints(&Keyboard_MIDI_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	MIDI_Device_ProcessControlRequest(&Keyboard_MIDI_Interface);
}