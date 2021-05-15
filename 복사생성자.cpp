#include <iostream>

using namespace std;

class MyArray {
public:
	int size;
	int* data;

	MyArray(int size) {
		cout << "생성자 진입" << endl;
		this->size = size;
		data = new int[size];
	}

	MyArray(const MyArray& a) {
		cout << "복사생성자 진입" << endl;
		size = a.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}

	~MyArray() {
		cout << "소멸자 진입" << endl;
		if (data != NULL) delete[] this->data;
	}
};

int main(void)
{
	MyArray buffer(10);
	buffer.data[0] = 1;
	{
		MyArray clone = buffer;
	}
	buffer.data[0] = 2;

	return 0;
}
