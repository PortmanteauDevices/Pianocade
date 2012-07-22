#include "pianocade.h"

const uint8_t prescaler[TOTAL_NOTES] PROGMEM = {0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010};
//const uint8_t prescaler[TOTAL_NOTES] PROGMEM = {0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001, 0b001};

const uint16_t note_freq[TOTAL_NOTES] PROGMEM = {30577, 28861, 27241, 25712, 24269, 22907, 21621, 20407, 19262, 18181, 17160, 16197, 15288, 14430, 13620, 12855, 12134, 11453, 10810, 10203, 9630, 9090, 8580, 8098, 61155, 57723, 54483, 51425, 48539, 45814, 43243, 40816, 38525, 36363, 34322, 32395, 30577, 28861, 27241, 25712, 24269, 22907, 21621, 20407, 19262, 18181, 17160, 16197, 15288, 14430, 13620, 12855, 12134, 11453, 10810, 10203, 9630, 9090, 8580, 8098, 7644, 7214, 6809, 6427, 6066, 5726, 5404, 5101, 4815, 4544, 4289, 4049, 3821, 3607, 3404, 3213, 3033, 2862, 2702, 2550, 2407, 2272, 2144, 2024, 1910, 1803, 1702, 1606, 1516, 1431, 1350, 1275, 1203, 1135, 1072, 1011, 955, 901, 850, 803, 757, 715, 675, 637, 601, 567, 535, 505, 477, 450, 425, 401, 378, 357, 337, 318, 300, 283, 267, 252, 238, 224, 212, 200, 189, 178, 168, 158};

const uint8_t bend_depth[TOTAL_NOTES] PROGMEM = {110, 104, 98, 93, 88, 83, 78, 74, 70, 66, 62, 58, 55, 52, 49, 46, 44, 41, 39, 37, 35, 33, 31, 29, 221, 208, 197, 186, 175, 165, 156, 147, 139, 131, 124, 117, 110, 104, 98, 93, 88, 83, 78, 74, 70, 66, 62, 58, 55, 52, 49, 46, 44, 41, 39, 37, 35, 33, 31, 29, 28, 26, 25, 23, 22, 21, 20, 18, 17, 16, 15, 15, 14, 13, 12, 12, 11, 10, 10, 9, 9, 8, 8, 7, 7, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const uint8_t sine_table[32] PROGMEM = {0, 0, 1, 1, 2, 3, 5, 6, 8, 9, 10, 12, 13, 14, 14, 15, 15, 15, 14, 14, 13, 12, 10, 9, 8, 6, 5, 3, 2, 1, 1, 0};
const uint8_t saw_table[32] PROGMEM = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15};
uint8_t wave_counter = 0;

uint8_t chord[MAXCHORD];
volatile uint8_t chord_length = 0;
uint8_t last_chord_length = 0;

uint16_t all_notes[OCTAVE_TOTAL] = {0};
uint16_t last_all_notes[OCTAVE_TOTAL] = {0};
uint16_t held_notes[OCTAVE_TOTAL] = {0};
uint8_t held_state = 0;
uint8_t held_changed = 0;
uint8_t held_hasnotes = 0;

uint8_t lastnote = 0;
uint8_t note_is_playing = 0;

uint8_t octave = 4;

uint8_t transpose = 0;

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

uint8_t last_coin = 0;
uint8_t coin = 0;
uint8_t debounce_coin = 0;
uint8_t debounce_coin_count = 0;

uint32_t last_notes_pressed = 0b0;
uint32_t notes_pressed = 0b0;
uint32_t debounce_notes = 0b0;
uint8_t debounce_notes_count = 0;

volatile uint8_t volume = 0b1111;
uint8_t duty_cycle = 1;

int8_t shift = 0;
uint8_t current_envelope = 0;
uint8_t last_envelope = 0;
uint8_t muteflag = 0;

void (*arpeggio[ARPMODES])(void) = {&ascending, &descending, &random_arp};
uint8_t arp_mode;

//void (*notegen_a)(void) = &square_a;
//void (*notegen_b)(void) = &square_b;

