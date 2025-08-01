#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"

//#include "lib/driverlib/gpio.h"
#include "pico/stdlib.h"
#include "pico/time.h"

#define EMP_PIN 7

#define LED_PIN 25
int main() {
    stdio_init_all();
    gpio_init(EMP_PIN);
    gpio_init(LED_PIN);

    gpio_set_dir(EMP_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    initialize_uarts();
    uart_set_pin(UART1, )
    uart_init(UART0);
    uart_init(UART1);

    uint64_t cnt = 1;
    const uint64_t inc = 1;
    uint8_t buf;
    while (uart_read_blocking(UART1, buf, 1) != 'A') {
        sleep_us(1);
    }
    while (true) {
        sleep_us(cnt);
        gpio_put(EMP_PIN, 1);
        uint8_t ret = uart_read_blocking(UART1, buf, 1);
        if (ret == 'B') {
            for (int i = 0; i < 4; i++) {
                uart_write_blocking(UART0, 'A', 1);
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
