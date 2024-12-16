#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int screenIndex;
HANDLE screen[2];

void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;

	// 화면 버퍼를 2개 생성합니다.
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	cursor.dwSize = 1;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);

}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;

}

void Clear()


{
	COORD position = { 0,0 };

	DWORD dword;

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(handle, &consoleInfo);

	int width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	int	height = consoleInfo.srWindow.Top - consoleInfo.srWindow.Bottom + 1;

	FillConsoleOutputCharacter(screen[screenIndex], ' ', width * height, position ,&dword);
}

void Position(int x, int y)
{
	// x축과 y축을 설정
	COORD position = { x , y };
	
	// 커서 위치를 이동하는 함수
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	char key = 0;

	int x = 0;
	int y = 0;

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	
	// CONSOLE_SCREEN_BUFFER_INFO : 콘솔창 화면 크기 정보

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(handle, &consoleInfo);
	
	while (1)
	{
		Position(x,y);
		printf("★");

		if (_kbhit())
		{
			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP:
				if (y > 0)
					y--;
				break;
			case LEFT:
				if (x > 0)
					x -= 2;
				break;
			case RIGHT:
				if (x < consoleInfo.srWindow.Right - 1)
					x += 2;
				break;
			case DOWN:
				if (y < consoleInfo.srWindow.Bottom)
					y++;
				break;
			default:
				printf("Exception\n");
				break;
			}
		}
		system("cls");
	}

	return 0;
}