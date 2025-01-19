#include <stdio.h>
#include "pico/stdlib.h"

// Defina os pinos conectados às linhas e colunas do teclado
#define ROWS 4
#define COLS 4
uint8_t row_pins[ROWS] = {2, 3, 4, 5};  // Pinos para as linhas
uint8_t col_pins[COLS] = {6, 7, 8, 9};  // Pinos para as colunas

// Definição do LED
#define LED_PIN 10  // Pino conectado ao LED

// Mapeamento das teclas
char keypad[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Protótipos das funções
void init_keypad();
char scan_keypad();
void execute_function(char key);
void apagar_led(); // Função específica para apagar o LED

int main() {
    // Inicializa o teclado e o LED
    init_keypad();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);  // Liga o LED inicialmente

    // Loop principal
    while (1) {
        char key = scan_keypad();
        if (key) {
            printf("Tecla pressionada: %c\n", key);
            execute_function(key);
        }

        sleep_ms(100);  // Pequeno atraso para evitar múltiplas leituras
    }

    return 0;
}

// Inicializa o teclado configurando os pinos
void init_keypad() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1);  // Linhas começam em nível alto
    }
    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);  // Ativa resistor pull-down
    }
}

// Escaneia o teclado matricial
char scan_keypad() {
    for (int row = 0; row < ROWS; row++) {
        // Coloca a linha atual em nível baixo
        gpio_put(row_pins[row], 0);

        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col])) {  // Detecta tecla pressionada
                gpio_put(row_pins[row], 1);  // Restaura o nível da linha
                return keypad[row][col];     // Retorna a tecla correspondente
            }
        }

        gpio_put(row_pins[row], 1);  // Restaura o nível da linha
    }
    return 0;  // Nenhuma tecla pressionada
}

// Executa a função associada à tecla pressionada
void execute_function(char key) {
    if (key == '6') {
        apagar_led(); // Tecla 3 apaga o LED
    } else {
        printf("Nenhuma função atribuída para a tecla %c\n", key);
    }
}

// Função específica para apagar o LED
void apagar_led() {
    gpio_put(LED_PIN, 0);  // Apaga o LED (nível baixo)
    printf("LED apagado!\n");
}
