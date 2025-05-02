#include "nrf52833.h"

// period = (16000000/freq_Hz)

// we use a prescaler of 4, so the PWM counter runs at 16MHz/4=4MHz
// period = (4000000/freq_Hz)

#define NOTE_NONE      0 // 246.94 Hz
#define NOTE_SI_2  16198 // 246.94 Hz
#define NOTE_DO_3  15289 // 261.63 Hz
#define NOTE_RE_3  13621 // 293.66 Hz
#define NOTE_MI_3  12135 // 329.63 Hz
#define NOTE_FA_3  11454 // 349.23 Hz
#define NOTE_SOL_3 10204 // 392.00 Hz
#define NOTE_LA_3   9091 // 440.00 Hz
#define NOTE_SI_3   8099 // 493.88 Hz
#define NOTE_DO_4   7645 // 523.25 Hz

// 4th Octave
#define NOTE_C4   1911  // 261.63 Hz
#define NOTE_CS4  1804  // 277.18 Hz
#define NOTE_D4   1703  // 293.66 Hz
#define NOTE_DS4  1607  // 311.13 Hz
#define NOTE_E4   1517  // 329.63 Hz
#define NOTE_F4   1432  // 349.23 Hz
#define NOTE_FS4  1351  // 369.99 Hz
#define NOTE_G4   1275  // 392.00 Hz
#define NOTE_GS4  1204  // 415.30 Hz
#define NOTE_A4   1136  // 440.00 Hz
#define NOTE_AS4  1073  // 466.16 Hz
#define NOTE_B4   1012  // 493.88 Hz

// 5th Octave
#define NOTE_C5    956  // 523.25 Hz
#define NOTE_CS5   902  // 554.37 Hz
#define NOTE_D5    851  // 587.33 Hz
#define NOTE_DS5   803  // 622.25 Hz
#define NOTE_E5    758  // 659.25 Hz
#define NOTE_F5    716  // 698.46 Hz
#define NOTE_FS5   676  // 739.99 Hz
#define NOTE_G5    638  // 783.99 Hz
#define NOTE_GS5   602  // 830.61 Hz
#define NOTE_A5    568  // 880.00 Hz
#define NOTE_AS5   536  // 932.33 Hz
#define NOTE_B5    506  // 987.77 Hz

//uint16_t song[] = {
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_DO_3, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_LA_3,  NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_SOL_3, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_SOL_3, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_SOL_3, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_SOL_3, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//    NOTE_SI_2, NOTE_MI_3, NOTE_SOL_3, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE, NOTE_NONE,
//};
uint16_t song[] = {


  // Hedwig's theme fromn the Harry Potter Movies
  // Socre from https://musescore.com/user/3811306/scores/4906610
  
  NOTE_NONE, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  NOTE_NONE,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1, 
  
};
uint16_t beat;

uint16_t pwm_comp[1];

void pwm_init(void) {
    
    // configure P0.00 as output
    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: DIR:     1=Output
    // .... .... .... .... .... .... .... ..B. B: INPUT:   1=Disconnect
    // .... .... .... .... .... .... .... CC.. C: PULL:    0=Disabled
    // .... .... .... .... .... .DDD .... .... D: DRIVE:   0=S0S1
    // .... .... .... ..EE .... .... .... .... E: SENSE:   0=Disabled
    // xxxx xxxx xxxx xx00 xxxx xxxx xxxx 0011 
    //    0    0    0    0    0    0    0    3 0x00000003
    NRF_P0->PIN_CNF[0]            = 0x00000003;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... ...A AAAA A: PIN:      00 (P0.00)
    // .... .... .... .... .... .... ..B. .... B: PORT:     0  (P0.00)
    // C... .... .... .... .... .... .... .... C: CONNECT:  0=Connected
    // 0xxx xxxx xxxx xxxx xxxx xxxx xx00 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->PSEL.OUT[0]         = 0x00000000;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: ENABLE:   1=Enabled
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1 
    //    0    0    0    0    0    0    0    1 0x00000001
    NRF_PWM0->ENABLE              = 0x00000001;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: UPDOWN:   0=Up
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx xxx0 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->MODE                = 0x00000000;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... .AAA A: PRESCALER: 0=DIV_1
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx x000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->PRESCALER           = 2;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... AAAA AAAA AAAA AAAA A: CNT:      0=Disabled
    // 0xxx xxxx xxxx xxxx 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->LOOP                = 0x00000000;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ..AA A: LOAD:     0=Common
    // .... .... .... .... .... ...B .... .... B: MODE:     0=RefreshCount
    // 0xxx xxxx xxxx xxxx xxxx xxx0 xxxx xx00 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->DECODER             = 0x00000000;
    NRF_PWM0->SEQ[0].PTR          = (uint32_t)(pwm_comp);
    NRF_PWM0->SEQ[0].CNT          = (sizeof(pwm_comp) / sizeof(uint16_t));

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... AAAA AAAA AAAA AAAA AAAA AAAA A: CNT:      0=Continuous
    // 0xxx xxxx 0000 0000 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->SEQ[0].REFRESH      = 0;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... AAAA AAAA AAAA AAAA AAAA AAAA A: CNT
    // 0xxx xxxx 0000 0000 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->SEQ[0].ENDDELAY     = 0;
}

void pwm_setperiod(uint16_t period) {

    if(NRF_PWM0->EVENTS_SEQSTARTED[0]==1) {
        NRF_PWM0->EVENTS_STOPPED  = 0;
        NRF_PWM0->TASKS_STOP      = 0x00000001;
        while(NRF_PWM0->EVENTS_STOPPED==0);
    }

    NRF_PWM0->COUNTERTOP          = period;
    pwm_comp[0]                   = period/2;

    NRF_PWM0->EVENTS_SEQSTARTED[0]=0;
    NRF_PWM0->TASKS_SEQSTART[0]   = 0x00000001;
    while(NRF_PWM0->EVENTS_SEQSTARTED[0]==0);
}

void rtc_init(void) {
    
    // configure/start the RTC
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // xxxx xxxx xxxx FEDC xxxx xxxx xxxx xxBA (C=compare 0)
    // 0000 0000 0000 0001 0000 0000 0000 0000 
    //    0    0    0    1    0    0    0    0 0x00010000
    NRF_RTC0->EVTENSET                 = 0x00010000;       // enable compare 0 event routing
    NRF_RTC0->INTENSET                 = 0x00010000;       // enable compare 0 interrupts

    // enable interrupts
    NVIC_SetPriority(RTC0_IRQn, 1);
    NVIC_ClearPendingIRQ(RTC0_IRQn);
    NVIC_EnableIRQ(RTC0_IRQn);

    // have RTC tick every second
    NRF_RTC0->CC[0]                    = 8000;             // 32768==1 s --> 1317==40.1ms
    NRF_RTC0->TASKS_START              = 0x00000001;       // start RTC0
}
    
int main(void) {
    pwm_init();
    rtc_init();

    while(1);
}

void RTC0_IRQHandler(void) {
    
    if (NRF_RTC0->EVENTS_COMPARE[0] == 0x00000001 ) {
        // handle compare[0]

        // clear flag
        NRF_RTC0->EVENTS_COMPARE[0]    = 0x00000000;

        // clear COUNTER
        NRF_RTC0->TASKS_CLEAR          = 0x00000001;

        pwm_setperiod(song[beat]);
        beat = (beat+1)%(sizeof(song) / sizeof(uint16_t));
    }
}