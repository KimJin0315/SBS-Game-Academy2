#include <stdio.h>
#include <windows.h>

enum State
{
	IDLE,
	ATTACK,
	DIE

	// ���������� �߰��� �ִ� ����� ���� �����ϰ� �Ǹ�
	// �״����� �ִ� ����� ���� ����� ������ ���� 1��
	// �����մϴ�.
};

enum Color
{
	BLACK,//0
	DARKBLUE,//1
	DARKGREEN,//2
	DARKSKYBLUE,//3
	DARKRED,//4
	DARKPURPLE,//5
	DARKYELLOW,//6
	GRAY,//7
	DARKGRAY,//8
	BLUE,//9
	GREEN,//10
	SKYBLUE,//11
	RED,//12
	PURPLE,//13
	YELLOW,//14
	WHITE		 //15
};

int main()
{
#pragma region ������
	// ������ ��� ���� ����� ��ȣ �̸���
	// �����Դϴ�.

	// enum State state = IDLE;
	// 
	// switch (state)
	// {
	// case IDLE:
	// 	printf("��� ����\n");
	// 	break;
	// case ATTACK:
	// 	printf("���� ����\n");
	// 	break;
	// case DIE:
	// 	printf("���� ����\n");
	// 	break;
	// default:
	// 	break;
	// }

#pragma endregion

	int count = 0;

	while (1)
	{
		count = count + 1;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), count % 15);

		printf("GYM\n");

		system("pause");

		system("cls");
	}

	return 0;
}