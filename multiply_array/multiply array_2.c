// 배열의 곱셈 수행하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int x, y;
static int sum = 0;
int get_num(int x);
int get_num1(int y); // 배열을 선언하며 수를 입력할 수 없기에 수를 입력받는 함수를 선언하여 사용하였다. 

int main(void)
{
	int size1, size2, size3, size4;
	printf("첫 번째 m X n 행렬을 입력하세요: ");
	scanf("%d %d", &size1, &size2);
	int** numptr1 = malloc(sizeof(int*) * size1);
	for (int i = 0; i < size1; i++)
	{
		numptr1[i] = malloc(sizeof(int) * size2);
	}

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			numptr1[i][j] = get_num(x); // numptr의 각 요소들을 get_num 함수로 입력받는다. 
		}
		printf("\n");
	}
	printf("\n");

	printf("두 번째 m X n 행렬을 입력하세요: ");
	scanf("%d %d", &size3, &size4);
	int** numptr2 = malloc(sizeof(int*) * size3);
	for (int i = 0; i < size3; i++)
	{
		numptr2[i] = malloc(sizeof(int) * size4);
	}

	for (int i = 0; i < size3; i++)
	{
		for (int j = 0; j < size4; j++)
		{
			numptr2[i][j] = get_num1(y);
		}
		printf("\n");
	}
	printf("\n");

	if (size2 != size3)
	{
		printf("입력된 두개의 행렬은 곱할 수 없습니다."); // 행렬의 곱셈을 수행할 수 없는 경우를 명시한다.
	}
	else if (size2 == size3) // 이 경우에만 행렬의 곱셈을 수행할 수 있음
	{
		int** mulnumptr = malloc(sizeof(int*) * size1);

		for (int i = 0; i < size1; i++)
		{
			mulnumptr[i] = malloc(sizeof(int) * size4);
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size4; j++)
			{
				mulnumptr[i][j] = 0; // 행렬 두 개를 곱하면서 동시에 출력할 수는 없으므로 곱한 결과를 저장할 영행렬을 생성한다. 
			}
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size4; j++)
			{
				for (int b = 0; b < size2; b++) // 매개변수의 도입을 통해서 두 행렬의 곱셈을 수행한다.
				{
					mulnumptr[i][j] += numptr1[i][b] * numptr2[b][j]; // 행렬의 곱셈을 수행한다. 
				}
			}
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size4; j++)
			{
				printf("%d ", mulnumptr[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < size1; i++)
		{
			free(mulnumptr[i]);
		}
		free(mulnumptr); // malloc함수로 데이터를 할당받아 사용했다면 free함수를 통해서 데이터를 해제해야 한다. 
	}

	for (int i = 0; i < size1; i++)
	{
		free(numptr1[i]);
	}
	free(numptr1);

	for (int i = 0; i < size3; i++)
	{
		free(numptr2[i]);
	}
	free(numptr2);
	return 0;
}
int get_num(int x)
{
	scanf("%d", &x);
	return x;
}
int get_num1(int y)
{
	scanf("%d", &y);
	return y;
}