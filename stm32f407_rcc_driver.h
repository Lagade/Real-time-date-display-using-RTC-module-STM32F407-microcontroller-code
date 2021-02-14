/*
 * stm32f407_rcc_driver.h
 *
 *  Created on: 01-Feb-2021
 *      Author: Shubham
 */

#ifndef INC_STM32F407_RCC_DRIVER_H_
#define INC_STM32F407_RCC_DRIVER_H_

#include "stm32f407.h"

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);

uint32_t RCC_GetPLLOutputClk(void);


#endif /* INC_STM32F407_RCC_DRIVER_H_ */
