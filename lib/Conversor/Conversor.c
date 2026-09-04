#include "Conversor.h"


void init(){
    int A[8]={0,1,2,3,4,5,6,7};
    int B[2]={0,1};
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPBEN|RCC_APB2ENR_ADC1EN;
 ADC1->CR2|= ADC_CR2_ADON;
for(int i=0;i<1000;i++);
    ADC1->CR2|= ADC_CR2_RSTCAL;
    while(ADC1->CR2 & ADC_CR2_RSTCAL);
    ADC1->CR2|= ADC_CR2_CAL;
    while(ADC1->CR2 & ADC_CR2_CAL);

ADC1->CR2|= ADC_CR2_EXTTRIG;
ADC1->CR2|= ADC_CR2_EXTSEL;

    for(int i=0;i<7;i++){
        GPIOA->CRL&=~(0XF<<A[i]*4);
        GPIOA->BSRR|=(0X0<<A[i]*4);
        if(i>5){
            GPIOB->CRL&=~(0XF<<B[i]*4);
            GPIOB->BSRR|=(0X0<<B[i]*4);
        }
    }
    
}


uint16_t adc_read(unsigned int canal, unsigned int v_ref){
    int canal;
 ADC1->SMPR2|=(0b111<<(canal * 3));
 ADC1 ->SQR3 |= (canal);
    int V_ref= (ADC1->DR/4095)* 3.3;
    ADC1->SR |=ADC_SR_EOC;
    while (!(ADC1->SR &ADC_SR_EOC))
    {
        return ADC1->DR;
        
    }
    
   


}