#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "welcome.h"
#include "operation.h"
#include "hidegame.h"

int main()
{
    // 设置背景颜色
    while (1)
    {
        system("color 84");
        welcome();
        int choice = 0;
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("Please select the mode");
            int mode = 0;
            moden();
            scanf_s("%d", &mode);
            CONSOLE_CURSOR_INFO a = {1, 0};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
            switch (mode)
            {
            case 1:
                CONSOLE_CURSOR_INFO a = {1, 0};
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
                point_game();
                break;
            case 2:
                CONSOLE_CURSOR_INFO a1 = {1, 0};
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a1);
                hide_game();
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
