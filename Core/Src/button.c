/*
 * button.c
 *
 *  Created on: Nov 22, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "main.h"
#include "button.h"
#include "led.h"


int keyReg0;
int keyReg1;
int keyReg2;
int keyReg3;

void key1Process() {
	led6_toggle();
}

void getKeyInput() {
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(GPIOA, BUTTON_Pin);
	if ( (keyReg0==keyReg1) && (keyReg1==keyReg2) ) {
		if (keyReg3 != keyReg2) {
			keyReg3 = keyReg2;
			if (keyReg2 == PRESSED_STATE)
				key1Process();
		}
	}
}
