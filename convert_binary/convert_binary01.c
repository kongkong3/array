//10진수를 2진수로 변환하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int j = 0;
int main(void)
{
	int digit, binary = 0;
	int numarr[30] = { 0 };
	printf("변환하고자 하는 10진수를 입력해 주세요:\n");
	scanf("%d", &digit);
	for (int i = 0; digit > 0; i++) // 이렇게 digit 을 digit > 0 과 같이 설정해두면 digit 이 0이 되는 순간 반복문을 탈출한다.
	{
		numarr[i] = digit % 2;
		digit = digit / 2;
		j += 1;
	}
	for (int i = j - 1; i >= 0; i--) // 순차적으로 저장했던 numptr의 요소들을 차례대로 출력한다.
	{
		printf("%d", numarr[i]);
	}
	return 0;
}