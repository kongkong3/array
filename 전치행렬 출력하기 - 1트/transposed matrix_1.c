// ��ġ ��� ����ϱ� - 1Ʈ -2021.09.12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int matrix[5][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++)
	{
		for (int j = 0; j < sizeof(matrix[0]) / sizeof(int) && j >= i; j++)
		{
			matrix[i][j] = matrix[j][i]; // �̷��� �ϸ� martix�� ��ġ����� ���ؼ� �ٽ� matrix�� �����ϹǷ� ���� �������� �ս��� �߻��Ѵ�.
		}
	}
	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++)
	{
		for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++)
		{
			printf("%d ", matrix[i][j]);  // �ջ�� matrix���� ������ �ȴ�. 
		}
		printf("\n");
	}
	return 0;
}
