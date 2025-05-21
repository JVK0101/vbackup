#include "simon_says.h"



int main(void) 
{

    

    init_stuff();
    int round_counter = 0;
    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);
    while(nrf_gpio_pin_read(BUTTON1)==1)
    {
    }
    srand(nrfx_rtc_counter_get(&rtc_instance));
    int *game_array = (int *)malloc(1 * sizeof(int));
    int *player_array = (int *)malloc(1 * sizeof(int));
    game_array[0] = rand()%4 + 1;
    
}


 