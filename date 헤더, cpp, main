main.cpp

#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	
	Date birth(2014, 3, 20); // 2014년 3월 20일
	Date independenceDay("1945/8/15"); // 1945년 8월 15일
	// string 클래스에서 제공하는 함수 이용할 것.

	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;

}



Date.h

#include <iostream>
#include <string>

using namespace std;
//Date 클래스 선언부
class Date {
private:
	int year, month, day;
public:
	Date(int a, int b, int c);
	Date(string a);

	//멤버함수 선언
	void show();
	int getYear();
	int getMonth();
	int getDay();
};



Date.cpp

#include "Date.h"

//Date 클래스 구현부
//2가지 생성자 구현
Date::Date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}

//string 클래스 멤버함수인 erase와 find를 사용하여 문자열을 분리하였고 stoi함수를 사용하여 정수형으로 변환시킨다
Date::Date(string a) {
	year = stoi(a);
	a.erase(0, a.find("/") + 1);
	month = stoi(a);
	a.erase(0, a.find("/") + 1);
	day = stoi(a);
}

void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}



