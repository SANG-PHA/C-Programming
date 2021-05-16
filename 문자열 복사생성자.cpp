#include<string.h>
#include<iostream>
using namespace std;

class Book {
	char *title;
	int price;
public:
	Book(const char * title, int price) {
		this->title = new char[strlen(title) + 1];
		for (int i = 0; i < strlen(title) + 1; i++)
			this->title[i] = title[i];
		this->price = price;
	}

	Book(Book &b) {
		price = b.price;
		title = new char[strlen(b.title) + 1];
		for (int i = 0; i < strlen(title) + 1; i++)
			this->title[i] = b.title[i];
	}
	~Book(){
		if(title != nullptr) delete[] title;
	}
	void set(const char* title, int price) {
		if (this->title != nullptr) {
			delete[] this->title; //할당된 메모리가 있다면 delete
			this->title = new char[strlen(title) + 1]; //새로운 메모리 할당
		}

		for (int i = 0; i < strlen(title) + 1; i++)
			this->title[i] = title[i];

		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};

int main() {
	Book cpp("Good C++", 10000);
	Book java = cpp;

	java.set("Excellent Java", 12000);
	cpp.show();
	java.show();

	return 0;
}
