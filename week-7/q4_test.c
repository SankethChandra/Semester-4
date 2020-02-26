#include <LPC17xx.h>
#include <stdio.h>

#define FIRST_SEG 0xF87FFFFF
#define SECOND_SEG 0xF8FFFFFF
#define THIRD_SEG 0xF97FFFFF
#define FOURTH_SEG 0xF9FFFFFF
#define DISABLE_ALL 0xFA7FFFFF

int dig1=0x00,dig2=0x00,dig3=0x00,dig4=0x00;
unsigned int twenty_count=0x00,dig_count=0x00,temp1=0x00;
unsigned char array_dec[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
unsigned char tmr0_flg=0x00,one_sec_flg=0x00;
unsigned long int temp2=0x00000000,i=0;
unsigned int temp3=0x00;
void delay(void);
void display(void);

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_PINCON->PINSEL3 &= 0XFFC03FFF;

	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_GPIO1->FIODIR |= 0X07800000;
	//switch configuration
	LPC_PINCON->PINSEL4 &= 0XFFFFFFFC;
	LPC_GPIO2->FIODIR |= 0XFFFFFFFE;
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1)
	{
		delay();
		dig_count+=1;
		if(dig_count==0x05)
		{
			dig_count=0x00;
			one_sec_flg=0xff;
		}
		if(one_sec_flg==0xff)
		{
			one_sec_flg=0x00;
			dig1+=1;
			if(dig1==0x0f)
			{
				dig1=0;
				dig2+=1;
				if(dig2==0x0f)
				{
					dig2=0;
					dig3+=1;
					if(dig3==0x0f)
					{
						dig3=0;
						dig4+=1;
						if(dig4==0x0f)
						{
							dig4=0;
						}
					}
				}
			}
		}
		display();
	}
	else
	{
		delay();
		dig_count+=1;
		if(dig_count==0x05)
		{
			dig_count=0x00;
			one_sec_flg=0xff;
		}
		if(one_sec_flg==0xff)
		{
			one_sec_flg=0x00;
			dig1-=1;
			if(dig1==-1)
			{
				dig1=0x0f;
				dig2-=1;
				if(dig2==-1)
				{
					dig2=0x0f;
					dig3-=1;
					if(dig3==-1)
					{
						dig3=0x0f;
						dig4-=1;
						if(dig4==-1)
						{
							dig4=0x0f;
						}
					}
				}
			}
		}
		display();
	}
}

}
void display(void)
{
	if(dig_count==0x01)
	{
		temp1=dig1;
		LPC_GPIO1->FIOPIN=FIRST_SEG;
	}
	else if(dig_count==0x02)
	{
		temp1=dig2;
		LPC_GPIO1->FIOPIN=SECOND_SEG;
	}
	else if(dig_count==0x03)
	{
		temp1=dig3;
		LPC_GPIO1->FIOPIN=THIRD_SEG;
	}
	else if(dig_count==0x04)
	{
		temp1=dig4;
		LPC_GPIO1->FIOPIN=FOURTH_SEG;
	}
	temp1&=0x0f;
	temp2=array_dec[temp1];
	temp2=temp2<<4;
	LPC_GPIO0->FIOPIN=temp2;
	for(i=0;i<500;i++);
	LPC_GPIO0->FIOCLR=0X0000FF00;
	LPC_GPIO1->FIOPIN=DISABLE_ALL;
}

void delay(void)
{
	unsigned int i;
	for(i=0;i<1000;i++);
	if(twenty_count==1000)
	{
		one_sec_flg=0xff;
		twenty_count=0x00;
	}
	else
		twenty_count+=1;
}
