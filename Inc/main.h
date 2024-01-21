/*
 * main.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ahadz
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include "stm32f746xx.h"

#define LD2_ON GPIOB->BSRR |= GPIO_BSRR_BS7;
#define LD2_OFF GPIOB->BSRR |= GPIO_BSRR_BR7;

void LD2_GPIO_CONF(void);
//void DELAY(uint32_t Delay_ms);

void LD2_GPIO_CONF(void){
	//GPIO PORT B CLOCK ENABLE
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	//OUTPUT
	GPIOB->MODER |= GPIO_MODER_MODER7_0;
	GPIOB->MODER &= ~(GPIO_MODER_MODER7_1);
	//OUTPUT TYPE - PUSH PULL
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT7);
	//OUTPUT SPEED VERY LOW
	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEEDR7);
	//NO PULL UP, NO PULL DOWN
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR7);
}

/*void DELAY(uint32_t Delay_ms){
    uint32_t StartTime = Tick;
    while(Tick < (StartTime + Delay_ms))
    {
        // Just wait
    }
}*/

#endif /* MAIN_H_ */
