#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//학생 클래스 정의
class student
{
private:
	string name;
	double marks;
public:
	student();
	student(string n, double m) : name{ n }, marks{ m } {};
	string getName();
	double getMarks();
};

string student::getName() {
	return name;
}

double student::getMarks() {
	return marks;
}

bool compare(student &p, student &q); //compare 함수원형

int main(void)
{
	vector<student> arr;

	string n;
	double m;

	//학생 정보 입력
	cout << "========================================" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "이름 : ";
		cin >> n;
		cout << "학점 : ";
		cin >> m;
		arr.push_back(student(n,m));
	}
	cout << "========================================" << endl;

	//정렬
	sort(arr.begin(), arr.end(), compare);

	cout << "========================================" << endl;
	for (student p : arr) {
		cout << "이름 : " << p.getName() << endl;
		cout << "학점 : " << p.getMarks() << endl;
	}
	cout << "========================================" << endl;
	return 0;
}

bool compare(student &p, student &q)
{
	return p.getMarks() < q.getMarks();
}
