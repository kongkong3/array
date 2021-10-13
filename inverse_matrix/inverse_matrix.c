// ���簢����� ����� ���ϱ�(gauss-jordan �ҰŹ� �ڵ�)
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
	printf("������� ���ϰ��� �ϴ� ���簢����� size�� �Է��ϼ��� : ");
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
			numPtr1[i][j] = get_num(x); // get_num �Լ��� numPtr1�� �� �� �Է¹ޱ�
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
				numPtr2[i][j] = 1;  // ������� ���ϰ��� �ϴ� ��İ� ũ�Ⱑ ���� ������� �����ϱ�.
			}
			else
				numPtr2[i][j] = 0;
		}
	}

	for (int p = 0; p < row_size1; p++)
	{
		if (p < row_size1 - 1)
		{
			if (numPtr1[p][p] != 0) // ������� ���ϰ��� �ϴ� ����� �ִ밢�� ������ 1�� �ƴϸ�, 1�� ������ ��
			{
				double temp1 = 1 / numPtr1[p][p];
				for (int j = 0; j < col_size1; j++)
				{
					numPtr1[p][j] = temp1 * numPtr1[p][j]; // ������� ���ϰ��� �ϴ� ����� ��Ҹ� 1�� �����, ���� ���� ������ ��ҵ鵵 ���� ���� ������.
					numPtr2[p][j] = temp1 * numPtr2[p][j];
				}

				for (int i = p + 1; i < row_size1; i++) // numPtr1[p][p] ���� �Ʒ��ʿ� �ִ� ��Ҹ� �����ؾ� �Ѵ�.
				{
					if (numPtr1[i][p] != 0) // �ִ밢�� ��Ҹ� ������, ������ ���� ��ҵ��� 0�� �ƴ� ���
					{
						double temp2 = -(numPtr1[i][p] / numPtr1[p][p]); // leading 1�� ������ �������� 0���� ����� ���ؼ� ���ؾ� �ϴ� �� ���ϱ�.
						for (int j = 0; j < col_size1; j++)
						{
							numPtr1[i][j] = temp2 * numPtr1[p][j] + numPtr1[i][j];
							numPtr2[i][j] = temp2 * numPtr2[p][j] + numPtr2[i][j]; // leading 1�� ����� ����.
						}
					}
				}
			}
		}
		if (p == row_size1 - 1) // ������ ���� ���, leading 1 �Ʒ��� ��Ұ� ��� ������ �����ߴ�.
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
	} // ��������� ���콺 �ҰŹ��� �ڵ�� ������ ��

	for (int i = row_size1 - 1; i >= 0; i--)
	{
		for (int j = row_size1 - 1; j >= 0; j--)
		{
			if (j < i && numPtr1[j][i] != 0)
			{
				double temp = -numPtr1[j][i];
				for (int p = 0; p < row_size1; p++)
				{
					numPtr1[j][p] = temp * numPtr1[i][p] + numPtr1[j][p]; // ���ǿ� �µ��� leading 1 ���� 0 �ƴ� ���Ҹ� 0���� �����.
					numPtr2[j][p] = temp * numPtr2[i][p] + numPtr2[j][p];
				}
			}
			else
			{
				numPtr1[j][i] = numPtr1[j][i];
				numPtr2[j][i] = numPtr2[j][i]; // ��Ҹ� 0���� �ٲپ�� �ϴ� ��찡 �ƴϸ� �״�� ��Ҹ� �����Ѵ�.
			}
		}
	}
	
	printf("gauss-jordan �ҰŹ����� ��ȯ�� numPtr1 = \n");
	for (int i = 0; i < row_size1; i++) // numPtr1 ����ϱ�
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
			sum += numPtr1[i][j]; // numPtr1�� ����������� �ƴ����� üũ�Ѵ�.
		}
	}

	if (sum != row_size1) // ��ȯ�� numPtr1 �� ��������� �ƴ� ���
	{
		printf("�־��� ����� ������� �������� �ʽ��ϴ�.");
	}
	if (sum == row_size1) // ��ȯ�� numPtr1 �� ��������� ���
	{
		printf("�Է��� ����� ������� ������ �����ϴ�\n");
		for (int i = 0; i < row_size2; i++) 
		{
			for (int j = 0; j < col_size2; j++)
			{
				printf("%10lf", numPtr2[i][j]); // ����� ���.
			}
			printf("\n");
		}
	}
	for (int i = 0; i < row_size1; i++)
	{
		free(numPtr1[i]);
	}
	free(numPtr1); // numPtr1 �޸� ����

	for (int j = 0; j < row_size2; j++)
	{
		free(numPtr2[j]);
	}
	free(numPtr2); // numPtr2 �޸� ����
	return 0;
}

double get_num(double x)
{
	scanf("%lf", &x);
	return x;
}
