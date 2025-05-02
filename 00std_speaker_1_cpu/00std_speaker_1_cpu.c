#include "nrf52833.h"

void wait(uint32_t tone) {
    volatile uint32_t a;
    for (a=0; a<tone;a++);
}

int main(void) {
    
    // set speaker pin as output
    NRF_P0->PIN_CNF[0] = 0x00000003; // P0.00

    uint32_t tone = 1000;
    while(1) {
        NRF_P0->OUTSET = (0x00000001 << 0); // speaker pin high
        wait(tone);
        NRF_P0->OUTCLR = (0x00000001 << 0); // speaker pin low
        wait(tone);
        tone += 10;
        if (tone > 8000){
          tone = 1000;
        }
    }
}
