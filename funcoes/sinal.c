#include <stdio.h>
#include "pico/stdlib.h"

#define gap 125    
#define ponto 200  
#define traco 800  
#define letras 250 
                                     
void sinal(uint32_t LED);                                    
void blink_led(uint32_t tempo, uint32_t LED);                     

void sinal(uint32_t LED) {

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);


    blink_led(ponto, LED);
    sleep_ms(gap);
    blink_led(ponto, LED);
    sleep_ms(gap);
    blink_led(ponto, LED);
    sleep_ms(letras);

    blink_led(traco, LED);
    sleep_ms(gap);
    blink_led(traco, LED);
    sleep_ms(gap);
    blink_led(traco, LED);
    sleep_ms(letras);

    blink_led(ponto, LED);
    sleep_ms(gap);
    blink_led(ponto, LED);
    sleep_ms(gap);
    blink_led(ponto, LED);

    sleep_ms(500);
}

void blink_led(uint32_t tempo, uint32_t LED) {
    gpio_put(LED, true);
    sleep_ms(tempo);
    gpio_put(LED, false);
}

