#include <stdio.h>
#include <windows.h>

#define SIZE 10

int main()
{
	// Ȧ�� �Ƿ��� ¦�� Ž��

	const char* dialog[SIZE];

	dialog[0] = "������ ���� �帱���?";
	dialog[1] = "�Ҿ���� �������� ã���ּ���.";
	dialog[2] = "ã�� ���� �ܼ��� � ���� �ֳ���?";
	dialog[3] = "�츮�� �������� ����Դϴ�.";
	dialog[4] = "�� �ٸ� �ܼ��� ������?";
	dialog[5] = "�� �̸�ǥ�� �ֽ��ϴ�.";
	dialog[6] = "������ �̸��� ��� �˴ϱ�?";
	dialog[7] = "������ �̸��� ���� �Դϴ�.";
	dialog[8] = "���� �� ���� ã�� ���ڽ��ϴ�.";
	dialog[9] = "�����մϴ�.";

	int count = 0;

	while (count < SIZE)
	{
		// 0x0000 : ������ ���� ���� ���� ȣ�� �������� �������� ���� ����
		
		// 0x0001 : ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����

		// 0x8000 : ������ ���� ���� ���� ȣ�� �������� �����ִ� ����

		// 0x8001 : ������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			if (count % 2 == 0)
			{
				printf("Ž�� : ");
			}
			else
			{
				printf("�Ƿ��� : ");
			}

			printf("%s\n", dialog[count]);

			count++;
		}
	}

	return 0;
}