#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define RAND_MAX 32767

class Random{
	//클래스 선언부
public:
	Random();
	int next();
	int nextInRange(int a, int b);

};

//클래스 구현부
Random::Random(){
	//아무것도 하지 않음
}

//0~ RAND_MAX 범위의 정수 반환
int Random::next(){
	return rand() % RAND_MAX;
}

int Random::nextInRange(int a, int b){
	return (rand() % (a + 1)) + (b - a);
}

int main() {
	srand(time(NULL)); //시드값 설정

	Random r;

	cout << "-- 0 ~ " << RAND_MAX << " number of 10 random int" << endl;

	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}

	cout << endl << endl << "-- 2 ~ " << "4 number of 10 random int --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;

	return 0;

	

}
