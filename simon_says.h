#ifndef SIMON_SAYS
#define SIMON_SAYS
#define PIN_TXD 20
#define PIN_RXD 22
#define BUTTON1 23
#define BUTTON2 24
#define BUTTON3 8
#define BUTTON4 9
#define LED1 28
#define LED2 29
#define LED3 30
#define LED4 31
#define CLEAR_SCREEN "\033c"
#include <nrfx.h>
#include <nrf5340_application.h>
#include <nrfx_config.h>
#include <nrf.h>
#include <nrfx_uarte.h>
#include <nrfx_systick.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <nrf_gpio.h>
#include <nrfx_gpiote.h>
#include <app_error.h>


void uarte_write(char* data, int length);

void init_stuff();

int pattern_handler(int* game_array, int round_counter);

int button_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action, int i);

void blinking_phase(int* game_array);

#endif