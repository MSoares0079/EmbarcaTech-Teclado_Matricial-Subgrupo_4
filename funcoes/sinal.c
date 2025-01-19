#include <stdio.h>
#include "pico/stdlib.h"

#define gap 125    
#define ponto 200  
#define traco 800  
#define letras 250 
                    
                            
void sinal();                                    
void blink_led(uint tempo, uint LED);                     


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

void blink_led(uint tempo, uint LED) {
    gpio_put(LED, true);
    sleep_ms(tempo);
    gpio_put(LED, false);
}