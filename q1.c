#include<lpc17xx.h>

void lcd_init(void);
void write_cmd(void);
void delay_lcd(unsigned int);
void lcd_com(int);
void write_data(void);
void lcd_data(void);
void clear_ports(void);
void lcd_puts(unsigned char*);

unsigned char Msg3[11]={"MIT"};
unsigned char Msg4[20]={"Dept. of CSE"};
unsigned long int temp1=0,temp2=0;

int main(void)
{
	lcd_init();
	temp1=0x80;
	delay_lcd(800);
	lcd_puts(&Msg3[0]);
	
	lcd_com(0x00);
	delay_lcd(800);
	lcd_puts(&Msg4[0]);
	return 0;
}
void lcd_init(void)
{
	LPC_GPIO0->FIODIR|=0x0f<<23|1<<27|1<<28;
	clear_ports();
	delay_lcd(3200);
	
	lcd_com(0x33);
	delay_lcd(800);
	
	lcd_com(0x32);
	delay_lcd(800);
	
	lcd_com(0x28);
	delay_lcd(800);
	
	lcd_com(0x0c);
	delay_lcd(800);
	
	lcd_com(0x06);
	delay_lcd(800);
	
	lcd_com(0x01);
	delay_lcd(800);
	
	lcd_com(0x80);
	delay_lcd(800);
	return;
}
void clear_ports()
{
	LPC_GPIO0->FIOCLR=0x0F<<23;
	LPC_GPIO0->FIOCLR=1<<27;
	LPC_GPIO0->FIOCLR=1<<28;
	return;
}
void delay_lcd(unsigned int r1)
{
	unsigned int r;
	for(r=0;r<r1;r++);
	return;
}
void lcd_com(int temp1)
{
	temp2=temp1&0xf0;
	temp2=temp2<<19;
	write_cmd();
	delay_lcd(30000);
	temp2=temp1&0x0f;
	temp2=temp2<<23;
	write_cmd();
	delay_lcd(30000);
	return;
}
void write_cmd()
{
clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOCLR=1<<27;
	LPC_GPIO0->FIOSET=1<<28;
	delay_lcd(800);
	LPC_GPIO0->FIOCLR=1<<28;
	return;
}

void lcd_puts(unsigned char *buf1)
{
unsigned int i=0;
	while(buf1[i]!='\0')
	{
		temp1=buf1[i];
		lcd_data();
		i++;
		if(i==16)
		{
			lcd_com(0xc0);
			delay_lcd(800);
		}
	}	
return;
}
void lcd_data(void)
{
temp2=temp1&0xf0;
temp2=temp2<<19;
	write_data();
	delay_lcd(800);
	temp2=temp1&0x0f;
	temp2=temp2<<23;
	write_data();
	delay_lcd(800);
	return;
}
void write_data(void)
{
clear_ports();
LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOSET=1<<27;
LPC_GPIO0->FIOSET=1<<28;
	delay_lcd(800);
	LPC_GPIO0->FIOCLR=1<<28;
	return;
}


