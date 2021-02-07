#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main()
{
	char s[SIZE], s2[SIZE];
	int ck,i;

	printf("문자열을 입력하시오(100자 이하) : ");
	gets(s);

	ck = strlen(s); //strlen()으로 ck에 입력받은 문자열길이 저장

	for (i = 0; i < ck; i++)
	{
		s2[i] = s[ck -1 -i]; //ck만큼 반복하여 문자열을 거꾸로 입력 
	}
	s2[ck] = NULL; //문자열의 끝을 표시하기위해 NULL입력

	printf("재배치된 문자열 : ");
	puts(s2);

	getch();
	return 0;
}
