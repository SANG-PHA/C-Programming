main.cpp////////////////

#include <iostream>
#include "family.h"

int main() {
	int n;
	string last, first;

	cout << "성 : ";
	cin >> last;
	cout << "인원 : ";
	cin >> n;

	family *obj = new family(last, n);

	for (int i = 0; i < n; i++) {
		cout << "이름 : ";
		cin >> first;
		obj->setName(i, first);
	}
	
	obj->print();
	delete obj;

	return 0;
}




person.h////////////////

#pragma once
#include <iostream>
#include <string>

using namespace std;

class person {
	string name;
public:
	person();
	person(string name);
	string getName();
	void setName(string name);
};


person.cpp//////////////

#include "person.h"

person::person() {}
person::person(string name) {
	this->name = name;
}
string person::getName() {
	return name;
}
void person::setName(string name) {
	this->name = name;
}


family.h///////////////

#pragma once
#include "person.h"

using namespace std;

class family {
	string className;
	person *p;
	int size;
public:
	family(string name, int size);
	void setName(int idx, string name);
	void print();
	~family();
};

family.cpp/////////////

#include "family.h"

family::family(string name, int size) {
	this->size = size;
	p = new person[size];
	className = name;
}
void family::setName(int idx, string name) {
	p[idx].setName(name);
}
void family::print() {
	cout << className << "가족은 다음과 같이" << this->size << "명 입니다" << endl;
	for (int i = 1; i <= size; i++) {
		cout << p[i - 1].getName() << className << "     ";
	}
}
family::~family() {
	delete []p;
}
