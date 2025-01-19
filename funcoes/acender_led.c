void acender_led(uint LED) {
    gpio_put(LED, 1);  // Acende o LED (nível alto)
    printf("LED no pino %u aceso!\n", LED);
}
