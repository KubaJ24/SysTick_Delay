/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "main.h"

uint32_t Tick;

void SysTick_Handler(void){
	//INCREASE SYSTEM TIMER
	Tick++;
}

void DELAY(uint32_t Delay_ms){
    uint32_t StartTime = Tick;
    while(Tick < (StartTime + Delay_ms))
    {
        // Just wait
    }
}

int main(void)
{

	LD2_OFF;
	LD2_GPIO_CONF();

	SysTick_Config(16000000/1000);

	while(1){
		LD2_ON;
		DELAY(500);

		LD2_OFF;
		DELAY(500);
	}
}
