#include<reg51.h>
sbit RS=P3^1;
sbit RW=P3^2;
sbit EN=P3^3;
sbit R0=P1^0;
sbit R1=P1^1;
sbit R2=P1^2;
sbit R3=P1^3;
sbit C0=P1^4;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;
sbit led=P3^4;
#define dataline P2
void lcd_init(void);
void lcd_string(unsigned char *);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(int);
void main()
{
	int i,pass[4],pass1[4]={2,1,6,2};
	
	lcd_init();
	while(1)
	{
		i=0;
		lcd_cmd(0x80);
		lcd_string("ENTER PASSWORD");
		lcd_cmd(0xC0);
		while(i<4)
		{
		R0=0;
		R1=R2=R3=1;
		if(C0==0)
		{
			lcd_data('1');
			pass[i]=1;
			i++;
		}
		R0=0;
		R1=R2=R3=1;
		if(C1==0)
		{
			lcd_data('2');
			pass[i]=2;
			i++;
		}
		R0=0;
		R1=R2=R3=1;
		if(C2==0)
		{
			lcd_data('3');
			pass[i]=3;
			i++;
		}
		R1=0;
		R0=R2=R3=1;
		if(C0==0)
		{
			lcd_data('4');
			pass[i]=4;
			i++;
		}
		R1=0;
		R0=R2=R3=1;
		if(C1==0)
		{
			lcd_data('5');
			pass[i]=5;
			i++;
		}
		R1=0;
		R0=R2=R3=1;
		if(C2==0)
		{
			lcd_data('6');
			pass[i]=6;
			i++;
		}
		R2=0;
		R0=R1=R3=1;
		if(C0==0)
		{
			lcd_data('7');
			pass[i]=7;
			i++;
		}
		R2=0;
		R0=R1=R3=1;
		if(C1==0)
		{
			lcd_data('8');
			pass[i]=8;
			i++;
		}
		R2=0;
		R0=R1=R3=1;
		if(C2==0)
		{
			lcd_data('9');
			pass[i]=9;
			i++;
		}
		R3=0;
		R0=R1=R2=1;
		if(C1==0)
		{
			lcd_data('0');
			pass[i]=0;
			i++;
		}
		delay(120);
	}
	if((pass[0]==pass1[0])&&(pass[1]==pass1[1])&&(pass[2]==pass1[2])&&(pass[3]==pass1[3]))
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Acces Granted");
		led=1;
		delay(1000);
	}
	else
	{
		lcd_cmd(0x80);
		lcd_string("WRONG PASSWORD");
		delay(1000);
		led=0;
		lcd_cmd(0x01);
	}
}
}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_cmd(0x0F);
}
void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
		p++;
	}
}
void lcd_cmd(unsigned char c)
{
	dataline=c;
	RS=0;
	RW=0;
	EN=1;
	delay(20);
	EN=0;
}
void lcd_data(unsigned char c)
{
	dataline=c;
	RS=1;
	RW=0;
	EN=1;
	delay(20);
	EN=0;
}
void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	
	{
		for(j=0;j<200;j++)
		{
		}
	}
}