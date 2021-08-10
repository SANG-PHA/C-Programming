#include <stdio.h>
#include <stdlib.h>

int remove_zeros();

int main(void)
{
	int *p = (int*)malloc(sizeof(int) * 10); //정수형 포인터에 동적 메모리 할당
	int arr[10] = { 1, 2, 3, 0, 0, 5, 6, 0, 7, 0 }; //정수 배열 초기화
	p = arr; //p는 arr을 가리키도록 설정

	printf("초기 배열 : ");
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", p[i]); //출력
	}

	int n = remove_zeros(p, 10);

	p = (int*)malloc(sizeof(int) * n); //새로운 배열을 가리킬 포인터에 동적 메모리 할당
	p = arr;

	printf("\n바뀐 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]); //출력

	p = NULL;
	free(p);
	getch();
	return 0;
}

int remove_zeros(int *p, int n)
{
	int i, j, num_of_zero = 0;
	for (i = 0; i < n; i++)
	{
		if (p[i] == 0) //해당 인덱스 값이 0 이면
		{
			for (j = i; j < n - 1 - num_of_zero; j++)
				p[j] = p[j + 1]; //하나씩 앞으로 당겨준다
			p[n - 1 - num_of_zero] = 99; //마지막 인덱스에 99 입력
			num_of_zero++; //찾은 0의 개수 1 증가
			i--;
		}
	}
	p = NULL;
	free(p);
	return n - num_of_zero; //0을 제거한 배열의 크기 반환
}
