#include "simon_says.h"



void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

void init_stuff()
{
    nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0); 
    const nrfx_uarte_config_t uarte_config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t err = nrfx_uarte_init(&instance, &uarte_config, NULL);
    nrfx_systick_init();

    if (errr != 0){
    }
}

int pattern_handler(int* game_array, int*player_array, int round_counter)
{
    round_counter ++;
    realloc(player_array, round_counter);
    realloc(game_array, round_counter);
    game_array[round_counter] == rand()%4 + 1;
    return round_counter;

}

void button_to_array(int* player_array)
{
    
}

void uarte_handler(nrfx_uarte_event_t const *p_event, void *p_context)
{
    nrfx_uarte_t * p_inst = p_context;
    if (p_event->type == NRFX_UARTE_EVT_RX_DONE)
    {
    //gör något
    }
}