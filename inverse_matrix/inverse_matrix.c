// 정사각행렬의 역행렬 구하기(gauss-jordan 소거법 코딩)
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
static int x, y;
static int sum = 0;
double get_num(double x);
int main(void)
{
	double sum = 0;
	double row_size1, col_size1, row_size2, col_size2;
	printf("역행렬을 구하고자 하는 정사각행렬의 size를 입력하세요 : ");
	scanf("%lf %lf", &row_size1, &col_size1);
	row_size2 = row_size1;
	col_size2 = col_size1;

	double** numPtr1 = malloc(sizeof(double) * row_size1);
	for (int i = 0; i < row_size1; i++)
	{
		numPtr1[i] = malloc(sizeof(double) * col_size1);
	}
	for (int i = 0; i < row_size1; i++)
	{
		for (int j = 0; j < col_size1; j++)
		{
			numPtr1[i][j] = get_num(x); // get_num 함수로 numPtr1에 들어갈 값 입력받기
		}
		printf("\n");
	}

	double** numPtr2 = malloc(sizeof(double) * row_size2);
	for (int i = 0; i < row_size2; i++)
	{
		numPtr2[i] = malloc(sizeof(double) * col_size2);
	}
	for (int i = 0; i < row_size2; i++)
	{
		for (int j = 0; j < col_size2; j++)
		{
			if (i == j)
			{
				numPtr2[i][j] = 1;  // 역행렬을 구하고자 하는 행렬과 크기가 같은 단위행렬 생성하기.
			}
			else
				numPtr2[i][j] = 0;
		}
	}

	for (int p = 0; p < row_size1; p++)
	{
		if (p < row_size1 - 1)
		{
			if (numPtr1[p][p] != 0) // 역행렬을 구하고자 하는 행렬의 주대각선 성분이 1이 아니면, 1로 만들어야 함
			{
				double temp1 = 1 / numPtr1[p][p];
				for (int j = 0; j < col_size1; j++)
				{
					numPtr1[p][j] = temp1 * numPtr1[p][j]; // 역행렬을 구하고자 하는 행렬의 요소를 1로 만들고, 같은 열의 나머지 요소들도 같은 수를 곱해줌.
					numPtr2[p][j] = temp1 * numPtr2[p][j];
				}

				for (int i = p + 1; i < row_size1; i++) // numPtr1[p][p] 보다 아래쪽에 있는 요소를 점검해야 한다.
				{
					if (numPtr1[i][p] != 0) // 주대각선 요소를 제외한, 나머지 행의 요소들이 0이 아닐 경우
					{
						double temp2 = -(numPtr1[i][p] / numPtr1[p][p]); // leading 1을 제외한 나머지를 0으로 만들기 위해서 곱해야 하는 수 구하기.
						for (int j = 0; j < col_size1; j++)
						{
							numPtr1[i][j] = temp2 * numPtr1[p][j] + numPtr1[i][j];
							numPtr2[i][j] = temp2 * numPtr2[p][j] + numPtr2[i][j]; // leading 1을 만드는 과정.
						}
					}
				}
			}
		}
		if (p == row_size1 - 1) // 마지막 열의 경우, leading 1 아래의 요소가 없어서 과정을 생략했다.
		{
			if (numPtr1[p][p] != 0)
			{
				double temp1 = 1 / numPtr1[p][p];
				for (int j = 0; j < col_size1; j++)
				{
					numPtr1[p][j] = temp1 * numPtr1[p][j];
					numPtr2[p][j] = temp1 * numPtr2[p][j];
				}
			}

		}
	} // 여기까지가 가우스 소거법을 코드로 구현한 것

	for (int i = row_size1 - 1; i >= 0; i--)
	{
		for (int j = row_size1 - 1; j >= 0; j--)
		{
			if (j < i && numPtr1[j][i] != 0)
			{
				double temp = -numPtr1[j][i];
				for (int p = 0; p < row_size1; p++)
				{
					numPtr1[j][p] = temp * numPtr1[i][p] + numPtr1[j][p]; // 조건에 맞도록 leading 1 위의 0 아닌 원소를 0으로 만든다.
					numPtr2[j][p] = temp * numPtr2[i][p] + numPtr2[j][p];
				}
			}
			else
			{
				numPtr1[j][i] = numPtr1[j][i];
				numPtr2[j][i] = numPtr2[j][i]; // 요소를 0으로 바꾸어야 하는 경우가 아니면 그대로 요소를 유지한다.
			}
		}
	}
	
	printf("gauss-jordan 소거법으로 변환된 numPtr1 = \n");
	for (int i = 0; i < row_size1; i++) // numPtr1 출력하기
	{
		for (int j = 0; j < col_size1; j++)
		{
			printf("%10lf", numPtr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < row_size1; i++)
	{
		for (int j = 0; j < col_size1; j++)
		{
			sum += numPtr1[i][j]; // numPtr1이 단위행렬인지 아닌지를 체크한다.
		}
	}

	if (sum != row_size1) // 변환된 numPtr1 이 단위행렬이 아닌 경우
	{
		printf("주어진 행렬은 역행렬이 존재하지 않습니다.");
	}
	if (sum == row_size1) // 변환된 numPtr1 이 단위행렬인 경우
	{
		printf("입력한 행렬의 역행렬은 다음과 같습니다\n");
		for (int i = 0; i < row_size2; i++) 
		{
			for (int j = 0; j < col_size2; j++)
			{
				printf("%10lf", numPtr2[i][j]); // 역행렬 출력.
			}
			printf("\n");
		}
	}
	for (int i = 0; i < row_size1; i++)
	{
		free(numPtr1[i]);
	}
	free(numPtr1); // numPtr1 메모리 해제

	for (int j = 0; j < row_size2; j++)
	{
		free(numPtr2[j]);
	}
	free(numPtr2); // numPtr2 메모리 해제
	return 0;
}

double get_num(double x)
{
	scanf("%lf", &x);
	return x;
}
