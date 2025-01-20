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

        // Avaliação de caractere para o LED e Buzzer
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
            buzzer_tone(GPIO_BUZZ, 1000, 261);  // 1000 Hz durante 1 segundo
            printf("Buzzer tocando a nota Dó (261Hz) por 1 segundo\n");
            break;

        // Adicionando novas funções para o controle de LEDs e Buzzer
        case '*':
            // Colocando um efeito de piscar nos LEDs
            for (int i = 0; i < 3; i++)
            {
                gpio_put(GPIO_LED[i], true);
                busy_wait_ms(500);
                gpio_put(GPIO_LED[i], false);
                busy_wait_ms(500);
            }
            printf("Efeito de piscar nos LEDs\n");
            break;

        case '#':
            // Agora, gera um tom no buzzer durante 1 segundo
            buzzer_tone(GPIO_BUZZ, 1000, 1000);  // 1000 Hz durante 1 segundo
            printf("Buzzer tocando a 1000 Hz por 1 segundo\n");
            break;

        case '2':  // Quando a tecla 2 for pressionada
            pino = GPIO_LED[0];
            ligaGPIO(pino);
            pino = GPIO_LED[1];
            ligaGPIO(pino);
            printf("LED Azul e LED Rosa ativados\n");
            break;

        case '3':  // Quando a tecla 2 for pressionada
            pino = GPIO_LED[0];
            ligaGPIO(pino);
            pino = GPIO_LED[1];
            ligaGPIO(pino);
            pino = GPIO_LED[2];
            ligaGPIO(pino);
            printf("LED Azul, LED Rosa e LED Roxo ativados\n");
            break;

        case '4':  // Quando a tecla 2 for pressionada
            pino = GPIO_LED[0];
            ligaGPIO(pino);
            pino = GPIO_LED[2];
            ligaGPIO(pino);
            printf("LED Azul e LED Roxo ativados\n");
            break;

        case '5':  // Quando a tecla 2 for pressionada
            pino = GPIO_LED[1];
            ligaGPIO(pino);
            pino = GPIO_LED[2];
            ligaGPIO(pino);
            printf("LED Rosa e LED Roxo ativados\n");
            break;

        case '6':
            pino = GPIO_LED[0];
            printf("LED Azul exibindo código Morse\n");

            // Sinal Morse: SOS (... --- ...)
            // Três pontos ("...")
            for (int i = 0; i < 3; i++) {
                gpio_put(pino, true);
                busy_wait_ms(200); // Um ponto
                gpio_put(pino, false);
                if (i < 2) {
                    busy_wait_ms(125); // Intervalo entre pontos
                }
            }

            busy_wait_ms(250); // Intervalo entre letras

            // Três traços ("---")
            for (int i = 0; i < 3; i++) {
                gpio_put(pino, true);
                busy_wait_ms(800); // Um traço
                gpio_put(pino, false);
                if (i < 2) {
                    busy_wait_ms(125); // Intervalo entre traços
                }
            }

            busy_wait_ms(250); // Intervalo entre letras

            // Três pontos ("...")
            for (int i = 0; i < 3; i++) {
                gpio_put(pino, true);
                busy_wait_ms(200); // Um ponto
                gpio_put(pino, false);
                if (i < 2) {
                    busy_wait_ms(125); // Intervalo entre pontos
                }
            }

            busy_wait_ms(3000); // Intervalo final antes de reiniciar o ciclo
            break;

        default:
            gpio_put(GPIO_LED[0], false);
            gpio_put(GPIO_LED[1], false);
            gpio_put(GPIO_LED[2], false);
            gpio_put(GPIO_BUZZ, false);
            printf("Todos os LEDs e o Buzzer estão desligados\n");
            break;
        }
    }
}

