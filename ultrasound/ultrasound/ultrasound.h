/*
 * ultrasound.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Mourad
 */

#ifndef ULTRASOUND_H_
#define ULTRASOUND_H_

#include"std_types.h"
#include"common_macros.h"


#define TRIGGER_PORT_ID PORTB_ID
#define TRIGGER_PIN_ID  PIN5_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASOUND_H_ */
