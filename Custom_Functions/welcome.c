#include "welcome.h"


void welcome()
{
	system("cls");
	printf("  \t*****************************************************************************\n");
	printf("  \t*                          Welcome to play Tetris!                          *\n");
	printf("  \t*                             operating method                              *\n");
	printf("  \t*                    W : turn  A : left  S : speeder  D : right             *\n");
	printf("  \t*                                                                           *\n");
	printf("  \t*                    1.PLAY                             0.exit              *\n");
	printf("  \t*                                                                           *\n");
	printf("  \t*                             Have a good game.                             *\n");
	printf("  \t*                              Version: 1.0                                 *\n");
	printf("  \t*           Made By 杨毅 8008123198 | Major Computer II | Class 2307         *\n");
	printf("  \t*****************************************************************************\n");
}

void ChineseHelp()
{
	system("cls");
	printf("  \t*                            以下是一些可能会帮助你的建议                                               *\n");
	printf("  \t         俄罗斯方块(Tetris)是一款经典的电脑游戏,玩家可以通过控制方块的旋转和移动,使它们落在正确的位置         \n");
	printf("  \t                                从而消除一行或一列的方块,获得分数。                                       \n");
	printf("  \t                              下面是显示俄罗斯方块的功能说明和使用说明:                                   \n");
	printf("  \t                                           功能说明:                                                   \n");
	printf("  \t                                   1 . 方块的移动和旋转                                                 \n");
	printf("  \t                                   2 . 消除行或列                                                       \n");
	printf("  \t                                   3 . 获得分数                                                         \n");
	printf("  \t                                   4 . 游戏结束                                                         \n");
	printf("  \t         使用说明:                                                                                      \n");
	printf("  \t  1 . 游戏界面:                                                                                         \n");
	printf("  \t  游戏界面包括一个包含方块的棋盘和一些辅助按钮,如开始游戏、 显示得分等。                                     \n");
	printf("  \t  2 . 方块:                                                                                            \n");
	printf("  \t  方块由四个小方块组成,每个方块都有一个颜色,可以通过旋转方块来改变它们的位置和方向。                          \n");
	printf("  \t  3 . 移动方块:                                                                                        \n");
	printf("  \t  玩家可以通过按方向键(上、下、左、右)来移动方块,使它们落在棋盘的某个位置上。                                \n");
	printf("  \t  4 . 旋转方块:                                                                                         \n");
	printf("  \t  玩家可以通过按方向键(上、下、左、右)来旋转方块,使它们的方向发生变化。                                      \n");
	printf("  \t  5 . 消除行或列:                                                                                       \n");
	printf("  \t  当一行的方块被全部消除时,这一行上的方块将被消除,并且这一行的位置将被空出来。                                \n");
	printf("  \t  当一列的方块被全部消除时,这一列上的方块将被消除,并且这一列的位置将被空出来。                                \n");
	printf("  \t  6 . 获得分数:                                                                                         \n");
	printf("  \t  当一行的方块被消除时,玩家会获得一定的分数。分数的计算方式可以根据游戏的设计而有所不同。                      \n");
	printf("  \t  7 . 游戏结束:                                                                                         \n");
	printf("  \t  当棋盘上的方块已经无法再移动和旋转时,游戏将会结束。                                                       \n");
	printf("  \t  这就是全部！！                                                                                         \n");
	printf("  \t                                                                                                       \n");
	printf("  \t                   希望这些信息能够帮助你更好地理解俄罗斯方块的游戏玩法和使用方法。                          \n");
	printf("  \t                                       祝你玩得开心!                                                    \n");
	system("pause");
	system("cls");
}

void EnglishHelp()
{
	system("cls");
	printf("  \t*                            Here are some suggestions that may help you                              *\n");
	printf("  \t    Tetris is a classic computer game that players can control the movement and rotation of blocks     \n");
	printf("  \tto fit them in the correct positions, thereby eliminating rows or columns of blocks and gaining scores.\n");
	printf("  \t              Below is a brief description of the functions of Tetris and how to use it:               \n");
	printf("  \t                                       Function Description:                                           \n");
	printf("  \t                                   1 . Block movement and rotation                                     \n");
	printf("  \t                                   2 . Line or column elimination                                      \n");
	printf("  \t                                   3 . Scoring                                                         \n");
	printf("  \t                                   4 . Game over                                                       \n");
	printf("  \t      Usage Instructions:                                                                              \n");
	printf("  \t  1 . Game interface:                                                                                  \n");
	printf("  \t The game interface includes a chessboard with blocks and some auxiliary buttons,                      \n");
	printf("  \t such as start the game, pause the game, and display the score.                                        \n");
	printf("  \t  2 . Blocks:                                                                                          \n");
	printf("  \t  Blocks are made up of four small blocks, each with a color,                                          \n");
	printf("  \t  which can be changed by rotating the blocks to change their position and direction.                  \n");
	printf("  \t  3 . Block movement:                                                                                  \n");
	printf("  \t  Players can move blocks by pressing direction keys (up, down, left, and right) on the keyboard,      \n");
	printf("  \t  placing them in a position on the chessboard.                                                        \n");
	printf("  \t  4 . Block rotation:                                                                                  \n");
	printf("  \t  Players can rotate blocks by pressing direction keys ""UP"" on the keyboard,                         \n");
	printf("  \t  changing their direction.                                                                            \n");
	printf("  \t  5 . Line or column elimination:                                                                      \n");
	printf("  \t  When all the blocks in a row are eliminated, the row will be eliminated,                             \n");
	printf("  \t  and the position will be cleared.                                                                    \n");
	printf("  \t  When all the blocks in a column are eliminated,                                                      \n");
	printf("  \t  the column will be eliminated, and the position will be cleared.                                     \n");
	printf("  \t  6 . Scoring:                                                                                         \n");
	printf("  \t  When a row of blocks is eliminated,                                                                  \n");
	printf("  \t  the player will earn a certain score based on the game design.                                       \n");
	printf("  \t  7 . Game over:                                                                                       \n");
	printf("  \t  When the blocks on the chessboard cannot be moved or rotated anymore, the game will end.             \n");
	printf("  \t  That ALL!                                                                                            \n");
	printf("  \t                                                                                                       \n");
	printf("  \t   I hope these information will help you better understand the rules and usage of Tetris.             \n");
	printf("  \t                                     Good luck playing!                                                \n");
	system("pause");
	system("cls");
}

void moden()
{
	system("cls");
	printf("  \t*****************************************************************************\n");
	printf("  \t*                          Welcome to play Tetris!                          *\n");
	printf("  \t*                             GAME   MODERN                                 *\n");
	printf("  \t*                            1 . point system                               *\n");
	printf("  \t*                            2 . hide  system                               *\n");
	printf("  \t*                                                                           *\n");
	printf("  \t*                                                                           *\n");
	printf("  \t*                         0 . Back to previous page                         *\n");
	printf("  \t*                            Have a good game.                              *\n");
	printf("  \t*                                                                           *\n");
	printf("  \t*****************************************************************************\n");
}