#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void get_arr(int *a);
void initialize(int *a,int *ascending, int *descending);
void sort(int *a, int *ascending, int *descending);
void display(int *ascending, int *descending);

int main(void)
{
	int *a = NULL;
	int *ascending = NULL;
	int *descending = NULL;

	a = (int)malloc(SIZE * sizeof(int));
	ascending = (int)malloc(SIZE * sizeof(int));
	descending = (int)malloc(SIZE * sizeof(int)); //크기가 100인 배열 생성

	get_arr(a);
	initialize(a,ascending, descending);
	sort(a, ascending, descending);
	display(ascending, descending);

	free(a);
	free(ascending);
	free(descending);
	getch();
	return 0;
}

void get_arr(int *a)
{
	srand(time(NULL));

	printf("생성된 배열 : [");
	for (int i = 0; i < SIZE; i++){
		a[i] = (rand() % SIZE ) + 1; //배열에 난수 입력
		printf("%d ", a[i]);
	}
	printf("\b]\n\n");
}

void initialize(int *a,int* ascending, int *descending)
{
	ascending = a;
	descending = a; //ascending, descending배열을 a배열을 가르키게 초기화
}

void sort(int *a, int *ascending, int *descending)
{
	int i, j, min, max, index, check[SIZE] = { NULL };

	//ascending 정렬
	for (i = 0; i < SIZE; i++){
		min = 101; //초기 최솟값을 모든 값보다 큰 값으로 초기화
		index = 0;
		for (j = 0; j < SIZE; j++){
			if (a[j] < min){ 
				if (check[j] != 1){ //이미 정렬된 최솟값이 아니면
					min = a[j]; //최솟값 저장
					index = j; //인덱스값 저장
				}
			}
		}
		check[index] = 1; //중복 방지를 위해 정렬된 인덱스번호에 1 저장
		ascending[i] = a[index]; //ascending 정렬
	}

	for (int k = 0; k < SIZE; k++)
		check[k] = 0; //check배열 초기화

	//descending 정렬
	for (i = 0; i < SIZE; i++){
		max = 0; 
		index = 0;
		for (j = 0; j < SIZE; j++){
			if (a[j] > max){
				if (check[j] != 1){ 
					max = a[j]; 
					index = j; 
				}
			}
		}
		check[index] = 1; 
		descending[i] = a[index]; 
	}
}

void display(int *ascending, int *descending)
{
	printf("ascending배열 : [");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", ascending[i]);
	}
	printf("\b]\n\n");

	printf("descending배열 : [");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", descending[i]);
	}
	printf("\b]\n");
}
