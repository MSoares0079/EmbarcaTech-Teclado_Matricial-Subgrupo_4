#include <stdio.h>
#include "pico/stdlib.h"

int LED_PIN 13 

#define gap 125    
#define ponto 200  
#define traco 800  
#define letras 250 
                    
                            
void sinal();                                    
void blink_led(uint tempo);                     


void sinal() {
    blink_led(ponto);
    sleep_ms(gap);
    blink_led(ponto);
    sleep_ms(gap);
    blink_led(ponto);
    sleep_ms(letras);

    blink_led(traco);
    sleep_ms(gap);
    blink_led(traco);
    sleep_ms(gap);
    blink_led(traco);
    sleep_ms(letras);

    blink_led(ponto);
    sleep_ms(gap);
    blink_led(ponto);
    sleep_ms(gap);
    blink_led(ponto);

    sleep_ms(500);
}

void blink_led(uint tempo) {
    gpio_put(LED_PIN, true);
    sleep_ms(tempo);
    gpio_put(LED_PIN, false);
}