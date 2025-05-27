#ifndef SIMON_SAYS_H
#define SIMON_SAYS_H
#define PIN_TXD 20
#define PIN_RXD 22
#define LED1 28
#define LED2 29
#define LED3 30
#define LED4 31
#define MAX 100
#include <nrf5340_application.h>
#include <nrfx_config.h>
#include <nrfx_uarte.h>
#include <stdlib.h>
#include <string.h>
#include <nrf_gpio.h>




extern nrfx_uarte_t uarte_instance;
extern volatile int player_array[MAX];
extern volatile int input_index;


void uarte_write(char* data, int length);

void send_int(int input_value);

void start_counter();

void init_stuff();

int pattern_handler(int* game_array, int round_counter);

void blink_led(int led_number);

void uarte_handler(nrfx_uarte_event_t const *p_event, void *p_context);

void blinking_phase(int* game_array, int round_counter);

#endif




