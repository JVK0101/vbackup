#ifndef GRUPP_15_H
#define GRUPP_15_H
#define PIN_TXD 20
#define PIN_RXD 22


void uarte_write(char* data, int length);
void read_string(char input_string[20]);
int read_int();
void send_int(int input_value);

#endif