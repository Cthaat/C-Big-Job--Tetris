#include <stdio.h>

// 方块
struct form
{
    int tT;
    int directiona[160];
};
struct tform tform1 = {1,
                       {0, 0, 0, 1, 1, 0, 1, 1,
                        0, 0, 0, 1, 1, 0, 1, 1,
                        0, 0, 0, 1, 0, 2, 0, 3,
                        0, 0, 1, 0, 2, 0, 3, 0,
                        0, 1, 1, 1, 1, 0, 2, 0,
                        0, 0, 0, 1, 1, 1, 1, 2,
                        0, 0, 1, 0, 1, 1, 2, 1,
                        1, 0, 1, 1, 0, 1, 0, 2,

                        0, 0, 0, 1, 0, 2, 1, 2,
                        2, 0, 2, 1, 1, 1, 0, 1,
                        0, 0, 1, 0, 1, 1, 1, 2,
                        0, 0, 1, 0, 2, 0, 0, 1,
                        1, 0, 1, 1, 1, 2, 0, 2,
                        0, 0, 1, 0, 2, 0, 2, 1,
                        0, 0, 1, 0, 0, 1, 0, 2,
                        0, 0, 0, 1, 1, 1, 2, 1,
                        0, 0, 1, 0, 2, 0, 1, 1,
                        0, 0, 0, 1, 1, 1, 0, 2,
                        1, 0, 0, 1, 1, 1, 2, 1,
                        1, 0, 0, 1, 1, 1, 1, 2}};
// 定义隐藏光标函数
void tOHideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

// 地图长宽
int tmap_width = 15;
int tmap_height = 25;
int tmap_size = tmap_width * tmap_height;

// 地图
int *tmap1 = NULL;
int *tmap2 = NULL;

// 下一方块
int *tnext1 = NULL;
int *tnext2 = NULL;

// 方块坐标
int tj1 = 0;
int tk1 = 0;
int tx1 = 0;
int ty1 = 0;
int tj2 = 0;
int tk2 = 0;
int tx2 = 0;
int ty2 = 0;

int tc1 = 0;
int tc2 = 0;

int T1[2] = 0;
int T2[2] = 0;

int td = 0;

void TwoPlayers()
{
    // 设置随机数起点
    srand((unsigned int)time(NULL));
    // 初始化地图
    tmap1 = (int *)malloc(sizeof(int) * tmap_size);
    tmap2 = (int *)malloc(sizeof(int) * tmap_size);
    tnext1 = (int *)malloc(sizeof(int) * 16);
    tnext2 = (int *)malloc(sizeof(int) * 16);
    for (system("cls"), c - 27, Sleep(30))
    {
        // 隐藏光标
        tOHideCursor();
        // 将刚才方块所占位置设为0
        for (int i = T1[0], int p = T2[0], int tb = 0; tj1 = tx1 + tform1.directiona[i * 8 - 1 + tb], tk1 = ty1 + tform1.directiona[i * 8 + tb], tj2 = tx2 + tform1.directiona[p * 8 - 1 + tb], tk2 = ty2 + tform1.directiona[p * 8 + tb - 1], tb != 7; tb += 2)
        {
            tmap1[tk1 * tmap_width + tj1] = 0;
            tmap2[tk2 * tmap_width + tj2] = 0;
        }
        tc1 = _kbhit() ? _getch() & 95 : 1 if (!(tc1 ^ 65))
        {
            move(&tx1, -1);
        }
        if (!(tc1 ^ 68))
        {
            move(&tx1, 1);
        }
        if (!(tc1 ^ 83))
        {
            move(&ty1, 1);
        }
        // 旋转
        if (!(tc1 ^ 87))
        {
            tturn();
        }
        tc2 = _kbhit() ? _getch() & 95 : 1 if (!(tc2 ^ 37))
        {
            move(&tx2, -1);
        }
        if (!(tc2 ^ 39))
        {
            move(&tx2, 1);
        }
        if (!(tc2 ^ 40))
        {
            move(&ty2, 1);
        }
        // 旋转
        if (!(tc2 ^ 38))
        {
            tturn();
        }
        if (td)
        {
            td--;
            for (int i = T1[0], int p = T2[0], int tb = 0; tj1 = tx1 + tform1.directiona[i * 8 - 1 + tb], tk1 = ty1 + tform1.directiona[i * 8 + tb], tj2 = tx2 + tform1.directiona[p * 8 - 1 + tb], tk2 = ty2 + tform1.directiona[p * 8 + tb - 1], tb != 7; tb += 2)
            {
                tmap1[tk1 * tmap_width + tj1] = T1[0] / 4 * 16 + 154;
                tmap2[tk2 * tmap_width + tj2] = T2[0] / 4 * 16 + 154;
            }
        }
        if (!td)
        {
            c = 1;
            move(&ty1, 1);
            move(&ty2, 1);
            for (int i = T1[0], int p = T2[0], int tb = 0; tj1 = tx1 + tform1.directiona[i * 8 - 1 + tb], tk1 = ty1 + tform1.directiona[i * 8 + tb], tj2 = tx2 + tform1.directiona[p * 8 - 1 + tb], tk2 = ty2 + tform1.directiona[p * 8 + tb - 1], tb != 7; tb += 2)
            {
                tmap1[tk1 * tmap_width + tj1] = T1[0] / 4 * 16 + 154;
                tmap2[tk2 * tmap_width + tj2] = T2[0] / 4 * 16 + 154;
            }
        }
        check(tmap1);
        check(tmap2);
    }
}
