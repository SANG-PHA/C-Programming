#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 20
int arr[n];
int arr2[n]; //정렬해야 할 배열 선언

int bubble_sort();
int insert_sort();

int main(void)
{
	srand(time(NULL)); //시드값 설정

	//배열 초기화
	printf("초기 배열 : ");
	for (int i = 0; i < n; i++){
		arr[i] = rand() % 100;
		arr2[i] = arr[i]; //같은 배열을 정렬해야 하므로 값을 똑같이 입력해준다.
		printf("%d ", arr[i]);
	}

	//카운트 변수 선언, 초기화
	int bubble_cnt = 0;
	int insert_cnt = 0;

	bubble_cnt = bubble_sort();
	insert_cnt = insert_sort();

	printf("\n정렬된 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n버블 정렬에 사용된 비교 횟수 : %d", bubble_cnt);

	printf("\n정렬된 배열 : ");
	for (int i = 0; i < n; i++)#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define n 30 //배열의 크기 선언
		int arr[n] = { 0, 1, 4, 5, 7, 8, 9, 10, 15, 20, 21, 25, 26, 27, 29, 32, 36, 37, 38, 39, 40, 41, 42, 46, 48, 49, 53, 58, 59, 60 }; //정렬된 배열 선언


	int linear_search(int val, int* is_find, int* index);
	int binary_search(int val, int* is_find, int* index);

	int main(void)
	{
		int val; //찾아야 할 숫자
		int lin_cnt, bin_cnt; //각 탐색의 비교횟수를 저장할 변수
		int is_find = FALSE; //탐색 성공,실패를 저장하는 boolean변수
		int index = 0; //찾을 숫자가 저장된 인덱스번호를 저장하는 변수

		printf("찾을 수를 입력하시오 : ");
		scanf("%d", &val);

		lin_cnt = linear_search(val, &is_find, &index);

		///////////////////////////////////////////////////////////////////////
		if (is_find == TRUE)
			printf("선형탐색에 성공했습니다.\n저장된 인덱스 번호 : %d\n", index);
		else
			printf("선형탐색에 실패했습니다.\n");
		printf("실행된 비교 횟수 : %d\n", lin_cnt);
		//////////////////////////////////////////////////////////////////////


		bin_cnt = binary_search(val, &is_find, &index);
		//////////////////////////////////////////////////////////////////////
		if (is_find == TRUE)
			printf("이진탐색에 성공했습니다.\n저장된 인덱스 번호 : %d\n", index);
		else
			printf("이진탐색에 실패했습니다.\n");
		printf("실행된 비교 횟수 : %d", bin_cnt);
		//////////////////////////////////////////////////////////////////////

		getch();
		return 0;
	}

	int linear_search(int val, int* is_find, int* index)
	{
		int count = 0;

		for (int i = 0; i < n; i++){

			count++; //비교 횟수 증가

			if (arr[i] == val){ //찾았을 때
				*is_find = TRUE;
				*index = i;
				return count;
			}
		}

		return count; //못찾았을 때
	}

	int binary_search(int val, int* is_find, int* index)
	{
		*is_find = FALSE; //boolean변수 초기화

		int count = 0;
		int i, j, m; //시작 인덱스, 마지막 인덱스, 중간 인덱스 변수 선언

		i = 0; //시작 인덱스 초기화
		j = n - 1; //마지막 인덱스 초기화

		while (i <= j){
			count++; //비교 횟수 증가

			m = (i + j) / 2; //중간 인덱스 설정

			if (val == arr[m]){ //찾았을 때
				*index = m;
				*is_find = TRUE;
				return count;
			}
			else if (val > arr[m]) //찾아야 하는 값이 중간값 보다 클 때
				i = m + 1; //시작인덱스 설정
			else //찾아야 하는 값이 중간값 보다 작을 때
				j = m - 1; //마지막 인덱스 설정
		}

		return count; //못찾았을 때
	}
		printf("%d ", arr2[i]);
	printf("\n삽입 정렬에 사용된 비교 횟수 : %d", insert_cnt);

	getch();
	return 0;
}

int bubble_sort()
{
	int tmp = 0;
	int count = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++){ //이미 정렬된 인덱스는 제외하기 때문에 j < n-1-i
			count++; //비교 횟수 증가
			if (arr[j + 1] < arr[j]){ //정렬해야 할 경우
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	return count;
}

int insert_sort()
{
	int count = 0;
	int tmp;

	for (int i = 1; i < n; i++){
		tmp = arr2[i];
		int j = i;
		while (j > 0 && arr2[j - 1] > tmp){ //비교할 인덱스의 앞에 위치해 있는 인덱스 값들을 한 칸씩 밀어준다.
			count++; //비교 횟수 증가
			arr2[j] = arr2[j - 1];
			j--;
		}
		arr2[j] = tmp; //삽입
	}

	return count;
}
