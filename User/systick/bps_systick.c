#include "bps_systick.h"


void Systick_us_delay(uint32_t us)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock/1000000);
	for (i=0;i<us;i++)
	{
		while (!(SysTick->CTRL &(1<<16)));
//		SysTick->CTRL &=~(1<<16);//ÊÖ¶¯ÇåÁã
	}
	SysTick->CTRL &=(~(SysTick_CTRL_ENABLE_Msk));
}



void Systick_ms_delay(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	for (i=0;i<ms;i++)
	{
		while (!(SysTick->CTRL &(1<<16)));
//		SysTick->CTRL &=~(1<<16);
	}
	SysTick->CTRL &=(~SysTick_CTRL_ENABLE_Msk);

}

