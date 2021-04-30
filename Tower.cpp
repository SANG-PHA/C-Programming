Tower.h

#include <iostream>

using namespace std;
//Tower 클래스 선언부
class Tower {
private:
	int height;
public:
	Tower();
	Tower(int r);
	int getHeight();
};


Tower.cpp

#include "Tower.h"

//Tower 클래스 구현부
//2가지 생성자 구현
Tower::Tower() {
	height = 1;
}

Tower::Tower(int r) {
	height = r;
}

//getHeight() 함수 구현
int Tower::getHeight() {
	return height;
}



main.cpp

#include <iostream>
#include "Tower.h"
using namespace std;

int main() {
	Tower myTower; // 1 미터
	Tower seoulTower(100); // 100 미터

	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
