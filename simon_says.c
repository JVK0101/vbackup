#include "simon_says.h"



void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

void init_stuff()
{
    nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0); 
    const nrfx_uarte_config_t uarte_config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t err = nrfx_uarte_init(&instance, &uarte_config, uarte_handler);
    nrfx_systick_init();
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2);
    nrf_gpio_cfg_output(LED3);
    nrf_gpio_cfg_output(LED4);
    
    nrfx_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
    config.pull = NRF_GPIO_PIN_PULLUP;

    nrfx_gpiote_in_init(BUTTON1, &config, button_handler);
    nrfx_gpiote_in_event_enable(BUTTON1, true);
    nrfx_gpiote_in_init(BUTTON2, &config, button_handler);
    nrfx_gpiote_in_event_enable(BUTTON2, true);
    nrfx_gpiote_in_init(BUTTON3, &config, button_handler);
    nrfx_gpiote_in_event_enable(BUTTON3, true);
    nrfx_gpiote_in_init(BUTTON4, &config, button_handler);
    nrfx_gpiote_in_event_enable(BUTTON4, true);

   

    if (errr != 0){
    }
}

int pattern_handler(int* game_array, int*player_array, int round_counter)
{
    round_counter ++;
    realloc(player_array, round_counter + 1);
    realloc(game_array, round_counter + 1);
    game_array[round_counter] = rand()%4 + 1;
    return round_counter;

}


void blinking_phase(int* game_array, int i)
{
    if(game_array[i] == 1)
    {
        nrf_gpio_pin_write(LED1, 0);
        nrfx_systick_delay_ms(500);
        nrf_gpio_pin_write(LED1, 1);
    }
    if(game_array[i] == 2)
    {
        nrf_gpio_pin_write(LED2, 0);
        nrfx_systick_delay_ms(500);
        nrf_gpio_pin_write(LED2, 1);
    }
    if(game_array[i] == 3)
    {
        nrf_gpio_pin_write(LED3, 0);
        nrfx_systick_delay_ms(500);
        nrf_gpio_pin_write(LED3, 1);
    }
    if(game_array[i] == 4)
    {
        nrf_gpio_pin_write(LED4, 0);
        nrfx_systick_delay_ms(500);
        nrf_gpio_pin_write(LED4, 1);
    }


}

int button_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action, int i)
{
    switch (pin)
    {
        case BUTTON1:
            player_array[i] = 1;
            i++;
            break;

        case BUTTON2:
            player_array[i] = 2;
            i++;
            break;

        case BUTTON3:
            player_array[i] = 3;
            i++;
            break;

        case BUTTON4:
            player_array[i] = 4;
            i++;
            break;

        default:
            break;
    }
}