#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "funcoes/Soma_BIN.c"
#include "funcoes/PlaySong.c"
#include "funcoes/sinal.c"
#include "funcoes/apagar_led.c"

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
            }else if(key == 'B'){
                gpio_put(LED_AZUL,true);
                printf("Led azul aceso\n");
            }else if(key == 'C'){
                gpio_put(LED_VERMELHO,true);
                printf("Led vermelho aceso\n");
            }else if (key == 'D') {
                printf("Tocando a sequência: Dó, Ré, Mi, Fá, Sol, Lá, Si, Dó\n");
                play_song(BUZZER); 
            }else if (key == '1') {
                printf("Leds piscando no formato de soma binaria\n");
                piscaBin_led(LED_VERDE, LED_AZUL, LED_VERMELHO); 
            } else if (key == '2'){
                play_note(BUZZER, 262, 1000);
                gpio_put(LED_VERMELHO, true);
                gpio_put(LED_AZUL, true);
                printf("Buzzer tocando a nota Dó e leds azul e vermelho ligados");
            }else if(key == '3'){
              play_note(BUZZER, 262,1000);//Toca a nota Dó
              printf("Buzzer tocando a nota Dó(262Hz) por 1s\n");
            }else if(key == '4'){
              play_note(BUZZER, 294,1000);//Toca a nota Ré
              printf("Buzzer tocando a nota Ré(294Hz) por 1s\n");
            }else if(key == '5'){
              play_note(BUZZER, 330,1000);//Toca a nota Mi
              printf("Buzzer tocando a nota Mi(330Hz) por 1s\n");
            }else if(key == '6'){
              play_note(BUZZER, 349,1000);//Toca a nota Fá
              printf("Buzzer tocando a nota Fá(349Hz) por 1s\n");
            }else if(key == '7'){
              play_note(BUZZER, 392,1000);//Toca a nota Sol
              printf("Buzzer tocando a nota Sol(349Hz) por 1s\n");
            }else if(key == '8'){
              play_note(BUZZER, 440,1000);//Toca a nota Lá
              printf("Buzzer tocando a nota Lá(440Hz) por 1s\n");
            }else if(key == '9'){
              play_note(BUZZER, 494,1000);//Toca a nota Si
              printf("Buzzer tocando a nota Si(494Hz) por 1s\n");
            }   
             else if (key == '#'){
                printf("Enviando código SOS...\n");
                sinal(LED_VERMELHO);
            }else if(key == '*'){
                apagar_led(LED_VERDE);
                apagar_led(LED_VERMELHO);
                apagar_led(LED_AZUL);
            }else{
                printf("Nenhuma funcionalidade foi atribuida a essa tecla\n");
               }
            } 
        sleep_ms(100);
    }
    return 0;
}


