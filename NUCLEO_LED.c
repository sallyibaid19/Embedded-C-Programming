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

/*
 * To Write a Program to turn on LED
 *  RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) GPIOA
 * AHB1 peripheral clock enable register (RCC_AHB1ENR) 0x4002 3800 Address offset: 0x30
 * Reset value: 0x0010 0000
 * GPIO port mode register (GPIOX MODER) (x = A..I/ OUTPUT
 * GPIO port output data register (GPIOX_ODR) (x = A..I/PIN 5/1
 *
 * */
#include <stdint.h>


int main(void)
{
	// RCC  Base Address = 0x4002 3800 Address offset: 0x30 [0x4002 3800 + 0x30 =  0x40023830]
	uint32_t *AHB1ENR = (uint32_t*)0x40023830;

	// Base Address = 0x40020000
	uint32_t *MODER   = (uint32_t*)0x40020000;

	// Base Address = 0x40020000 >> Address offset: 0x14  [0x4002 0000 + 0x14 =  0x40020014]
	uint32_t *ODR     = (uint32_t*)0x40020014;

	*AHB1ENR |= 0x01;
	*MODER &=0xFFFFF3FF;
	*MODER |=0x00000400;
	*ODR |= 0x20;

	for(;;);
}