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

// 0 BLACK
// 1 DARKBLUE
// 2 DARKGREEN

enum ColorType
{
	BLACK,  	//0
	DARKBLUE,	//1
	DarkGreen,	//2
	DARKSkyBlue,//3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("GYM");
	return 0;
}