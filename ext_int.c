/*
 * ext_int.c
 *
 *  Created on: ١٥‏/٠٩‏/٢٠٢١
 *      Author: Moe
 */

#include "ext_int.h"

void INT0_Init(){

	//Set PD2 as input for button 1 with internal pull-up
	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);

	// Falling edge generates interrupt
	MCUCR |= (1<<ISC01);

	// Enable external interrupt
	GICR |= (1<<INT0);

	//Enable global interrupt
	SREG |=(1<<7);
}

void INT1_Init(){

	//SET PD3 as input for button 2
	DDRD &= ~(1<<PD3);

	// Falling edge generates interrupt
	MCUCR |= (1<<ISC11) | (1<<ISC10);

	// Enable external inteerupt
	GICR |= (1<<INT1);

	//Enable global interrupt
	SREG |=(1<<7);
}

void INT2_Init(){

	//Set PD2 as input for button 3 with internal pull-up
	DDRD &= ~(1<<PB2);
	PORTD |= (1<<PB2);

	// Falling edge generates interrupt
	MCUCSR &= ~(1<<ISC2);

	// Enable external inteerupt
	GICR |= (1<<INT2);

	//Enable global interrupt
	SREG |=(1<<7);
}
