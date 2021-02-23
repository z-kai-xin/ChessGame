//������С��Ϸ
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
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//�����Ϸ����
	while (1)
	{
		//�����
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//������
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret ==  '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	do
	{
		memu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
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