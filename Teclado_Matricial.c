#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "funcoes/Soma_BIN.c"
#include "funcoes/PlaySong.c"

#define ROWS 4  // Número de linhas
#define COLS 4  // Número de colunas
#define NUN_PERIFERICOS 4// Número de perifericos
#define LED_VERDE 11 // Pino do Led verde
#define LED_AZUL 12 // Pino do Led azul
#define LED_VERMELHO 13 // Pino do Led vermelho
#define BUZZER 21// Pino do Buzzer

// Define os GPIOs para as linhas e colunas do teclado matricial
uint cols[ROWS] = {4, 3, 2, 1};  // Pinos GPIO das linhas
uint rows[COLS] = {8,7,6,5};  // Pinos GPIO das colunas
//Define os GPIOs para os dispositivos de saída
uint Saidas[NUN_PERIFERICOS] = {LED_VERDE,LED_AZUL,LED_VERMELHO,BUZZER};//Pinos de saída
// Mapeamento das teclas
char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


// Função que escaneia o teclado e retorna a tecla pressionada
char scan_keypad() {
    for (int i = 0; i < ROWS; i++) {
        gpio_put(rows[i], 0);  // Coloca a linha em nível baixo

        for (int j = 0; j < COLS; j++) {
            if (gpio_get(cols[j]) == 0) {  // Verifica se a coluna está em nível baixo
                while (gpio_get(cols[j]) == 0);  // Aguarda até a tecla ser solta
                gpio_put(rows[i], 1);  // Restaura a linha para nível alto
                return key_map[i][j];  // Retorna a tecla correspondente
            }
        }
        gpio_put(rows[i], 1);  // Restaura a linha para nível alto
    }
    return '\0';  // Retorna nulo se nenhuma tecla foi pressionada
}

int main() {
    stdio_init_all();
    for (int i = 0; i < ROWS; i++) {
        gpio_init(rows[i]);//Inicializa a GPIO das linhas
        gpio_set_dir(rows[i], GPIO_OUT);//Define como saída
        gpio_put(rows[i], 1);  // Mantém as linhas em nível alto
    }
    for (int j = 0; j < COLS; j++) {
        gpio_init(cols[j]);//Inicializa a GPIO das colunas
        gpio_set_dir(cols[j], GPIO_IN);//Define como entrada
        gpio_pull_up(cols[j]);  // Ativa resistor pull-up nas colunas
    }
    for( int i =0;i<NUN_PERIFERICOS;i++){
        gpio_init(Saidas[i]);
        gpio_set_dir(Saidas[i], GPIO_OUT);
    }
    printf("Pressione uma tecla...\n");
    while (1) {
        char key = scan_keypad();  // Verifica o teclado
        if (key != '\0') {         // Se uma tecla foi pressionada
            printf("A tecla pressionada foi: %c\n", key);
            if(key == 'A'){
               gpio_put(LED_VERDE,true);
               printf("Led verde aceso\n");
            }
            else if(key == 'D'){
              play_note(BUZZER, 440,1000);//Toca a nota A4(440 Hz) por 1s
              printf("Buzzer tocando a nota Lá(440Hz) por 1s\n");
            } else if (key == '1') {
                piscaBin_led(LED_VERDE, LED_AZUL, LED_VERMELHO);
                printf("Leds piscando no formato de soma binaria\n");
            } else if (key == '2'){
                play_note(BUZZER, 262, 1000);
                gpio_put(LED_VERMELHO, true);
                gpio_put(LED_AZUL, true);
                printf("Buzzer tocando a nota Dó e leds azul e vermelho ligados");
            }

            else if (key == '0') {
                printf("Tocando a sequência: Dó, Ré, Mi, Fá, Sol, Lá, Si, Dó\n");
                play_song(BUZZER); 
            }else{
                printf("Nenhuma funcionalidade foi atribuida a essa tecla\n");
               }
            } 
        
        sleep_ms(100);
    }
    return 0;
}
