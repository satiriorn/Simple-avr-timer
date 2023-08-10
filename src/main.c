#include "timer.h"
#include "STDIO_UART.h"

#include <avr/interrupt.h>

int main() {
    uart_init();
    timer_init();
    sei(); // Enable global interrupts
    printf("Start");
    while (1) {
        if (milliseconds >= 1000) {
            milliseconds = 0;
            seconds++;
            if(seconds==60){
                minutes++;
                seconds = 0;
            }
            if(minutes==60){
                hours++;
                minutes = 0;
            }
            printf("%i:%i:%i\r\n", hours, minutes, seconds);
        }
    }

    return 0;
}


ISR(TIMER0_COMPA_vect) {
    milliseconds++;
}