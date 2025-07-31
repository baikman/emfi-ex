#include <stdio.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_PIN 25

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    bool ledVal = false;

    const uint32_t magic = 0xDEADBEEF;

    while (true) {
        if (magic != 0xDEADBEEF) {
            break;
        }

        if (ledVal) {
            gpio_put(LED_PIN, 1);
        } else {
            gpio_put(LED_PIN, 0);
        }

        ledVal = !ledVal;

        printf("Still running...\n");
        sleep_ms(1000);
    }

    // Control flow faulted via EMFI!!!
    gpio_put(LED_PIN, 1);
    printf("FAULT DETECTED - LED ON\n");

    while (true) {
        tight_loop_contents();
    }
}
