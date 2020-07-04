#include "wdg.h"
#include "sys.h"

static void IWDG_Init(u8 prer,u16 rlr);

volatile u8 WDG_Flg = 1;

/*****************************************************************************
程序功能：看门狗模块的回调函数
程序版本：V1.0
入口参数：无
返回参数：无
日    期：2019/6/18
作    者：Orange
修    改：无
******************************************************************************/

void MWDG_CallBack(void)
{
	IWDG_ReloadCounter();    //重新给看门口加载初值，如果程序运行时间超过10s，单片机就会复位
}


/*****************************************************************************
程序功能：看门狗模块的初始化
程序版本：V1.0
入口参数：无
返回参数：无
日    期：2019/6/18
作    者：Orange
修    改：无
******************************************************************************/

void MWDG_Init(void)
{
	
	IWDG_Init(PRER, RLR);  //程序运行时间超过10s，单片机就会复位
}

/*****************************************************************************
程序功能：看门狗的初始化配置
程序版本：V1.0
入口参数：*Data_BUF
返回参数：无
日    期：2019/6/18
作    者：Orange
修    改：无
******************************************************************************/

static void IWDG_Init(u8 prer,u16 rlr) 
{	
 	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  //使能对寄存器IWDG_PR和IWDG_RLR的写操作
	
	IWDG_SetPrescaler(prer);  //设置IWDG预分频值:设置IWDG预分频值为64
	
	IWDG_SetReload(rlr);  //设置IWDG重装载值,Tout=((4×2^prer) ×rlr) /40 (ms)
	
	IWDG_ReloadCounter();  //按照IWDG重装载寄存器的值重装载IWDG计数器
	
	IWDG_Enable();  //使能IWDG
}


