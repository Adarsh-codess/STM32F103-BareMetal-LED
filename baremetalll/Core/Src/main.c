#include "stm32f1xx.h"

// Simple dummy delay function
void delay(int count) {
    while(count--);
}

int main(){
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

    GPIOA->CRL &=~(0xF<<20);
    GPIOA->CRL |=(0x1<<20);

    GPIOA->CRL &=~(0xF<<24);
    GPIOA->CRL |=(0x1<<24);

    GPIOB->CRL &=~(0xF<<8);
    GPIOB->CRL |=(0x1<<8);

    GPIOB->CRH &=~(0xF<<16);
    GPIOB->CRH |=(0x1<<16);

    while(1){
        GPIOA->ODR &=~((1<<5)|(1<<6));
        GPIOB->ODR &=~((1<<2)|(1<<12));
        GPIOA->ODR ^=(1<<5);
        delay(200000);

        GPIOA->ODR &=~((1<<5)|(1<<6));
        GPIOB->ODR &=~((1<<2)|(1<<12));
        GPIOA->ODR ^=(1<<6);
        delay(200000);

        GPIOA->ODR &=~((1<<5)|(1<<6));
        GPIOB->ODR &=~((1<<2)|(1<<12));
        GPIOB->ODR ^=(1<<2);
        delay(200000);

        GPIOA->ODR &=~((1<<5)|(1<<6));
        GPIOB->ODR &=~((1<<2)|(1<<12));
        GPIOB->ODR ^=(1<<12);
        delay(200000);
    }
}
