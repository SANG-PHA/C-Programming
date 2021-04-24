#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Board{
private:
	static string name[SIZE];
	static string message[SIZE];
	static int idx; //배열 인덱스 번호
public:
	Board(){}
	void print(){
		cout << "*************Board*************" << endl;
		for (int i = 0; i < idx; i++){
			cout << i << ": " << name[i] << ":  " << message[i] << endl;
		}
		cout << endl;
	}

	void add(string name, string message){
		this->name[idx] = name;
		this->message[idx] = message;
		this->idx++;
	}
};

class Person{
private:
	string name;
	Board obj;
public:
	Person(string name = "default"){ this->name = name; }
	void write(){
		string message;

		cout << "Enter a message : ";
		getline(cin, message); //공백을 포함한 문자열을 입력받기 위해 getline사용
		obj.add(this->name, message);
	}

	void read(){
		obj.print();
	}
};

string Board::name[SIZE];
string Board::message[SIZE];
int Board::idx = 0; //Board 클래스 idx변수 초기화

int main(void)
{
	Person hong("Hong"), jeon("Jeon"), kim("Kim"), nam("Nam");

	hong.write();
	jeon.write();
	kim.read();
	kim.write();
	nam.read();
	nam.write();
	hong.read();
	jeon.read();

	getchar();

	return 0;
}
