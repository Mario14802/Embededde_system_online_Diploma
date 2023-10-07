/*
 * Stm32f103x6.h
 *
 *  Created on: Aug 24, 2023
 *      Author: MARIO
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include  "stdlib.h"
#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASG_MEMORY_BASE 			0x08000000UL
#define SYSTEM_MEMORY_BASE		 	0x1FFFF000UL
#define SRAM_MEMORY_BASE 			0x20000000UL

#define Peripherals_BASE 			0x40000000UL

#define cortex_m3_Peripherals_BASE 	0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
//RCC
#define RCC_BASE					0x40021000UL
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIO
//A,B FULLY included LQFP48
#define GPIOA_BASE					0x40010800UL
#define GPIOB_BASE					0x40010C00UL

//C,D PARTIAL FULLY included LQFP48
#define GPIOC_BASE					0x40011000UL
#define GPIOD_BASE					0x40011400UL

//E, NOT included LQFP48
#define GPIOE_BASE					0x40011800UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Type_Def;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWEIR;
	volatile uint32_t PR;

}EXTI_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESREVED;
	volatile uint32_t MAPR2;

}AFIO_TypeDef;




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   (((GPIO_Type_Def *) GPIOA_BASE))
#define GPIOB   (((GPIO_Type_Def *) GPIOB_BASE))
#define GPIOC   (((GPIO_Type_Def *) GPIOC_BASE))
#define GPIOD   (((GPIO_Type_Def *) GPIOD_BASE))
#define GPIOE   (((GPIO_Type_Def *) GPIOE_BASE))

#define RCC     (((RCC_TypeDef *) RCC_BASE))

#define EXTI    (((EXTI_TypeDef *) EXTI_BASE))

#define AFIO   	(((AFIO_TypeDef *) AFIO_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()   (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()   (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()   (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()   (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()   (RCC->APB2ENR |= 1<<6)

#define AFIO_GPIO_CLK_EN()   (RCC->APB2ENR |= 1<<0)
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32F103X6_H_ */