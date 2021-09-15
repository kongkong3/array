// 전치 행렬 출력하기 - 1트 -2021.09.12
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
			matrix[i][j] = matrix[j][i]; // 이렇게 하면 martix의 전치행렬을 구해서 다시 matrix에 저장하므로 원본 데이터의 손실이 발생한다.
		}
	}
	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++)
	{
		for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++)
		{
			printf("%d ", matrix[i][j]);  // 손상된 matrix값이 나오게 된다. 
		}
		printf("\n");
	}
	return 0;
}
