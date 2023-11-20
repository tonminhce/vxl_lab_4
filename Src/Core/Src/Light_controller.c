/*
 * Light_controller.c
 *
 *  Created on: Nov 26, 2022
 *      Author: phamk
 */

#include "Light_controller.h"

GPIO_TypeDef * LED_PORT[3] = {
		RED_GPIO_Port,
		GREEN_GPIO_Port,
		YELLOW_GPIO_Port
};

uint16_t LED_PIN[3] = {
		RED_Pin,
		GREEN_Pin,
		YELLOW_Pin
};

void turnOnRed(void){}

void turnOnGreen(void){}

void turnOnYellow(void){}

void turnOffAll(void){
	HAL_GPIO_WritePin(LED_PORT[RED_INDEX], LED_PIN[RED_INDEX], 1);
	HAL_GPIO_WritePin(LED_PORT[GREEN_INDEX], LED_PIN[GREEN_INDEX], 1);
	HAL_GPIO_WritePin(LED_PORT[YELLOW_INDEX], LED_PIN[YELLOW_INDEX], 1);
}
