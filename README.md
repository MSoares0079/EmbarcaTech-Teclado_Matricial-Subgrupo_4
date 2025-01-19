# Teclado Matricial
Este projeto tem como objetivo mostrar as aplicações de um teclado matricial em uma placa Raspberry Pi Pico W.

# Como executar o código
    1-Baixar ou utilizar git clone no repositório.
          git clone https://github.com/MSoares0079/EmbarcaTech-Teclado_Matricial-Subgrupo_4.git
    2-Ter o VS Code instalado e configurado.
    3-Ter a extensão do Raspberry Pi Pico instalada.
    4-Compilar o arquivo "Teclado_Matricial.c" utilizando o compilador do Raspberry Pi Pico.
    5-Rodar o código um Raspberry ou utilizar o "diagram.json" através da extensão do Wokwi.

# Estrutura do código

O código se baseia em ler as entradas do teclado matricial, dependendo da tecla que for apertado o programa produzirá uma ação correspondente através do acionamento de LEDs e um Buzzer.

# Funções das teclas
    1-Leds piscam no formato de uma soma binária.
    2-Buzzer toca a nota Dó e acendem os LEDs azul e vermelho.
    3-Buzzer toca a nota Dó.
    4-Buzzer toca a nota Ré.
    5-Buzzer toca a nota Mi.
    6-Buzzer toca a nota Fá.
    7-Buzzer toca a nota Sol.
    8-Buzzer toca a nota Lá.
    9-Buzzer toca a nota Si.
    *-Apaga todos os LEDs.
    0-Não foi atribuida função para esta tecla.
    #-Envia sinal de SOS no LED vermelho.
    A-Aciona o LED verde.
    B-Aciona o LED azul.
    C-Aciona o LED vermelho.
    D-Toca a sequência de notas:
        Dó,Ré,Mi,Fá,Sol,Lá,Si,Dó.
# Link de um vídeo demonstrando o funcionamento:
  https://drive.google.com/file/d/1TDwqGezPDho5oiTkd0DH3ipIT84SG3gU/view?usp=drive_link
