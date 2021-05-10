#include <iostream>

using namespace std;

class A {
public:
	A(int x) { cout << "생성자 A " << x << endl; }
	~A() { cout << "소멸자 A" << endl; }
};

class B : public A {
public:
	B() : A(20) {
		cout << "생성자 B " << endl;
	}
	B(int x) : A(20 + x) { 
		cout << "생성자 B " << x << endl; 
	}
	~B() { cout << "소멸자 B" << endl; }
};

int main(void)
{
	B obj;

	return 0;
}
