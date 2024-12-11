#include <stdio.h>
#include <windows.h>

#define SIZE 10

int main()
{
	// 홀수 의뢰인 짝수 탐정

	const char* dialog[SIZE];

	dialog[0] = "무엇을 도와 드릴까요?";
	dialog[1] = "잃어버린 강아지를 찾아주세요.";
	dialog[2] = "찾을 만한 단서가 어떤 것이 있나요?";
	dialog[3] = "우리집 강아지는 비숑입니다.";
	dialog[4] = "또 다른 단서는 없나요?";
	dialog[5] = "목에 이름표가 있습니다.";
	dialog[6] = "강아지 이름이 어떻게 됩니까?";
	dialog[7] = "강아지 이름은 몽이 입니다.";
	dialog[8] = "다음 주 까지 찾아 보겠습니다.";
	dialog[9] = "감사합니다.";

	int count = 0;

	while (count < SIZE)
	{
		// 0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태

		// 0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태

		// 0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태

		// 0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			if (count % 2 == 0)
			{
				printf("탐정 : ");
			}
			else
			{
				printf("의뢰인 : ");
			}

			printf("%s\n", dialog[count]);

			count++;
		}
	}

	return 0;
}