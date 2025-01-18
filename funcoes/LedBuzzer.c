#include <stdio.h>
#include "pico/stdlib.h"

#include "PlaySong.c"

#define LED_AZUL 12
#define LED_VERDE 11
#define BUZZER 21

void tecla() { 
    printf("Ligando...\n");
    gpio_put(LED_AZUL, true);  
    gpio_put(LED_VERDE, true); 
    play_note(BUZZER, 262, 1000); 
    sleep_ms(1000); 

    gpio_put(LED_AZUL, false);  
    gpio_put(LED_VERDE, false); 
    gpio_put(BUZZER, false);    
}

