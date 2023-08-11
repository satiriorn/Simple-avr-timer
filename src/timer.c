#include <avr/io.h>

void timer_init(void) {
    TCCR0A = (1 << WGM01); // CTC mode
    TCCR0B = (1 << CS02) | (1 << CS00); // prescaler on 1024

    OCR0A = 252; // // Reaching a value of 252 will give an interrupt every 16ms 
    TIMSK0 = (1 << OCIE0A); //enable interrupt
}

void timer_stop(void){
    TCCR0B = 0;
}
