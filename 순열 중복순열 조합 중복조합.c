#include <iostream>

/*완전탐색과 동적계획법을 사용하여 문제 해결*/

using namespace std;

#define SIZE 10

//함수 원형
void permutation(int level);
void combination(int level, int next);
void repeated_perm(int level);
void repeated_com(int level, int next);

//전역변수
int n, r;
int element[SIZE]; //각 함수 완전 탐색에 쓰일 배열
int selected_element[SIZE]; //순열에서 중복되는 값 출력을 방지하는 배열

int main(void)
{
	char repeat;

	cout << "n?";
	cin >> n;
	cout << "r?";
	cin >> r;
	cout << "duplicate?(Y/N)";
	cin >> repeat;

	if (repeat == 'Y'){
		cout << "r - Repeat Permutation" << endl;
		repeated_perm(0);
		cout << "r - Repeated Combination" << endl;
		repeated_com(0, 1);
	}
	else{
		cout << "r - Permutation" << endl;
		permutation(0);
		cout << "r - Combination" << endl;
		combination(0, 1);
	}

	cin.get();
	return 0;
}

void permutation(int level)
{
	//종료 조건
	//완전탐색 마지막 단계에 도달하면 출력한다.
	if (level == r){
		for (int i = 0; i < level; i++)
			cout << element[i];
		cout << endl;
		return;
	}

	//재귀함수 반복
	//데이터 입력
	for (int i = 1; i <= n; i++){

		//해당 원소가 이미 선택되었다면 건너뛴다
		if (selected_element[i])
			continue;
		selected_element[i] = 1; //원소가 선택되었다는 사실을 추가한다

		element[level] = i;
		permutation(level + 1);
		selected_element[i] = 0; //다음 반복문 진행 시 영향을 주지 않기 위해 초기화
	}
}

void combination(int level, int next)
{
	//종료 조건
	//완전탐색 마지막 단계에 도달하면 출력한다.
	if (level == r){
		for (int i = 0; i < level; i++)
			cout << element[i];
		cout << endl;
		return;
	}

	//재귀함수 반복
	//데이터 입력
	for (int i = next; i <= n; i++){
		element[level] = i;
		combination(level + 1, i + 1); //이번 단계에서 추가한 원소보다 큰 값만 추가하기위해
									   //combination함수에 (현재 원소 + 1) 을 매개변수로 넘겨준다
	}
}

void repeated_perm(int level)
{
	//종료 조건
	//완전탐색 마지막 단계에 도달하면 출력한다.
	if (level == r){
		for (int i = 0; i < level; i++)
			cout << element[i];
		cout << endl;
		return;
	}

	//재귀함수 반복
	//데이터 입력
	for (int i = 1; i <= n; i++){
		element[level] = i;
		repeated_perm(level + 1);
	}
}

void repeated_com(int level, int next)
{
	//종료 조건
	//완전탐색 마지막 단계에 도달하면 출력한다.
	if (level == r){
		for (int i = 0; i < level; i++)
			cout << element[i];
		cout << endl;
		return;
	}

	//재귀함수 반복
	//데이터 입력
	for (int i = next; i <= n; i++){
		element[level] = i;
		combination(level + 1, i);
	}
}
