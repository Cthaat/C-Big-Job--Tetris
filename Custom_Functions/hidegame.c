#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "hidegame.h"
// 获取坐标H
#define HGet(HC) for (HC, Hi = Hn[HT[0]]; Hj = Hx + Hi % 4, Hk = Hy + Hi / 4 % 4, Hi; Hi >>= 4)
#define HNext(HC) for (HC, Hi = Hn[HT[1]]; Hnj = Hi % 4, Hnk = Hi / 4 % 4, Hi; Hi >>= 4)

// 每种方块的类型
// 使用一个数字储存
// 转化为二进制使用
int Hn[] = {
	51264,
	12816,

	21520,
	21520,

	25872,
	34113,

	21537,
	38208,

	25921,
	38481,
	38484,
	38209,

	25922,
	43345,
	34388,
	38160,

	25920,
	38177,
	42580,
	38993};
// 变量
int Hi, Hj, Hk, Hd, Hmy = 0;
int Hnj, Hnk = 0;
int Hc = -1;
// 地图
int *Hmap = NULL;
// 地图大小
int Hheight = 25;
int Hwide = 12;
int Hsize = 0;
// 坐标
int Hx = 0;
int Hy = 0;
// 类型
int HT[2] = {0};
// 积分
int Hmarks = 0;
// 困难程度
int Hflag = 0;
int Hnum = 0;
// 提示区域
int *Himply = NULL;
// 下一个元素
int *Hnext = NULL;

void hide_move(int *Hv, int Hl)
{
	// 用Get取出四个位置坐标，并判断合法性
	// 分别判断左越界，右越界，下越界，有无方块
	// 如果出现冲突，发出固定信号c = 0
	HGet(*Hv += Hl)
	{
		if (Hj < 0 || Hj >= Hwide || Hk >= Hheight || Hmap[Hk * Hwide + Hj] != 0)
		{
			// c非法
			// 将c 变为0 ，发出回滚信号
			Hc = 0;
		}
	}
	if (Hc)
	{
		Hc = 1;
	}
	// 如果c等于0 ，坐标违法，数据回滚
	if (!Hc)
	{
		*Hv -= Hl;
		// 如果是下降造成违法
		// 说明降落到某个实体上边
		// 发出固定信号
		// 准备生成下一个方块
		if (Hv == &Hy)
		{
			Hc = -1;
		}
	}
}

void hide_check(int *Hmap, int *Hc, int *Hx, int *Hy, int HT[2], int *Hj1, int *Hk1)
{
	int Hcount = 0;
	if (*Hc == -1)
	{
		// 如果没有失败，生成新的
		if (*Hy)
		{
			// 清空提示栏
			HNext(1)
			{
				Hnext[Hnk * 4 + Hnj] = 0;
			}
			// 生成下一个
			HT[0] = HT[1];
			HT[1] = rand() % 20;
			// 难度
			Hnum++;
			// 重置坐标
			*Hx = 0;
			*Hy = 0;
			Hi = 0;
			while (Hi < Hsize)
			{

				Hmap[Hi] = Hmap[Hi] ? 1 : 0;
				Hi++;
			}
			while (Hi)
			{
				for (*Hj1 = Hwide; Hi;)
				{
					*Hj1 -= !!Hmap[Hi];
					if ((Hi-- % Hwide) == 0)
					{
						break;
					}
				}
				if (!*Hj1)
				{
					Hi += Hwide;
					int Hp = Hi;
					// 消除整列
					while (Hp > Hwide)
					{
						Hmap[Hp] = Hmap[Hp - Hwide];
						Hp--;
					}
					Hi = 0;
					while (Hi < Hsize)
					{
						Hmap[Hi] = Hmap[Hi] ? 156 : 0;
						Hi++;
					}
					Hmarks += (Hwide * ++Hcount);
				}
			}
			*Hk1 = 0;
			*Hj1 = 0;
		}
		// 如果y=0代表游戏失败
		else if (!*Hy)
		{
			*Hc = 27;
			return;
		}
	}
}

