//三子棋小游戏
#include "game.h"

void memu()
{
	printf("************************************************\n");
	printf("**********     1. PLAY   0. EXIT     ***********\n");
	printf("************************************************\n");
}

void game()
{
	char ret = 0;
	//设置棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//设计游戏规则
	while (1)
	{
		//玩家走
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢了
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑走
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断电脑是否赢了
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret ==  '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	do
	{
		memu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}