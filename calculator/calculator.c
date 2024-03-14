/*
 * calculator.c
 *
 * Created: 5/24/2023 4:06:22 PM
 *  Author: Shawky Ramadan
 */ 



#include "LCD.h"
#include "keypad_driver.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	label:	LCD_vInit();
	keypad_vInit();
unsigned char arr[6]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED} ;
unsigned short res ;
unsigned char counter=0 ;
while(1)
{
	do
	{
		arr[counter]=keypad_u8check_press();
		
	} while(arr[counter]==NOTPRESSED);
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_clearscreen();
		goto label ;
	}
	else
	{
		LCD_vSend_char(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=keypad_u8check_press();
		
	}while(arr[counter]==NOTPRESSED);
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_clearscreen();
		goto label ;
	}
	else
	{
		LCD_vSend_char(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	
	do
	{
		arr[counter]=keypad_u8check_press();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='=')
	{
		LCD_clearscreen();
		goto label ;
	}
	else
	{
		LCD_vSend_char(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=keypad_u8check_press();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_clearscreen();
		goto label ;
	}
	else
	{
		LCD_vSend_char(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	do
	{
		arr[counter]=keypad_u8check_press();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	{
		LCD_clearscreen();
		goto label ;
	}
	else
	{
		LCD_vSend_char(arr[counter]);
	}
	counter++;
	_delay_ms(300);
	
	
	do
	{
		arr[counter]=keypad_u8check_press();
		
	}while(arr[counter]==NOTPRESSED);
	
	if(arr[counter]=='=')
	{
		LCD_vSend_char(arr[counter]);
		
		
		switch(arr[counter-3])
		{
			case '+':
			res=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
			if(res>=100&&res<1000)
			{
				LCD_vSend_char((res/100)+48);
				LCD_vSend_char(((res/10)%10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if (res>=10&&res<100)
			{
				LCD_vSend_char((res/10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if(res<10)
			{
				LCD_vSend_char(res+48);
			}
			break;
			case '-' :
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=100&&res<1000)
			{
				LCD_vSend_char((res/100)+48);
				LCD_vSend_char(((res/10)%10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if (res>=10&&res<100)
			{
				LCD_vSend_char((res/10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if(res<10)
			{
				LCD_vSend_char(res+48);
			}
			break;
			case '*':
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=1000&&res<10000)
			{
				LCD_vSend_char((res/1000)+48);
				LCD_vSend_char(((res/100)%10)+48);
				LCD_vSend_char(((res/10)%10)+48);
				LCD_vSend_char((res%10)+48);
				
			}
			else if(res>=100&&res<1000)
			{
				LCD_vSend_char((res/100)+48);
				LCD_vSend_char(((res/10)%10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if (res>=10&&res<100)
			{
				LCD_vSend_char((res/10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if(res<10)
			{
				LCD_vSend_char(res+48);
			}
			break;
			case '/':
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=100&&res<1000)
			{
				LCD_vSend_char((res/100)+48);
				LCD_vSend_char(((res/10)%10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if (res>=10&&res<100)
			{
				LCD_vSend_char((res/10)+48);
				LCD_vSend_char((res%10)+48);
			}
			else if(res<10)
			{
				LCD_vSend_char(res+48);
			}
			break;
			default : break;
			
		}
	}
	else
	{
		LCD_clearscreen();
		goto label ;
	}
	_delay_ms(200);
}
	}