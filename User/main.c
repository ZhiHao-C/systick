#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_systick.h"


void delay_ms(int n)//ÑÓÊ±º¯Êý
{
	int i;
	while (n--)
	{
		for(i=0;i<5520;i++);
	}
}



int main()
{
	LED_G_GPIO_Config();
	while (1)
	{
		led(on);
		Systick_us_delay(500000);
		led(off);
		Systick_us_delay(500000);
	}
}

