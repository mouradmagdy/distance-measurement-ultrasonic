/*
 * ultrasound.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Mourad
 */

#include"ultrasound.h"
#include"icu.h"
#include"gpio.h"
#include<util/delay.h>

uint8 g_edges=0;
uint16 total_time=0;

void Ultrasonic_init(void){
	ICU_ConfigType icu_config={F_CPU_8,RAISING};
	ICU_init(&icu_config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(12);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	uint16 distance;

	while(g_edges==0||g_edges==1||g_edges==2){
		if(g_edges==2){
			g_edges=0;
			break;
		}
	}
	distance=1+(total_time/58);
	return distance;

}

void Ultrasonic_edgeProcessing(void){
	g_edges++;
	if(g_edges==1){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edges==2){
		total_time=ICU_getInputCaptureValue();

		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);


	}

}

