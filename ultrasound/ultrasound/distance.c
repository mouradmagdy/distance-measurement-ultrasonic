/*
 * distance.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Mourad
 */

#include"ultrasound.h"
#include"lcd.h"
#include"icu.h"
#include<avr/io.h>

int main(){
	SREG|=(1<<7);
	LCD_init();
	Ultrasonic_init();
	uint16 distance=0;
	LCD_displayString("Distance=    cm");
	while(1){
		LCD_moveCursor(0,9);
		distance=Ultrasonic_readDistance();
		if(distance<100){
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		else{
			LCD_intgerToString(distance);
		}
	}

}
