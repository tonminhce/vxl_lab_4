/*
 * Light_controller.h
 *
 *  Created on: Nov 26, 2022
 *      Author: phamk
 */

#ifndef INC_LIGHT_CONTROLLER_H_
#define INC_LIGHT_CONTROLLER_H_

#include "stm32f1xx_hal.h"
#include "main.h"

void turnOnRed(void);
void turnOnGreen(void);
void turnOnYellow(void);

void turnOffAll(void);

#endif /* INC_LIGHT_CONTROLLER_H_ */
