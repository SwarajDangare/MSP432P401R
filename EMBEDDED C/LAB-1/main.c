#include"msp.h"
void delay(int n);
void PORT1_IRQHandler(void);
void delay(int n)
{
	int i,j;
	 for(i=0;i<n;i++)
	{
		for(j=750;j>0;j++);
	}
}

int main(void)
{
		__disable_irq();
		WDT_A->CTL=WDT_A_CTL_PW|WDT_A_CTL_HOLD;
		
		P2->DIR |= BIT0;
	
		P1->DIR &= ~BIT0;
		P1->REN |= BIT1;
		P1->OUT |= BIT1;
		
		P1->IES &= ~BIT1;
		P1->IFG &= ~BIT1;
		P1->IE |= BIT4;
		NVIC->ISER[1]= 0x0000008;
	  __enable_irq();
		while(1){
		}
}

void PORT1_IRQHandler(void)
{
	if((P1->IFG & BIT4)== BIT4)
	{
		P2->OUT |= BIT2;
		delay(2000);
		P2->OUT ^= BIT2;
		P1->IFG = 0;
	}
}