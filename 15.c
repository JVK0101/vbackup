#include <15.h>
#include <nrfx.h>
#include <nrf5340_application.h>
#include <nrfx_config.h>
#include <nrf.h>
#include <nrfx_uarte.h>
#include <nrfx_rtc.h>
#include <nrfx_systick.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <nrf_gpio.h>


nrfx_rtc_t rtc_instance = NRFX_RTC_INSTANCE(0);
nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0); 
char uarte_buffer;

void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

void read_string(char input_string[20])
{
    char input_char;
    int i = 0;
    while(i < 20)
    {
        nrfx_uarte_rx (&instance, &input_char, sizeof(input_char));
        if (input_char != '\r' && i != 19)
        {
            input_string[i] = input_char;
            i++;
        }
        else
        {    
            input_string[i] ='\0';
            i = 20;
        }
    }
} 

void send_int(int input_value)
{
    char buffer[30];
    sprintf(buffer, "%d", input_value);
    uarte_write(buffer, strlen(buffer));
}

int read_int()
{
    char buffer[20];
    read_string(buffer);
    return atoi(buffer);
}

void init_stuff()
{
    nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0); 
    const nrfx_uarte_config_t uarte_config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t err = nrfx_uarte_init(&instance, &uarte_config, NULL);
    nrfx_rtc_config_t rtc_config = NRFX_RTC_DEFAULT_CONFIG;
    nrfx_err_t errr = nrfx_rtc_init(&rtc_instance, &rtc_config, NULL);
    nrfx_rtc_enable(&rtc_instance);
    nrfx_systick_init();

    if (errr != 0){
    }
}