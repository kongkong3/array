//10������ 2������ ��ȯ�ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int j = 0;
int main(void)
{
	int digit, binary = 0;
	int numarr[30] = { 0 };
	printf("��ȯ�ϰ��� �ϴ� 10������ �Է��� �ּ���:\n");
	scanf("%d", &digit);
	for (int i = 0; digit > 0; i++) // �̷��� digit �� digit > 0 �� ���� �����صθ� digit �� 0�� �Ǵ� ���� �ݺ����� Ż���Ѵ�.
	{
		numarr[i] = digit % 2;
		digit = digit / 2;
		j += 1;
	}
	for (int i = j - 1; i >= 0; i--) // ���������� �����ߴ� numptr�� ��ҵ��� ���ʴ�� ����Ѵ�.
	{
		printf("%d", numarr[i]);
	}
	return 0;
}