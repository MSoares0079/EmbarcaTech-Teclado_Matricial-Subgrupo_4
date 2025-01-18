#include <stdio.h>
#include "pico/stdlib.h"



void play_note(int buzzer, int frequency, int duration) {
    if (frequency == 0) {
        sleep_ms(duration);  // Pausa (silêncio)
        return;
    }

    int delay = 1000000 / frequency / 2; // Meio ciclo da frequência
    int cycles = (frequency * duration) / 1000;

    for (int i = 0; i < cycles; i++) {
        gpio_put(buzzer, 1);
        sleep_us(delay);
        gpio_put(buzzer, 0);
        sleep_us(delay);
    }
}

void play_song(uint pin) {
    // Frequências das notas musicais
    int notes[] = {262, 294, 330, 349, 392, 440, 494, 523}; // Dó, Ré, Mi, Fá, Sol, Lá, Si, Dó
    int duration = 500; // Duração de cada nota em milissegundos

    for (int i = 0; i < 8; i++) {
        play_note(pin, notes[i], duration);
        sleep_ms(100); // Pequena pausa entre as notas
    }
}