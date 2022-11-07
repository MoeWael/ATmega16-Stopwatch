/*
 * main.c
 *
 *  Created on: ١٥‏/٠٩‏/٢٠٢١
 *      Author: Moe
 */


#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

#include "timer.h"
#include "ext_int.h"

uint8_t sec = 0;
uint8_t min = 0;
uint8_t hour = 0;

int main(){

	//Set first 6 pins of Port A as output
	//for 7 segments enable/disable
	DDRA |= 0x3F;
	PORTA &= ~(0x3F);

	Timer1_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();

	while(1){
		PORTA = (1<<5);
		PORTC = sec%10;
		_delay_ms(5);

		PORTA = (1<<4);
		PORTC = sec/10;
		_delay_ms(5);

		PORTA = (1<<3);
		PORTC = min%10;
		_delay_ms(5);

		PORTA = (1<<2);
		PORTC = min/10;
		_delay_ms(5);

		PORTA |= (1<<1);
		PORTC = hour%10;
		_delay_ms(5);

		PORTA = (1<<0);
		PORTC = hour/10;
		_delay_ms(5);

	}
}

ISR(TIMER1_COMPA_vect){

	sec++;
	if(sec == 60){
		sec = 0;
		min++;
	}
	if(min == 60){
		min = 0;
		hour++;
	}

}

ISR(INT0_vect){

	sec = 0;
	min = 0;
	hour = 0;
}

ISR(INT1_vect){

	TCCR1B &= ~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10);
}

ISR(INT2_vect){

	TCCR1B |= (1<<CS12) | (1<<CS10);
}
