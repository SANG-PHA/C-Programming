#include <stdio.h>

#define TRUE 1
#define FALSE 0

int search(int a[], int n, int val);

int main(void)
{
	int a[20] = { 1, 3, 5, 8, 10, 11, 12, 13, 18, 20, 22, 28, 31, 32, 33, 39, 45, 47, 49, 50 }; //오름차순으로 정렬된 배열로 초기화

	//배열 출력
	printf("배열 : ");
	for (int i = 0; i < 20; i++)
		printf("%d ", a[i]);

	int val = 21;
	int result = search(a, 20, val);
	printf("\n찾을 값 : %d", val);

	if (result == TRUE)
		printf("\n결과 : 찾았습니다.");
	else printf("\n결과 : 못찾았습니다.");

	getch();
	return 0;
}

int search(int a[], int n, int val)
{
	int i = 0; //배열 시작 인덱스 번호
	int j = n - 1; //배열 마지막 인덱스 번호
	int m; //중간 인덱스 번호를 저장할 변수

	while (i <= j){
		m = (i + j) / 2;
		if (a[m] == val) //중간값과 비교
			return TRUE;
		else if (a[m] < val) //중간값보다 찾아야할 숫자가 크다면
			i = m + 1; //시작 인덱스 = m + 1
		else //중간값보다 찾아야할 숫자가 작다면
			j = m - 1; //마지막 인덱스 = m - 1
	}
	return FALSE;
}
