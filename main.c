#include "simon_says.h"




int main(void) 
{


    init_stuff();
    

    static uint8_t rx_buffer;
    nrfx_uarte_rx(&uarte_instance, &rx_buffer, 1);
 
    

    
    
    srand(2);
    NVIC_ClearPendingIRQ(NRFX_IRQ_NUMBER_GET(NRF_UARTE_INST_GET(0)));
    NVIC_EnableIRQ(NRFX_IRQ_NUMBER_GET(NRF_UARTE_INST_GET(0)));
    int game_array[MAX];
    int round_counter = 0;

    char win_msg[] = "Correct!";
    char lose_msg[] = "Wrong! Rounds completed:";
    
    
    start_counter();
    while(1)
    {
        input_index = 0;
        round_counter = pattern_handler(game_array, round_counter);
        blinking_phase(game_array, round_counter);

       

        while(input_index < round_counter);

        for(int i = 0; i < round_counter; i++)
        {
            if(player_array[i] != game_array[i])
            {
                uarte_write(lose_msg, strlen(lose_msg));
                send_int(round_counter - 1);
                round_counter = 0;
                start_counter();
                break;
            }
            else if(i == round_counter - 1 && game_array[i] == player_array[i])
            {
            
                uarte_write(win_msg, strlen(win_msg));
            
            }
        }
        
        
    }
   
   
   
 

}



