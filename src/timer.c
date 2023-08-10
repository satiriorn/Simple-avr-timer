#include <avr/io.h>

void timer_init() {
    TCCR0A = (1 << WGM01);
    OCR0A = 249;            // Reaching a value of 249 will give an interrupt every 1ms
    TIMSK0 = (1 << OCIE0A); // enable interrupt
    TCCR0B = (1 << CS01) | (1 << CS00); 
}