void hide_game()
{
	Hc = 1;
	// 初始化
	// 设置随机数起点
	srand((unsigned int)time(NULL));
	// 开辟空间
	Hmap = (int *)calloc(Hsize = Hwide * Hheight, sizeof(int));
	Hnext = (int *)calloc(16, sizeof(int));
	// 清屏
	// 退出
	// 刷新率
	for (system("cls"); Hc - 27; Sleep(30))
	{
		CONSOLE_CURSOR_INFO Ha = {1, 0};
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Ha);
		// 获取是否有操作
		// 转换大小写
		HGet(Hc = _kbhit() ? _getch() & 95 : 1)
		{
			// 将对应的区域设置为0
			Hmap[Hk * Hwide + Hj] = 0;
		}
		// 判断c是否为对应操作
		// 如果是对应操作，异或后就是0
		// 是0的话就要继续操作逻辑或
		// 如果不是0就会跳出
		// 左右和加速操作
		//  c ^ 65 || move(&x, -1), c ^ 68 || move(&x, 1), c ^ 83 || move(&y, 1);
		// 换一种写法
		if (!(Hc ^ 65))
		{
			hide_move(&Hx, -1);
		}
		if (!(Hc ^ 68))
		{
			hide_move(&Hx, 1);
		}
		if (!(Hc ^ 83))
		{
			hide_move(&Hy, 1);
		}
		// 旋转
		if (!(Hc ^ 87))
		{
			if (HT[0] > 8)
			{
				Hi = 3;
			}
			if (HT[0] <= 8)
			{
				Hi = 1;
			}
			if ((HT[0] & Hi ^ Hi) == 0)
			{
				Hmy = -Hi;
			}
			if (HT[0] & Hi ^ Hi)
			{
				Hmy = 1;
			}
			hide_move(&HT[0], Hmy);
		}
		// 自动下落
		// 循环十次下落一次
		if (Hd != 0)
		{
			Hd--;
			HGet(1)
			{
				Hmap[Hk * Hwide + Hj] = HT[0] / 4 * 16 + 154;
			}
		}
		else if (Hd == 0)
		{
			Hc = 1;
			hide_move(&Hy, 1);
			HGet(Hd = 15 - Hflag)
			{
				Hmap[Hk * Hwide + Hj] = HT[0] / 4 * 16 + 154;
			}
		}
		if (!(Hnum % 2))
		{
			while (Hi < Hsize)
			{
				Hmap[Hi] = Hmap[Hi] ? 156 : 0;
				Hi++;
			}
		}
		// 提高难度
		if (Hnum == 15)
		{
			if (Hflag != 12)
			{
				Hflag++;
				Hnum = 0;
			}
		}
		// 检查是否可以消除
		// 并且当上一个块落下去后才可以进行检查
		hide_check(Hmap, &Hc, &Hx, &Hy, HT, &Hj, &Hk);
		// 注意这里是两个空格,不然比例不对
		// 设置光标位置准备打印
		// 同时隐藏光标
		COORD Hb = {0, 0};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Hb);
		// 打印一次
		Hi = 0;
		while (Hi < Hsize)
		{
			// 设置颜色，如果是实体就会打印出有颜色的空格
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Hmap[Hi]);
			// 无阻塞输出
			_cputs("  ");
			Hi++;
			if (Hi % Hwide == 0)
			{
				_cputs("\n");
			}
		}
		COORD Hc = {30, 12};
		// 打印分数
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Hc);
		printf("marks: %d", Hmarks);
		// 打印当前难度
		COORD Hd = {30, 14};
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Hd);
		printf("rank: %d", Hflag);
		// 打印下一个方块
		COORD He = {32, 2};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), He);
		HNext(1)
		{
			Hnext[Hnk * 4 + Hnj] = HT[1] / 4 * 16 + 154;
		}
		int Hr = 0;
		while (Hr < 16)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Hnext[Hr]);
			_cputs("  ");
			Hr++;
			if (Hr % 4 == 0)
			{
				_cputs("\n");
				COORD He = {32, 2 + Hr / 4};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), He);
			}
		}
	}
}