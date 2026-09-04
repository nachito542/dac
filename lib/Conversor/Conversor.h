#ifndef CONVERSOR_H
#define CONVERSOR_H
#include "stdint.h"
#include "stm32f103xb.h"


void adc_init();
uint16_t adc_read(unsigned int canal);



#endif