#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int m;
	int i, j, q;
	srand(time(NULL));

	printf("m을 입력하시오 : ");
	scanf("%d",&m);

	int **A = NULL, **An = NULL;
	
	//A,An행렬 구현을 위해 2중 포인터 동적할당
	A = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		A[i] = (int*)malloc(sizeof(int) * m);

	An = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		An[i] = (int*)malloc(sizeof(int) * m);
	

	//A행렬 값 입력 및 출력
	printf("행렬 A\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			A[i][j] = rand() % 4;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//An행렬 값 계산
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			An[i][j] = 0;
			for (q = 0; q < m; q++)
				An[i][j] += A[i][q] * A[q][j];
		}
	}

	//AB행렬 출력
	printf("행렬An\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			printf("%d ",An[i][j]);
		}
		printf("\n");
	}

	getch();
	return 0;
}
