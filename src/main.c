#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "timer.h"
#include "STDIO_UART.h"
#include <avr/interrupt.h>

int main() {
    uart_init();
    timer_init();
    sei(); // Enable global interrupts
    printf("Start");
    
    while (1) {
        //code
    }
    return 0;
}


ISR(TIMER0_COMPA_vect) {
    milliseconds+=16;
    if (milliseconds >= 1000) {
		milliseconds = 0;
		seconds++;
        printf("%i:%i:%i\r\n", hours, minutes, seconds);
	}
	if(seconds==59){
		minutes++;
		seconds = 0;
        printf("%i:%i:%i\r\n", hours, minutes, seconds);
	}
	if(minutes==59){
		hours++;
		minutes = 0;
	}
}