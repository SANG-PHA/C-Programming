#include <stdio.h>
#include <stdlib.h>

int** create_pascal(int n);
void display_pascal(int *p[], int n);

int main(void)
{
	int n;

	printf("n을 입력하시오 : ");
	scanf("%d", &n);

	int(*table)[] = create_pascal(n); //create_pascal에서 반환된 2차원배열을 새로운 포인터변수 table에 저장

	display_pascal(table, n);

	free(table);
	getch();
	return 0;
}

int** create_pascal(int n)
{
	int **pas = NULL;
	int i, j;

	pas = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		pas[i] = (int *)malloc(sizeof(int) * i+1);
	} //2차원배열을 포인터변수로 동적메모리할당

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (j == 0)
				pas[i][j] = 1;
			else if (j == i)
				pas[i][j] = 1;
			else
				pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	} //파스칼 삼각형 각 인덱스 값 계산

	return pas;
}

void display_pascal(int *p[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			printf("%d ", p[i][j]); //출력
		}
		printf("\n");
	}
}
