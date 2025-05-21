#include <15.c>
#include <list.h>
#define BUTTON1 23




int main(void) 
{

    //Uppgift 1: is_sorted

    init_stuff();
    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);
    while(nrf_gpio_pin_read(BUTTON1)==1)
    {
    }
    srand(nrfx_rtc_counter_get(&rtc_instance));
    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		
		arr[i] = rand()%10 + 1;
        
	}

    List list = create_empty_list();
    for(int i = 0; i < LIST_SIZE; i++)
	{
		add_last(&list, rand()%10 + 1);

	}
  
//*********************************************************************************************** */

   // Uppgift 2: Bubblesort
    
    /*print_list(list);
    bubblesort(&list);
    print_list(list);

//*********************************************************************************************** */

   // Uppgift 3: QuickSort
    /*for(int i = 0; i < ARRAY_SIZE; i++)
    {
        send_int(arr[i]);
    }
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        send_int(arr[i]);
    }

//*********************************************************************************************** */

    //uppgift 4: MergeSort



    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        send_int(arr[i]);
    }
    merge_sort(arr, 0, ARRAY_SIZE - 1);
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        send_int(arr[i]);
    }
}
 
void uarte_handler(nrfx_uarte_event_t const *p_event, void *p_context)
{
    nrfx_uarte_t * p_inst = p_context;
    if (p_event->type == NRFX_UARTE_EVT_RX_DONE)
    {
    //gör något
    }
}