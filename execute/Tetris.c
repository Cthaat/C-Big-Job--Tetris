#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "welcome.h"
#include "operation.h"
#include "hidegame.h"

// 定义隐藏光标函数
void HideCursorm()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

int main()
{
    HideCursorm();
    // 设置背景颜色
    while (1)
    {
        system("color 85");
        EnglishHelp();
        ChineseHelp();
        welcome();
        int choice = 0;
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("Please select the mode");
            int mode = 0;
            HideCursorm();
            moden();
            scanf_s("%d", &mode);
            HideCursorm();
            switch (mode)
            {
            case 1:
                HideCursorm();
                point_game();
                break;
            case 2:
                HideCursorm();
                hide_game();
                break;
            case 3:
                // TwoPlayersMode();
                break;
            default:
                break;
            }
            break;
        case 0:
            system("cls");
            printf("Bye~\n");
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
