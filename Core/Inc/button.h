/*
 * button.h
 *
 *  Created on: Nov 22, 2022
 *      Author: loing
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();
void key1Process();
void key2Process();
void key3Process();

#endif /* INC_BUTTON_H_ */
