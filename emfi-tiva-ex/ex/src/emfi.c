//lab9.c

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "tm4c123gh6pm.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "uart/uart.h"

#define UART UART0

#define R ((unsigned char)'R')
#define C ((unsigned char)'C')

int main() {
    bool ledVal = false;

    const uint32_t magic = 0xDEADBEEF;

    while (true) {
        tight_loop_contents();
    }
    unsigned int state;
    SYSCTL->RCGCGPIO |= 0x20;   /* enable clock to GPIOF */
    GPIOF->LOCK = 0x4C4F434B;   // unlockGPIOCR register
    GPIOF->CR = 0x01;           // Enable GPIOPUR register enable to commit
    GPIOF->PUR |= 0x10;         // Enable Pull Up resistor PF4
    GPIOF->DIR |= 0x02;         //set PF1 as an output and PF4 as an input pin
    GPIOF->DEN |= 0x12;         // Enable PF1 and PF4 as a digital GPIO pins 

    while(true)
    {   
        state = GPIOF->DATA & 0x10;
        GPIOF->DATA = (~state>>3);    /* put it on red LED */
    }
}
