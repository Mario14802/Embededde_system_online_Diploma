/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Stm32_GPIO_driver.h"
#include "Stm32f103x6.h"

void clock_init()
{
	RCC_GPIOA_CLK_EN();

	RCC_GPIOB_CLK_EN();
}

void GPIO_init()
{

	GPIO_PinConfig PinCfg;
	PinCfg.GPIO_PinNumber=GPIO_PIN_1;
	PinCfg.GPIO_MODE=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_init(GPIOA,&PinCfg);


	PinCfg.GPIO_PinNumber=GPIO_PIN_1;
	PinCfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB,&PinCfg);

	PinCfg.GPIO_PinNumber=GPIO_PIN_13;
	PinCfg.GPIO_MODE=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_init(GPIOA,&PinCfg);


	PinCfg.GPIO_PinNumber=GPIO_PIN_13;
	PinCfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB,&PinCfg);


}

void wait  (uint32_t time)
{
	int i ,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<255;j++);
	}

}

int main(void)
{
	while(1)
	{


		if(MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_1)== 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_1)== 0);

		}
		if(MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_13)== 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

wait(1);

	}
}