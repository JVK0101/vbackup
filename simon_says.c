#include "simon_says.h"
#include <nrfx_systick.h>
#include <stdio.h>
#include <nrf.h>

nrfx_uarte_t uarte_instance = NRFX_UARTE_INSTANCE(0); 


volatile int player_array[MAX];
volatile int input_index = 0;
volatile int tx_check = 0;
void uarte_write(char* data, int length)
{
    tx_check = 1;
    nrfx_uarte_tx(&uarte_instance, data, length, 0);
    while(tx_check == 1);
}

void send_int(int input_value)
{
    char buffer[30];
    sprintf(buffer, "%d", input_value);
    uarte_write(buffer, strlen(buffer));
}

void init_stuff()
{
    
   
    const nrfx_uarte_config_t uarte_config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t err = nrfx_uarte_init(&uarte_instance, &uarte_config, uarte_handler);
    
   
    nrfx_systick_init();
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2);
    nrf_gpio_cfg_output(LED3);
    nrf_gpio_cfg_output(LED4);

    
    
    nrf_gpio_pin_set(LED1);
    nrf_gpio_pin_set(LED2);
    nrf_gpio_pin_set(LED3);
    nrf_gpio_pin_set(LED4);


   

    if (err != 0){
    }
}

int pattern_handler(int* game_array, int round_counter)
{
   
    game_array[round_counter] = rand()%4 + 1;
    return round_counter + 1;

}

void blink_led(int led_number)
{
    nrf_gpio_pin_clear(led_number);
    nrfx_systick_delay_ms(500);
    nrf_gpio_pin_set(led_number);
    nrfx_systick_delay_ms(500);
}

void blinking_phase(int* game_array, int round_counter)
{
    for (int i = 0; i < round_counter; i++) 
    {
        switch (game_array[i]) 
        {
            case 1: blink_led(LED1); break;
            case 2: blink_led(LED2); break;
            case 3: blink_led(LED3); break;
            case 4: blink_led(LED4); break;
        }
    }
}

void start_counter()
{
    char msg[] = "Game starts in: ";
    uarte_write(msg, strlen(msg));
    send_int(3);
    nrfx_systick_delay_ms(1000);
    send_int(2);
    nrfx_systick_delay_ms(1000);
    send_int(1);
    nrfx_systick_delay_ms(1000);
}

void uarte_handler(nrfx_uarte_event_t const *p_event, void *p_context)
{
    nrfx_uarte_t * p_inst = p_context;
    if (p_event->type == NRFX_UARTE_EVT_RX_DONE)
    {
        tx_check = 1;
        char input = p_event->data.rx.p_data[0];
        switch(input)
        {
            case 'r':
                player_array[input_index] = 1;
                input_index++;
                break;
            case 't':
                player_array[input_index] = 2;
                input_index++;
                break;
            case 'f':
                player_array[input_index] = 3;
                input_index++;
                break;
            case 'g':
                player_array[input_index] = 4;
                input_index++;
                break;
            default:
                break;
        }
        static uint8_t rx_buffer;
        nrfx_uarte_rx(&uarte_instance, &rx_buffer, 1);
    }
if (p_event->type == NRFX_UARTE_EVT_TX_DONE)
    {
        tx_check = 0;
    }
}





