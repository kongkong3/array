// ��ġ��� ���ϱ� - 2Ʈ - 2021.09.12
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
	int param_matrix[5][5] = { 0 };  // matrix[5][5] �� ���� �����ϱ� ���� �����Ϳ� �ս��� �����.
									 //��� 5X5 ������� ������ ���⿡ matrix�� ��ġ����� ���� �����Ѵ�. (���������� �ս� ����)

	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++)
	{
		for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++)
		{
			param_matrix[i][j] = matrix[j][i]; // param_matrix �� matrix�� ��ġ ����� ���ؼ� �����Ѵ�. 
			printf("%d ", param_matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}