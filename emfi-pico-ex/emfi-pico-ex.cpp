#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"

#include <lib/uart/uart.h>


#include "pico/stdlib.h"
#include "pico/time.h"
//#include "pico/gpio.h"

#define EMP_PIN 7

#define LED_PIN 25
int main() {
    stdio_init_all();
    gpio_init(EMP_PIN);
    gpio_init(LED_PIN);

    gpio_set_dir(EMP_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    uart_inst_t *uart0 = uart_get_instance(UART0)

    gpio_set_function(4, GPIO_FUNC_UART);
    gpio_set_function(5, GPIO_FUNC_UART);
    uart_inst_t *uart1 = uart_get_instance(UART1)

    uart_init(uart0, 115200);
    uart_init(uart1,115200);

    uint64_t cnt = 1;
    const uint64_t inc = 1;
    while (uart_getc(uart0) != 'A') {
        sleep_us(1);
    }
    while (true) {
        uart_putc(uart1, 0x11);
        sleep_us(cnt);
        gpio_put(EMP_PIN, 1);
        uint8_t ret = uart_getc(uart1);
        if (ret == 'B') {
            for (int i = 0; i < 4; i++) {
                uart_putc(uart0, (cnt & 0xFF));
                cnt >>= 2;
            }
            break;
        }
        else if (ret != 'A') return -1;
        cnt += inc;
    }

    // Control flow faulted via EMFI!!!
    gpio_put(LED_PIN, 1);
    printf("FAULT DETECTED - LED ON\n");

    while (true) {
        tight_loop_contents();
    }
}
