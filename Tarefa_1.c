#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "features/keyPad4x4.c"
#include "features/LED_Buzz.c"

// define os pinos LED de saída
const uint GPIO_LED[3] = {18, 19, 20};

// define o pino do Buzzer de saída
const uint GPIO_BUZZ = 28;

// define os pinos do teclado com as portas GPIO
const uint columns[4] = {5, 4, 3, 2};
const uint rows[4] = {9, 8, 7, 6};

// mapa de teclas
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

// função principal
int main()
{
    uint pino;
    stdio_init_all();
    menu();
    pico_keypad_init(columns, rows, KEY_MAP);
    initLed(GPIO_LED, GPIO_BUZZ);
    char tecla;

    while (true)
    {
        busy_wait_us(500000);
        tecla = pico_keypad_get_key();

        // Avaliação de caractere para o LED
        switch (tecla)
        {
        case 'A':
            pino = GPIO_LED[0];
            ligaGPIO(pino);
            printf("LED Azul (A) ativado\n");
            break;
        case 'B':
            pino = GPIO_LED[1];
            ligaGPIO(pino);
            printf("LED Rosa (B) ativado\n");
            break;
        case 'C':
            pino = GPIO_LED[2];
            ligaGPIO(pino);
            printf("LED Roxo (C) ativado\n");
            break;
        case 'D':
            pino = GPIO_BUZZ;
            ligaGPIO(pino);
            printf("Buzzer (D) ativado\n");
            break;
        default:
            gpio_put(GPIO_LED[0], false);
            gpio_put(GPIO_LED[1], false);
            gpio_put(GPIO_LED[2], false);
            gpio_put(GPIO_BUZZ, false);
            printf("Todos os LEDs e o Buzzer foram desligados\n");
            break;
        }
    }
}
