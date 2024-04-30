#include "Arduino.h"

void delay(unsigned long ms){
    usleep(ms * 1000);
}

void delayMicroseconds(unsigned int us){
    usleep(us);
}

unsigned long millis(void){
    struct timespec* tp;

    clock_gettime(CLOCK_MONOTONIC, tp);

}
unsigned long micros(void);