uint8_t table_delay = 0;
uint8_t table_timer = 0;
uint8_t table_pos = 0;

uint8_t start_volume;
uint8_t start_duty_cycle;
uint8_t table[TABLE_SIZE];
uint8_t jump_on_release;
uint8_t jump_flag;
uint8_t retrigger_flag;

uint8_t pinreadbuffer;

const uint8_t EEMEM banked_start_volume[BANK_SIZE] = {0xFF, 0xF, 0x0, 0xF, 0xB, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x3};
const uint8_t EEMEM banked_arp_mode[BANK_SIZE] = {0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
const uint8_t EEMEM banked_arp_speed[BANK_SIZE] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 120, 120, 120, 120, 120};
const uint8_t EEMEM banked_retrigger_flag[BANK_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
const uint8_t EEMEM banked_start_duty_cycle[BANK_SIZE] = {1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const uint8_t EEMEM banked_table[BANK_SIZE][TABLE_SIZE] = {
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
const uint8_t EEMEM banked_jump_flag[BANK_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
const uint8_t EEMEM banked_jump_on_release[BANK_SIZE] = {0xF, 0xF, 0x2, 0xF, 0xE, 0xF, 0x1, 0x0, 0xF, 0x1, 0xF, 0xF, 0xF, 0xF, 0xF};

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
    &shiftnote, // A
    &setvolumevelocity, // B
    &shiftnoteup, // C
    &shiftnotedown // D
};

int main(void) {
    pianocadeSetup();
    initializeTranspose();
    for(;;) {
        // If we're on the MIDI clock, advance Arp
        if(midi_clock_flag && midi_tick >= midi_tempo){
            midi_tick %= midi_tempo;
            cli();
            (*arpeggio[arp_mode])();
            sei();
            TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
        }

        // Check for and process any available MIDI input
        MIDI_rx();

        // BEGIN ANALOGUE SETTINGS
        // This section is for future expansion, allowing analogue adjustment of arp_speed
        OCR2A = arp_speed + 10;
        // END ANALOGUE SETTINGS

        // READ ALL NOTES AND CONTROLS
        readPins();
        debouncePins();

        // PROCESS CONTROLS
        processControls();
        processCoins();

        // PROCESS NOTES
        processNotes();
    }
}

// Arpeggiator timer
ISR(TIMER2_COMPA_vect, ISR_NOBLOCK){
    if(!midi_clock_flag){
        if(arp_count++ > 32){
            //TCCR1B = 0;
            (*arpeggio[arp_mode])();
            TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
        }
    }
}

// BEGIN NOTE GENERATION
// Note generator -- set high according to current volume state
ISR(TIMER1_COMPA_vect){
    square_a();
}

// More note generator -- bring low at COMPB interrupt, according to duty cycle
ISR(TIMER1_COMPB_vect){
    square_b();
}
// END NOTE GENERATION

// Utility clock: table, pitch autobend
ISR(TIMER0_COMPA_vect){
    autobend();
    if(++table_timer > TABLE_SPEED && table_pos < TABLE_SIZE){
        table_timer = 0;
        if(table_delay){
            --table_delay;
        } else {
            do{
                (*table_command[HINIBBLE(table[table_pos % TABLE_SIZE])])(LONIBBLE(table[table_pos % TABLE_SIZE]));
            } while(table_nextflag);
        }
    }
}
// BEGIN NOTE GENERATION METHODS
static inline void square_a(){
    OCR1A = pgm_read_word(&note_freq[CURRENT_PITCH]) + (autobend_step + bend_step + midi_bend_step)*pgm_read_byte(&bend_depth[CURRENT_PITCH]);
    OCR1B = (OCR1A >> duty_cycle) ;
    TCNT1 = 0;
    PORT_DAC = muteflag ? 0 : volume;
}

static inline void square_b(){
    PORT_DAC = 0b0;
}

void wave_a(){
    OCR1A = pgm_read_word(&note_freq[CURRENT_PITCH]) + (autobend_step + bend_step + midi_bend_step)*pgm_read_byte(&bend_depth[CURRENT_PITCH]);
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
    if(midi_arp_output){MIDI_tx_noteOff(lastnote);}
    if(arp_pos < chord_length - 1){
        arp_pos++;
    } else {
        arp_pos = 0;
    }
    shift = 0;
//    TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
    if(midi_arp_output){MIDI_tx_noteOn(CURRENT_NOTE);}
    lastnote = CURRENT_NOTE;
    arp_count = 0;
    if(retrigger_flag) new_note();
}

void descending(){
    if(midi_arp_output){MIDI_tx_noteOff(lastnote);}
    shift = 0;
//    TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
    if(midi_arp_output){MIDI_tx_noteOn(CURRENT_NOTE);}
    lastnote = CURRENT_NOTE;
    arp_count = 0;
    if(arp_pos){
        arp_pos--;
    } else {
        arp_pos = chord_length - 1;
    }
    if(retrigger_flag) new_note();
}

void random_arp(){
    if(midi_arp_output){MIDI_tx_noteOff(lastnote);}

    //TODO: replace rand with something better (that gives a return value between 0 and chord_length-1, exclusive)
    arp_pos = (arp_pos + 1 + (rand() % (chord_length-1))) % chord_length;
    shift = 0;

//    TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
    if(midi_arp_output){MIDI_tx_noteOn(CURRENT_NOTE);}
    lastnote = CURRENT_NOTE;
    arp_count = 0;
    if(retrigger_flag) new_note();
}
// END ARPEGGIO METHODS

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

void shiftnoteup(uint8_t interval){
    shift += interval;
    table_nextflag = (++table_pos % 2);
}

void shiftnotedown(uint8_t interval){
    shift -= interval;
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

void setvolumevelocity(uint8_t unused){
    volume = midi_velocity >> 3;
    table_nextflag = (++table_pos % 2);
}
// END TABLE METHODS

void load_settings(uint8_t bank){
    if(bank < BANK_SIZE){
        mute();
        start_volume = eeprom_read_byte(&(banked_start_volume[bank]));
        start_duty_cycle = eeprom_read_byte(&(banked_start_duty_cycle[bank]));
        
        eeprom_read_block((void*)&table, (const void*)&(banked_table[bank]), TABLE_SIZE);

        jump_on_release = eeprom_read_byte(&(banked_jump_on_release[bank]));
        jump_flag = eeprom_read_byte(&(banked_jump_flag[bank]));

        arp_mode = eeprom_read_byte(&(banked_arp_mode[bank])) % ARPMODES;
        arp_speed = eeprom_read_byte(&(banked_arp_speed[bank]));
        retrigger_flag = eeprom_read_byte(&(banked_retrigger_flag[bank]));
        load_settings_ifPlaying();
    }
}

void load_settings_ifPlaying(void){
    if(chord_length == 1) TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
    if(notes_pressed || held_hasnotes || midi_hasnotes) new_note();
}

void save_settings(uint8_t bank){
    if(bank < BANK_SIZE){
        cli();
        eeprom_update_byte(&(banked_start_volume[bank]), start_volume);
        eeprom_update_byte(&(banked_start_duty_cycle[bank]), start_duty_cycle);
        
        eeprom_update_block((const void*)&table, (void*)&(banked_table[bank]), TABLE_SIZE);
        
        eeprom_update_byte(&(banked_jump_on_release[bank]), jump_on_release);
        eeprom_update_byte(&(banked_jump_flag[bank]), jump_flag);
        
        eeprom_update_byte(&(banked_arp_mode[bank]), arp_mode);
        eeprom_update_byte(&(banked_arp_speed[bank]), arp_speed);
        eeprom_update_byte(&(banked_retrigger_flag[bank]), retrigger_flag);
        sei();
    }
}

void new_note(){
    shift = 0;
    bend_step = 0;
    table_pos = 0;
    volume = (start_volume > 0xF) ? (midi_velocity >> 3) : start_volume;
    duty_cycle = start_duty_cycle;
    memset(table_localdata,0,16);
    table_timer = TABLE_SPEED;
    muteflag = 0;
}

static inline void pianocadeSetup(){
    MIDI_init();

    (CLKPR = 0x80, CLKPR = (0)); // Set clock to 16MHz (for TEENSY BOARD)

    // Set DDR pins to output
    DDR_DAC = 0b1111;
    DDRD = 0b11000000; // coin lights

    // Internal pull-ups
    PORT_CONTROL |= 0b11111111; // controls
    PORT_NOTES0 |= 0b11111111; // Notes C0-G0
    PORT_NOTES1 |= 0b11111111; // Notes G#0-D#1
    PORT_NOTES2 |= 0b11111111; // Notes E1-B1
    PORTD |= 0b00110001; // High C, coin buttons

    TCCR2A = 0b00000010; //CTC mode, all pins detached
    TCCR2B = 0; // Stopped; when started, will set to clk/1024
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
}

static inline void initializeTranspose(){
    readPins();
    for(uint8_t i = 0; i < 25; ++i){
        if((notes_pressed >> i) & 1){
            transpose = i % 12;
            break;
        }
    }
    while(notes_pressed){
        readPins();
    }
    notes_pressed = 0;
    control = 0;
}

static inline void readPins(){
    control = (~PIN_CONTROL);
    coin = (~PIND);

    pinreadbuffer = (~PIN_NOTES0);
    notes_pressed = pinreadbuffer;

    pinreadbuffer = (~PIN_NOTES1);
    notes_pressed |= ((uint32_t)pinreadbuffer << 8);

    pinreadbuffer = (~PIN_NOTES2);
    notes_pressed |= ((uint32_t)pinreadbuffer << 16);
    
    pinreadbuffer = coin;
    if(pinreadbuffer & 1) notes_pressed |= ((uint32_t)1 << 24);
}

static inline void debouncePins(){
    // Debounce note keys
    if(notes_pressed == debounce_notes){
        debounce_notes_count++;
    } else {
        debounce_notes_count = 0;
        debounce_notes = notes_pressed;
    }

    // Debounce control keys
    if(control == debounce_control){
        debounce_control_count++;
    } else {
        debounce_control_count = 0;
        debounce_control = control;
    }
    
    // Debounce coin keys
    if(coin == debounce_coin){
        debounce_coin_count++;
    } else {
        debounce_coin_count = 0;
        debounce_coin = coin;
    }
}

static inline void processHold(){
    for(int i = 0; i < OCTAVE_TOTAL; ++i){
        held_notes[i] |= all_notes[i];
        if(held_notes[i]) held_hasnotes = 1;
    }
}

static inline void clearHold(){
    memset(held_notes, 0, 2*OCTAVE_TOTAL);
    held_hasnotes = 0;
    held_changed = 1;    
}

static inline void processControls(){
    if((last_control != control) && (debounce_control_count > CONTROL_DEBOUNCE)){
        last_control = control;

        if(control & 0b00100000) {
            if(octave > OCTAVE_MIN) {
                onOctaveChange();
                octave--;
            }
        }
        if(control & 0b01000000) {
            if(octave < OCTAVE_MAX) {
                onOctaveChange();
                octave++;
            }
        }
        autobend = &autobend_return;
        if(control & 0b00010000) {
            autobend = &autobend_up;
            //arp_mode = (arp_mode + 1) % ARPMODES;
            //if(duty_cycle > 1) duty_cycle--;
        }
        if(control & 0b10000000) {
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
}

static inline void processCoins(){
    if((last_coin != coin) && (debounce_coin_count > CONTROL_DEBOUNCE)){
        last_coin = coin;

        if(coin & 0b00100000) {
            clearHold();
        }
        
        if(coin & 0b00010000) {
            held_state = 1;
            processHold();
        } else {
            held_state = 0;
        }
    }
}

static inline void onOctaveChange(){
    if(!midi_arp_output){
        for(int key_count = 0; key_count < 25; ++key_count){
            if((last_notes_pressed >> key_count) & 1){
                MIDI_tx_noteOff(key_count + 12*octave);
            }
        }
    }
    last_notes_pressed = 0;
}

static inline void loadPressedNotes(uint16_t noteStore[]){
    noteStore[octave] |= (uint16_t)((notes_pressed << transpose) & 0b111111111111);
    noteStore[octave + 1] |= (uint16_t)(notes_pressed >> (12 - transpose));
    noteStore[octave + 2] |= (uint16_t)(notes_pressed >> (24 - transpose));
}

static inline void processNotes(){
    uint8_t pressed_changed = (last_notes_pressed != notes_pressed) && (debounce_notes_count > NOTES_DEBOUNCE);
    if( !midi_arp_output && pressed_changed ){
        uint32_t pressed_diff = last_notes_pressed ^ notes_pressed;
        for(int key_count = 0; key_count < 25; ++key_count){
            if((pressed_diff >> key_count) & 1){
                ((notes_pressed >> key_count) & 1) ? MIDI_tx_noteOn(key_count + 12*octave) : MIDI_tx_noteOff(key_count + 12*octave);
            }
        }
    }
    if(notes_pressed) midi_velocity = MIDI_DEFAULT_VELOCITY;
    if( pressed_changed || midi_changed || held_changed ){
        chord_length = 0;

        memcpy(all_notes, held_notes, 2*OCTAVE_TOTAL);
        if(midi_hasnotes){
            for(int i = 0; i < OCTAVE_TOTAL; ++i){
                all_notes[i] |= midi_notes[i];
            }
        }
        if(midi_local_control){
            loadPressedNotes(all_notes);
        }
        
        if(held_state) processHold();

        if( (notes_pressed && midi_local_control) || held_hasnotes || midi_hasnotes){ // Checks if any notes are pressed
            for(int octave_count = 0; octave_count < OCTAVE_TOTAL; ++octave_count){
                if(all_notes[octave_count]){
                    for(int key_count = 0; key_count < 12; ++key_count){
                        if( (all_notes[octave_count] >> key_count) & 1 ){
                            cli();
                            chord[chord_length++] = key_count + 12*octave_count;

                            // If it is newly pressed...
                            if( !((last_all_notes[octave_count] >> key_count) & 1) ){
                                if(midi_arp_output && note_is_playing){MIDI_tx_noteOff(lastnote);} // ... turn the last note off
                                arp_pos = chord_length-1; // ... adjust arpeggiation index to current note
                                if(midi_arp_output){
                                    MIDI_tx_noteOn(CURRENT_NOTE); // .. turn the current note on
                                    note_is_playing = 1;
                                }
                                lastnote = CURRENT_NOTE;
                                arp_count = 0; // ... reset arpeggiation counter (do we actually want this?)
                                shift = 0;
                                TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]); // ... change the prescaler value to prevent "ghosting"
                                new_note();
                            }
                            sei();
                        }
                    }
                }
            }
            if( !(all_notes[CURRENT_NOTE/12] >> (CURRENT_NOTE % 12) & 1) ){
                cli();
                // If the current playing note is NOT set advance the arpeggio counter
                (*arpeggio[arp_mode])();
                sei();
            }
            if(chord_length > 1){ // It's a real chord
                TCCR2B = 0b00000111; // Start arpeggiator clock: Prescaler at clk/1024
            } else { // It's only a single note
                TCCR2B = 0; // Stop arpeggiator clock
            }
            if(!last_chord_length){ // If no notes were pressed before, begin the attack phase
                shift = 0;
                TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
                new_note();
            }
            last_chord_length = chord_length;
        } else { // No notes are pressed, so start the release phase, stop last note, etc
        // ENVELOPE: RELEASE NOTE
            //shift = 0; // Why was this here?! Seems wrong to interrupt the shift level
            TCCR1B = pgm_read_byte(&prescaler[CURRENT_PITCH]);
            if(jump_flag) table_pos = jump_on_release << 1;
            table_delay = 0;
            table_timer = TABLE_SPEED;
            if(midi_arp_output) { MIDI_tx_noteOff(lastnote); }
            TCCR2B = 0;
            last_chord_length = 0;
            note_is_playing = 0;
        }
        last_notes_pressed = notes_pressed;
        memcpy(last_all_notes, all_notes, 2*OCTAVE_TOTAL);
        midi_changed = 0;
        held_changed = 0;
    }
}