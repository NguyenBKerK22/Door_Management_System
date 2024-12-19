/*
 * keypad.c
 *
 *  Created on: Nov 11, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "keypad.h"

//--- Variables ----------------------------------
//- Local Variables ------------------------------
KEY keys[TOTAL_BUTTON];
static GPIO_PinState debounceButtonBuffer1[TOTAL_BUTTON];
static GPIO_PinState debounceButtonBuffer2[TOTAL_BUTTON];
static GPIO_PinState flagForButtonPress[TOTAL_BUTTON];
//static GPIO_PinState flagForButtonPress1s[TOTAL_BUTTON];

//--- Functions Definition -----------------------
//- Local Functions ------------------------------
/*	Function: key_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, char key, KEY* k)
 * 	Return: none
 * 	Purpose: init all key
 */
void key_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, char key, KEY* k)
{
	k->Port = GPIOx;
	k->Pin = GPIO_Pin;
	k->Key = key;
	k->states = BUTTON_STATE_RELEASE;
}

//- Global Functions -----------------------------
/*	Function: init_keypad(void)
 * 	Return: none
 * 	Purpose: init keypad
 */
void keypad_init(void)
{
	key_init(KEY_0_GPIO_Port, KEY_0_Pin, '0', &keys[0]);
	key_init(KEY_1_GPIO_Port, KEY_1_Pin, '1', &keys[1]);
	key_init(KEY_2_GPIO_Port, KEY_2_Pin, '2', &keys[2]);
	key_init(KEY_3_GPIO_Port, KEY_3_Pin, '3', &keys[3]);
	key_init(KEY_4_GPIO_Port, KEY_4_Pin, '4', &keys[4]);
	key_init(KEY_5_GPIO_Port, KEY_5_Pin, '5', &keys[5]);
	key_init(KEY_6_GPIO_Port, KEY_6_Pin, '6', &keys[6]);
	key_init(KEY_7_GPIO_Port, KEY_7_Pin, '7', &keys[7]);
	key_init(KEY_8_GPIO_Port, KEY_8_Pin, '8', &keys[8]);
	key_init(KEY_9_GPIO_Port, KEY_9_Pin, '9', &keys[9]);
	key_init(KEY_DELETE_GPIO_Port, KEY_DELETE_Pin, 'd', &keys[10]);
	key_init(KEY_ENTER_GPIO_Port, KEY_ENTER_Pin, 'e', &keys[11]);
	key_init(KEY_CLOSE_GPIO_Port, KEY_CLOSE_Pin, 'c', &keys[12]);
	flag_press = 0;
	for(unsigned char i = 0; i<TOTAL_BUTTON; ++i)
	{
		debounceButtonBuffer1[i] = 1;
		debounceButtonBuffer2[i] = 1;
		flagForButtonPress[i] = 1;
	}
}

/*	Function: keypad_button_reading(void)
 * 	Return: none
 * 	Purpose: read the input pins, mainly use in interrupt function
 */
void keypad_button_reading(void)
{
	for(uint8_t i = 0; i<TOTAL_BUTTON; ++i)
	{
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(keys[i].Port, keys[i].Pin);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			flagForButtonPress[i] = debounceButtonBuffer1[i];
		}
	}
}

/*	Function: keypad_run(void)
 * 	Return: none
 * 	Purpose: process keypad
 */
char keypad_run(void)
{
	for(uint8_t i = 0; i<TOTAL_BUTTON; ++i)
	{
		button_processing_run(&(keys[i].states), i);
		if(flag_press == 1)
		{
			//TODO
#ifdef TESTING
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
#else
			return keys[i].Key;
#endif
		}
	}
	return '\0';
}

unsigned char keypad_is_button_pressed(unsigned char index)
{
	if(index >= TOTAL_BUTTON) return 0;
	return (flagForButtonPress[index] == BUTTON_STATUS_PRESSED);
}



