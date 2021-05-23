#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	//cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	//cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	//cout << "소멸자 실행 radius = " << radius << endl;
}

//함수원형
void getData(vector<Circle> &v, Circle p);
void display(vector<Circle> v);
bool compare(Circle a, Circle b);
void sortData(vector<Circle> &v);

int main(void)
{
	/*Circle *p, *q;
	p = new Circle();
	q = new Circle(30);
	Circle r;

	p->setRadius(10);

	cout << p->getArea() << endl << q->getArea() << endl;

	delete p;
	delete q;*/

	vector<Circle> vec;

	/*Circle *p;

	int r;

	do {
	cout << "반지름 : ";
	cin >> r;
	if (radius > 0){
	p = new Circle(r);
	cout << "면적 : " << p->getArea() << endl;
	delete p;
	}
	} while (r != -1);*/

	for (int i = 1; i < 4; i++) {
		Circle a;
		a.setRadius(5 - i);
		getData(vec, a);
	}

	sortData(vec);
	display(vec);


	return 0;
}

void getData(vector<Circle> &v, Circle p)
{
	v.push_back(p);
}

void display(vector<Circle> v)
{
	for (Circle e : v)
		cout << "면적 : " << e.getArea() << endl;
}

bool compare(Circle a, Circle b) {
	return a.getArea() < b.getArea();
}

void sortData(vector<Circle> &v) {
	sort(v.begin(), v.end(), compare);
}
