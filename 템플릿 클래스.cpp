#include <iostream>

using namespace std;

template <class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack() {
		tos = -1;
	}
	void push(T element) {
		tos++;
		data[tos] = element;
	}
	T pop() {
		T tmp = data[tos];
		tos--;
		return tmp;
	}
};

int main(void)
{
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char> *p = new MyStack<char>();
	p->push('a');
	cout << p->pop() << endl;

	delete p;

	return 0;
}
