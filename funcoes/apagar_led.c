void apagar_led(uint LED) {
    gpio_put(LED, 0);  // Apaga o LED (nível baixo)
    printf("LED no pino %u apagado!\n", LED);
}
