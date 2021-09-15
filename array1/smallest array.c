// 가장 작은 수 출력하기(배열 이용) - 2021.09.02
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int numarr[5] = { 0 };
	printf("숫자 5개를 입력해 주세요 단, 입력 후에는 엔터를 누르세요.\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numarr[i]);
	}
	int snum = numarr[0]; // 가장 작은 수를 저장하는 snum선언. 무조건 배열의 첫번째 요소의 값을 기준점으로 삼는다.
	for (int j = 0; j < 4; j++)
	{
		if (snum - numarr[j] < 0)
			snum = snum;
		else if (snum - numarr[j] > 0)
			snum = numarr[j];  // 초기의 snum값에서 순차적으로 비교하며 snum값을 갱신한다

	}
	printf("가장 작은 수 = %d", snum);
	return 0;
}
