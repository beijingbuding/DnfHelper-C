#include "pch.h"
#include "framework.h"
#include "Address.h"
#include "功能.h"
#include "读写.h"
#include "公用.h"

VOID 武器冰冻() {
	MessageBoxW(NULL, L"武器冰冻", L"功能", MB_OK);

	BOOL static 冰冻开关 = FALSE;
	DWORD64 空白地址 = 全局空白;
	if (冰冻开关 == FALSE)
	{
		DWORD64 kb = 读长整数型(空白地址);
		DWORD64 rw = 读长整数型(人物基址);
		DWORD64 rwb = 读长整数型(人物基址B);

		写长整数型(空白地址, 0);
		写长整数型(空白地址 + 4, 2000);
		写长整数型(空白地址 + 8, 2000);
		写长整数型(空白地址 + 12, 0);
		写长整数型(空白地址 + 16, 0);
		写长整数型(空白地址 + 20, 0);
		写长整数型(空白地址 + 24, 0);
		写长整数型(空白地址 + 28, 0);
		DWORD64 武器 = 读长整数型(读长整数型(人物基址) + 武器偏移);
		写长整数型(武器 + 冰冻开始, 空白地址);
		写长整数型(武器 + 冰冻结束, 空白地址 + 32);
		冰冻开关 = TRUE;
		return;
	}
	DWORD64 武器 = 读长整数型(读长整数型(人物基址) + 武器偏移);
	写长整数型(武器 + 冰冻开始, 0);
	写长整数型(武器 + 冰冻结束, 0);
	for (int i = 0; i >= 7; i++)
	{
		写整数型(空白地址, 0);
		空白地址 = 空白地址 + 4;
	}
	冰冻开关 = FALSE;
}

//void 技能开关() {
//
//	HWND hWnd = FindWindow(TEXT("地下城与勇士"), TEXT("地下城与勇士"));
//	static bool _switch = false;
//	if (_switch == false)
//	{
//		SetTimer(hWnd, 1, 频率, (TIMERPROC)遍历全屏技能);
//		公告("技能全屏 - 开启");
//	}
//	else
//	{
//		KillTimer(hWnd, 1);
//		公告("技能全屏 - 关闭");
//	}
//	_switch = !_switch;
//
//}



VOID HOOK伤害() {
	BOOL static HOOK开关 = false;

	DWORD64 伤害地址, 伤害数值;
	BYTE* 地址原数据;

	伤害地址 = 全局基址;
	伤害数值 = 999999999;

	if (HOOK开关)
	{
		地址原数据 = 读字节集型(伤害地址,10);
		//写字节集型(伤害地址, { 72, 190 } + 到长字节集(伤害数值));
	}
	else
	{
		//写字节集型(伤害地址,(PBYTE)地址原数据,10);
	}
}


