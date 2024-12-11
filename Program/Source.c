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

	srand(time(NULL));

	int list[SIZE] = { 1,2,3,4,5 };

	shuffle(list, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}
#pragma endregion


	return 0;
}