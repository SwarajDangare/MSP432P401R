/*
Q. UART    CLOCK=12MHz    BD= 115200

A.

n=12000000/115200=104.1666

n>16                          UCOS16 -> 1

n/16 = 6.5104                 BRW->6 

0.5104*16 = 8                 BRF->8   

From table of BRS find the value of BRS for 0.166
                              BRS->0x20

MCTLW   0010 0000   1000     0001       = 0X2081     
           BRS       BRF     OS16

*/

#include "msp.h"
int main (void)
{
	P1->SEL0|=BIT2|BIT3;  //PINS FOR UART
	
	CS->KEY|=CS_KEY_VAL;
	CS->CTL0 |= CS_CTL0_DCOEN|CS_CTL0_DCORSEL_2;
	CS->CTL1 |= CS_CTL1_SELS_3;
	CS->KEY &= ~CS_KEY_VAL;

	EUSCI_A0->CTLW0|=(1<<0);    //RESET UART
	EUSCI_A0->CTLW0|=(1<<15)|(1<<14)|(2<<6);  
	EUSCI_A0->BRW=6;
	EUSCI_A0->MCTLW  = 0x2081;
	EUSCI_A0->IE |=(1<<0)|(1<<1);         //IE = enable interupts
	EUSCI_A0->IFG &=~((1<<0)|(1<<1));

	__enable_irq();
	NVIC->ISER[0]= (1<<16);     
	EUSCI_A0->CTLW0&=~(1<<0);  //ENABLE UART

while(1);
}

void EUSCIA0_IRQHandler()
{     
	    //transmiter                       //reciver
	if(EUSCI_A0->IFG & BIT1)         //if(EUSCI_A0->IFG & BIT0) 
	{                                //{
		EUSCI_A0->TXBUF = "data";        //if(EUSCI_A0->RXBUF == "data")		
	  //Task given                     //{                           
		//                             		  	//task given
		//                                    //  
		//                                    //
		//                               //}
	}                                //} 
  EUSCI_A0->IFG &=~(1<<1);       	//OR EUSCI_A0->IFG &=~(1<<0)

}
