//emfi.c

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "inc/tm4c123gh6pm.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "uart/uart.h"

#define UART UART0

#define R ((unsigned char)'R')
#define C ((unsigned char)'C')

int main() {
    bool ledVal = false;

    const uint32_t magic = 0xDEADBEEF;

    return 0;
}
