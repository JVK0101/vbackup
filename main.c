#include "simon_says.h"



int main(void) 
{

    

    init_stuff();
    int round_counter = 0;
   
    while(nrf_gpio_pin_read(BUTTON1)==1)
    {
    }
    srand(nrfx_rtc_counter_get(&rtc_instance));

    NVIC_ClearPendingIRQ(GPIOTE_IRQn);
    NVIC_EnableIRQ(GPIOTE_IRQn);

    nrf_gpio_pin_write(LED1, 1);
    nrf_gpio_pin_write(LED2, 1);
    nrf_gpio_pin_write(LED3, 1);
    nrf_gpio_pin_write(LED4, 1);
    int pos_to_check;
    int *game_array = (int *)malloc(1 * sizeof(int));
    int *player_array = (int *)malloc(1 * sizeof(int));
    game_array[0] = rand()%4 + 1;
    for(int i = 0; i < round_counter + 1; i++)
    {
        blinking_phase(game_array, i);
    }
    pos_to_check = 0;
    while(pos_to_check < round_counter + 1)
    {
        

    }

}


 