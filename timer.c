/*
 * timer.c
 *
 *  Created on: ١٥‏/٠٩‏/٢٠٢١
 *      Author: Moe
 */

#include "timer.h"

void Timer1_Init(){
	//set first 4 pins of Port C to output
	DDRC |= 0x0F;
	PORTC &= ~(0x0F);

	//Non-PWM Mode
	TCCR1A = (1<<FOC1A);

	/* CTC Mode
	 * Prescaler = 1024
	 */
	TCCR1B |= (1<<WGM12) | (1<<CS10) | (1<<CS12);

	//Set initial value to 0
	TCNT1 = 0;

	//Set top value to 977 (1 sec)
	OCR1A = 977;

	//Enable global interrupt
	SREG |=(1<<7);

	//Enable Interrupts
	TIMSK |= (1<<OCIE1A);
}

