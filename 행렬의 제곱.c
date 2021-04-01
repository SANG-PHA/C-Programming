#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int m,n;
	int i, j, q, pow = 1;
	srand(time(NULL));

	printf("m,n을 입력하시오 : ");
	scanf("%d %d", &m, &n);

	int **A = NULL, **An = NULL, **Atmp = NULL;

	//A,An행렬 구현을 위해 2중 포인터 동적할당
	A = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		A[i] = (int*)malloc(sizeof(int) * m);

	An = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		An[i] = (int*)malloc(sizeof(int) * m);

	Atmp = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		Atmp[i] = (int*)malloc(sizeof(int) * m);


	//A행렬 값 입력 및 출력
	printf("행렬 A\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			A[i][j] = rand() % 3;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//An행렬 초기화
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			An[i][j] = A[i][j];

	//An행렬 값 계산
	while (pow < n){
		for (i = 0; i < m; i++){
			for (j = 0; j < m; j++){
				Atmp[i][j] = 0;
				for (q = 0; q < m; q++)
					Atmp[i][j] += An[i][q] * A[q][j];
			}
		}

		for (i = 0; i < m; i++)
			for (j = 0; j < m; j++)
				An[i][j] = Atmp[i][j];
		pow++;
	}

	//An행렬 출력
	printf("행렬An\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			printf("%d ", An[i][j]);
		}
		printf("\n");
	}

	getch();
	return 0;
}
