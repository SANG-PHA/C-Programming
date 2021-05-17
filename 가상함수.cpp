#include <iostream>

using namespace std;

class A{
public:
	void func() { f(); }
	void f() { cout << "A::f() called" << endl; }
};

class B : public A {
public:
	void f(){ cout << "B::f() called" << endl; }
};

class C : public B {
public:
	void f() { cout << "C::f() called" << endl; }
};

int main(void)
{
	/*C c;
	A *pa;
	B *pb;

	pa = pb = &c;

	pa->func();*/
	A *pa = new A();
	B *pb = new B();
	C *pc = new C();

	pa->func();
	pb->func();
	pc->func();

	pa = pb = pc;

	pa->func();
	pb->func();
	pc->func();

	return 0;
}
