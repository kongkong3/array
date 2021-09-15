// 전치행렬 구하기 - 2트 - 2021.09.12
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
	int param_matrix[5][5] = { 0 };  // matrix[5][5] 를 직접 변경하기 원본 데이터에 손실이 생겼다.
									 //고로 5X5 영행렬을 선언해 여기에 matrix의 전치행렬을 구해 복사한다. (원본데이터 손실 없음)

	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++)
	{
		for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++)
		{
			param_matrix[i][j] = matrix[j][i]; // param_matrix 에 matrix의 전치 행렬을 구해서 복사한다. 
			printf("%d ", param_matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}