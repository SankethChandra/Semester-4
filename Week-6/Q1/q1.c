#include<LPC17xx.h>
int main(void)
{
	unsigned int i,j;
	unsigned long led =0x00000000;
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	while(1)
	{
		led=0x00000010;
		for(i=1;i<9;i++)
		{
		LPC_GPIO0->FIOSET=led;
		for(j=0;j<100000;j++)
		{
		}
		led <<= 1;
	  }

	led=0x00000010;
	for(i=1;i<9;i++)
{
	LPC_GPIO0->FIOCLR=led;
	for(j=1;j<100000;j++)
	{}//working as delay function
		led<<=1;
		}
	}
}
