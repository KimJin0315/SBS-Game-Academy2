#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void shuffle(int array[], int size)
{

	for (int i = 0; i < size; i++)
	{
		int range = rand() % size;

		int temporary = array[range];
		array[range] = array[i];
		array[i] = temporary;
	}
}

void View(int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("♥");
	}
	printf("\n");
}

int main()
{
#pragma region rand() 함수

	// seed값에 따라서 rand의 값이 바뀌게 됩니다.
	// srand(time(NULL));
	// 
	// int random = rand() % 10 + 1 ;
	// rand() % n : 0 ~ n-1 범위의 난수 생성
	// (rand() % n) + 1 : 1 ~ n 범위의 난수 생성
	// 
	// printf("random 변수의 값 : %d\n", random);

#pragma endregion

#pragma region 셔플 함수

	// srand(time(NULL));
	// 
	// int list[SIZE] = { 1,2,3,4,5 };
	// 
	// shuffle(list, SIZE);
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	printf("%d ", list[i]);
	// }
#pragma endregion

#pragma region localtime() 함수

	// time_t currentTime = 0;
	// 
	// time(&currentTime);
	// 
	// struct tm * timePointer = localtime(&currentTime);
	// 
	// printf("%d 초\n", timePointer->tm_sec);
	// printf("%d 분\n", timePointer->tm_min);
	// printf("%d 시\n", timePointer->tm_hour);
	// 
	// printf("%d 월\n", timePointer->tm_mon + 1);
	// printf("%d 일\n", timePointer->tm_mday);
	// printf("%d 년\n", timePointer->tm_year + 1900);
	// 
	// switch (timePointer->tm_wday)
	// {
	// case 0:
	// 	printf("일요일");
	// 	break;
	// case 1:
	// 	printf("월요일");
	// 	break;
	// case 2:
	// 	printf("화요일");
	// 	break;
	// case 3:
	// 	printf("수요일");
	// 	break;
	// case 4:
	// 	printf("목요일");
	// 	break;
	// case 5:
	// 	printf("금요일");
	// 	break;
	// case 6:
	// 	printf("토요일");
	// 	break;
	// }
#pragma endregion

#pragma region UP - DOWN Game

	srand(time(NULL));
	
	int health = 5;
	int answer = 0;
	int computer = rand() & 50 +1;
	
	printf(" > Game Strart <\n\n");
	
	while (health > 0)
	{
		printf("체력 : ");
		View(health);
		printf("computer가 가지고 있는 값 : ");
		scanf_s("%d", &answer);
	
		if (answer == computer)
		{
			printf("V I C T O R Y");
			break;
		}
		else if (answer < computer)
		{
			printf("computer가 가지고 있는 값보다 작습니다.\n");
			health--;
		}
		else if (answer > computer)
		{
			printf("computer가 가지고 있는 값보다 큽니다.\n");
			health--;
		}
	
		printf("\n");
	}
	
	if (health <= 0)
	{
		printf("\nD E F E A T\n");
	}

#pragma endregion

	return 0;
}