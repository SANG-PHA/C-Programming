#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
private:
	static int idx;
public:
	MyStack(int c = 100) : BaseArray(c) {}

	//스택의 크기 반환
	int length() {
		return idx + 1; //idx는 인덱스 번호이므로 +1 값 리턴
	}

	int pop() {
		if (idx > -1) { //스택이 비어있지 않으면
			int item = get(idx);
			idx--;
			return item;
		}
		else {
			cout << "스택 비어있음" << endl;
			return 0;
		}
	}

	void push(int n) {
		if (idx < getCapacity()) { //스택이 꽉 차있지 않으면
			idx++;
			put(idx, n);
		}
		else cout << "스택 용량 초과" << endl;
	}

	//스택 용량 반환
	int capacity() {
		return getCapacity();
	}
};

int MyStack::idx = -1;

int main(void)
{
	MyStack mStack(100);
	int n;

	cout << "스택에 삽입할 5개의 정수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}

	cout << "스택 용량 : " << mStack.capacity() << ", 스택 크기 : " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다. >>  ";

	while (mStack.length() != 0) 
		cout << mStack.pop() << " ";
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;

	getchar();
	getchar();
	return 0;
}
