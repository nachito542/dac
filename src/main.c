#include "stm32f103xb.h"
#include "Conversor.h"


int pin=0;
int led=5;
int est;

int main(){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    GPIOA->CRL&=~(0XF<<led*4);
    GPIOA->BSRR|=(0X1<<led*4);
    
    adc_init(pin);
    while(1){
        if( est = adc_read(pin)>2048){
            GPIOA->BSRR|=(1<<led*4);
        };
    };

}

