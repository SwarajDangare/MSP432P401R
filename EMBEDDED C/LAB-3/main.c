#include "msp.h"
int main(void)
{
	WDT_A->CTL = WDT_A_CTL_HOLD|WDT_A_CTL_PW;
	
	P2->DIR|=BIT0;
	TIMER32_1->LOAD |= 2999999;
	TIMER32_1->CONTROL |= (1<<1|1<<5|1<<6|1<<7);
	
	
	while(1)
	{
		if ((TIMER32_1->RIS & 1<<0) == 1) 
		{
			TIMER32_1->INTCLR=0;
			P2->OUT^=BIT0;
		}
	}
}