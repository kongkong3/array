// ���� ���� �� ����ϱ�(�迭 �̿�) - 2021.09.02
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int numarr[5] = { 0 };
	printf("���� 5���� �Է��� �ּ��� ��, �Է� �Ŀ��� ���͸� ��������.\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numarr[i]);
	}
	int snum = numarr[0]; // ���� ���� ���� �����ϴ� snum����. ������ �迭�� ù��° ����� ���� ���������� ��´�.
	for (int j = 0; j < 4; j++)
	{
		if (snum - numarr[j] < 0)
			snum = snum;
		else if (snum - numarr[j] > 0)
			snum = numarr[j];  // �ʱ��� snum������ ���������� ���ϸ� snum���� �����Ѵ�

	}
	printf("���� ���� �� = %d", snum);
	return 0;
}
