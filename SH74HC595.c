/*
 * SH74HC595.c
 *
 *  Created on: Sep 6, 2022
 *      Author: neo-a
 */
#include "SH74HC595.h"
extern SPI_HandleTypeDef hspi1;
uint8_t i=0;

uint8_t Symbol[16] = {
		0b00111111,  //0
		0b00000110,  //1
		0b01011011,  //2
		0b01001111,  //3
		0b01100110,  //4
		0b01101101,  //5
		0b01111101,  //6
		0b00000111,  //7
		0b01111111,  //8
		0b01101111,  //9
		0b01110111,  //A
		0b01111100,  //b
		0b00111001,  //C
		0b01011110,  //d
		0b01111001,  //E
		0b01110001   //F
};

void Init()
{
	HAL_SPI_Transmit(&hspi1, &Symbol[0], 1, 100);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
  	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
  	HAL_Delay(50);
}

void Forward()
{
	if(i>15)
	{
		i=0;
	}
	HAL_SPI_Transmit(&hspi1, &Symbol[i], 1, 100);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
}

void Backward()
{

	HAL_SPI_Transmit(&hspi1, &Symbol[i], 1, 100);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
}

void Reset()
{
	i=0;
	HAL_SPI_Transmit(&hspi1, &Symbol[i], 1, 100);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
}




