#ifndef SIMON_SAYS
#define SIMON_SAYS
#define PIN_TXD 20
#define PIN_RXD 22
#define BUTTON1 23
#define BUTTON2 24
#define BUTTON3 8
#define BUTTON4 9
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

void uarte_write(char* data, int length);

void init_stuff();

int pattern_handler(int* game_array, int round_counter);

void uarte_handler(nrfx_uarte_event_t const *p_event, void *p_context);
#endif