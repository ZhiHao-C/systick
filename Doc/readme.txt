TM32 中的 Systick 部分内容属于 NVIC 控制部分，一共有 4 个寄存器，名称和地址分别是：
STK_CSR      0xE000E010  --  控制寄存器	
STK_LOAD     0xE000E014  --  重载寄存器	
STK_VAL      0xE000E018  --  当前值寄存器	
STK_CALRB    0xE000E01C  --  校准值寄存器
STK_CSR 控制寄存器：寄存器内有 4 个位具有意义
第 0 位：ENABLE，Systick 使能位（0：关闭 Systick 功能；1：开启 Systick 功能）

第 1 位：TICKINT，Systick 中断使能位（0：关闭 Systick 中断；1：开启 Systick 中断）

第 2 位：CLKSOURCE，Systick 时钟源选择（0：使用 HCLK/8 作为 Systick 时钟；1：使用 HCLK 作为 Systick 时钟）

第 16 位：COUNTFLAG，Systick 计数比较标志，如果在上次读取本寄存器后，SysTick 已经数到了0，则该位为1。如果读取该位，该位将自动清零。

STK_LOAD 重载寄存器：
Systick 是一个递减的定时器，当定时器递减至0 时，重载寄存器中的值就会被重装载，继续开始递减。STK_LOAD 重载寄存器是个24 位的寄存器最大计数0xFFFFFF。
STK_VAL 当前值寄存器：
也是个24 位的寄存器，读取时返回当前倒计数的值，写它则使之清零，同
时还会清除在 SysTick 控制及状态寄存器中的 COUNTFLAG 标志。
STK_CALRB 校准值寄存器：
位31 NOREF：= 1 没有外部参考时钟（STCLK 不可用），= 0 外部参考时钟可用
位30 SKEW：= 1 校准值不是准确的1ms，= 0校准值是准确的1ms
————————————————
版权声明：本文为CSDN博主「叫我谢布斯」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xiebs/article/details/121166071