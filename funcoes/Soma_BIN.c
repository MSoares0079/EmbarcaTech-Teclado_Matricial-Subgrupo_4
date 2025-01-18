#include <stdio.h>
#include "pico/stdlib.h"

void piscaBin_led(int led_verde, int led_azul, int led_vermelho) {
    gpio_put(led_verde, 1);
    sleep_ms(400);
    gpio_put(led_azul, 1);
    gpio_put(led_verde, 0);
    sleep_ms(400);
    gpio_put(led_verde, 1);
    sleep_ms(400);
    gpio_put(led_azul, 0);
    gpio_put(led_verde, 0);
    gpio_put(led_vermelho, 1);
    sleep_ms(400);
    gpio_put(led_verde, 1);
    sleep_ms(400);
    gpio_put(led_azul, 1);
    gpio_put(led_verde, 0);
    sleep_ms(400);
    gpio_put(led_verde, 1);
    sleep_ms(400);
    gpio_put(led_vermelho, 0);
    gpio_put(led_azul, 0);
    gpio_put(led_verde, 0);
}