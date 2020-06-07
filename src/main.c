
/*
program to control 7-segment display using INT2
requirements:
- the 7-segment is connected to the first four pins of PORTC
- connect the switch using pull down configuration on INT2/PB2 pin
conditions:
- when INT2 is triggered just increase the number appeared in the 7-segment
display, and if the maximum number (9) is reached, overflow occurs
*/

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT2_vect)
{
	if(PORTC == 9)	
	   PORTC=0;
	else 
	   PORTC++;		
}

/* External INT2 enable and configuration function */
void INT2_Init(void){
	  
}

int main(void)
{
	DDRC = 0xFF; 			.
	PORTC = 0x00; 		     // 7-seg display off
	DDRB  &= (~(1<<PB2));    // configure INT2/PB2 as input pin
	
	/* interrupt setup */
    cli();      
	GICR   |= (1<<INT2);	// Enable external interrupt pin INT2
	MCUCSR |= (1<<ISC2);    // Trigger INT2 with the raising edge
	sei();    
	
   for(;;);				
}
