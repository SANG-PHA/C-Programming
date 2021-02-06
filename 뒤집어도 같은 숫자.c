#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, num, *p = NULL, tmp, check = 0, same = 0, weighted_num;

	printf("양의 정수를 입력하시오 : ");
	scanf("%d", &num);

	weighted_num = num;
	for (i = 1; weighted_num >= 10; i = 10)
	{
		weighted_num = weighted_num / i;
		check++;
	} //입력받은 수의 자릿수 계산

	p = (int *)malloc(check * sizeof(int)); //배열 동적할당

	for (i = 0; i < check; i++)
	{
		tmp = num % 10;
		p[i] = tmp;
		num = num / 10;
	} //뒤집어도 같은숫자인지 확인하기위해 배열의 각 인덱스에 각 자릿수 입력


	for (i = 0; i < check / 2; i++)
	{
		if (p[i] != p[check - 1 - i]) //배열의 인덱스는 0부터 시작하므로 check에서 -1
		{
			same = 1;
			break; //맨 앞과 맨 뒤의 숫자를 비교하여 같지않다면 same=1, 반복문break
		}
	}

	if (same == 1)
		printf("뒤집어도 같은 숫자가 아닙니다.");
	else printf("뒤집어도 같은 숫자입니다.");

	free(p); //동적메모리 반납
	getch();
	return 0;
}
