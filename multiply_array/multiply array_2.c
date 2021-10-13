// �迭�� ���� �����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int x, y;
static int sum = 0;
int get_num(int x);
int get_num1(int y); // �迭�� �����ϸ� ���� �Է��� �� ���⿡ ���� �Է¹޴� �Լ��� �����Ͽ� ����Ͽ���. 

int main(void)
{
	int size1, size2, size3, size4;
	printf("ù ��° m X n ����� �Է��ϼ���: ");
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
			numptr1[i][j] = get_num(x); // numptr�� �� ��ҵ��� get_num �Լ��� �Է¹޴´�. 
		}
		printf("\n");
	}
	printf("\n");

	printf("�� ��° m X n ����� �Է��ϼ���: ");
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
		printf("�Էµ� �ΰ��� ����� ���� �� �����ϴ�."); // ����� ������ ������ �� ���� ��츦 ����Ѵ�.
	}
	else if (size2 == size3) // �� ��쿡�� ����� ������ ������ �� ����
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
				mulnumptr[i][j] = 0; // ��� �� ���� ���ϸ鼭 ���ÿ� ����� ���� �����Ƿ� ���� ����� ������ ������� �����Ѵ�. 
			}
		}

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size4; j++)
			{
				for (int b = 0; b < size2; b++) // �Ű������� ������ ���ؼ� �� ����� ������ �����Ѵ�.
				{
					mulnumptr[i][j] += numptr1[i][b] * numptr2[b][j]; // ����� ������ �����Ѵ�. 
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
		free(mulnumptr); // malloc�Լ��� �����͸� �Ҵ�޾� ����ߴٸ� free�Լ��� ���ؼ� �����͸� �����ؾ� �Ѵ�. 
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