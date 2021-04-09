//모듈화 프로그래밍 하려했으나 다른 모듈간 클래스 교차참조 과정에서 오류가 발생하여
//부득이하게 하나의 cpp파일로 수정하였습니다.
//죄송합니다 ㅜㅜ

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

class client{
public:
	//멤버 변수
	struct member //회원 구조체 
	{
		string name; //이름
		int age; //나이
		int phone; //핸드폰 번호
		string residence; //거주지
		string id;
		string pw;
		string cat; //마지막으로 빌린 책의 카테고리
	};
	static vector<member> members;

	//멤버 함수
	void menu(); //메뉴 출력
	void sign(); //회원가입
	void information(); //가입된 회원들의 정보 출력
};

struct meroDate //책의 대여일, 반납일 구조체
{
	int mm, dd, yy;
};

class book{
public:
	//멤버 변수
	//상속을 위해 멤버변수의 접근지정자를 public으로 설정
	struct information{
		int id; //id
		string name; //책 이름
		string Author; //저자 이름
		int quantity; //수량
		struct meroDate issued;
		struct meroDate duedate;
		string clent_name; //책을 빌려간 회원의 이름
	};
	static vector<information> issued_book; //대여된 책을 위한 static벡터

	//멤버 함수
	//자식 클래스마다 다른 information 벡터와 book_count 사용을 위해 가상함수 사용
	virtual void addbooks() = 0;
	virtual void deletebooks() = 0;
	virtual void searchbooks() = 0;
	virtual void issuebook() = 0;

};



class computer : public book{
public:
	//멤버 변수
	static vector<information> books; //책의 정보를 저장할 벡터
	static int book_count; //현재 카테고리에 포함된 책의 수

	//멤버 함수
	void addbooks();
	void deletebooks();
	void searchbooks();
	void issuebook();
};



class civil : public book{
public:
	//멤버 변수
	static vector<information> books;
	static int book_count;

	//멤버 함수
	void addbooks();
	void deletebooks();
	void searchbooks();
	void issuebook();
};



class electronic : public book{
public:
	//멤버 변수
	static vector<information> books;
	static int book_count;

	//멤버 함수
	void addbooks();
	void deletebooks();
	void searchbooks();
	void issuebook();
};

class start{
public:
	//필요한 객체 생성
	client client;
	computer computer;
	civil civil;
	electronic electronic;
};

vector<client::member> client::members;

vector<book::information> book::issued_book;
book::information child[3];
vector<book::information> computer::books;
int computer::book_count = 0;
vector<book::information> civil::books;
int civil::book_count = 0;
vector<book::information> electronic::books;
int electronic::book_count = 0;

void mainmenu();
void view_book_list();

start obj; //시작객체 전역변수로 선언

int main(void)
{
	mainmenu();

	return 0;

}

void mainmenu(){

	system("cls");

	int i;

	cout << "******************** MAIN MENU ********************" << endl;
	cout << "------- 1. Add Books   " << endl << endl;
	cout << "------- 2. Delete books" << endl << endl;
	cout << "------- 3. Search Books" << endl << endl;
	cout << "------- 4. Issue Books" << endl << endl;
	cout << "------- 5. View Book list" << endl << endl;
	cout << "------- 6. About Member" << endl << endl;
	cout << "------- 7. Close Application" << endl << endl;
	cout << "*****************************************************" << endl;
	cout << "Enter your choice:";
	cin >> i;

	switch (i)
	{
	case 1:
		system("cls");
		cout << "******************** Select category ********************" << endl;
		cout << "------- 1. Computer" << endl << endl;
		cout << "------- 2. Civil" << endl << endl;
		cout << "------- 3. Electronic" << endl << endl;
		cout << "*********************************************************" << endl;
		cout << "Enter your choice : ";
		cin >> i;
		switch (i){
		case 1:
			obj.computer.addbooks();
		case 2:
			obj.civil.addbooks();
		case 3:
			obj.electronic.addbooks();
		}
		break;
	case 2:
		system("cls");
		cout << "******************** Select category ********************" << endl;
		cout << "------- 1. Computer" << endl << endl;
		cout << "------- 2. Civil" << endl << endl;
		cout << "------- 3. Electronic" << endl << endl;
		cout << "*********************************************************" << endl;
		cout << "Enter your choice : ";
		cin >> i;
		switch (i){
		case 1:
			obj.computer.deletebooks();
		case 2:
			obj.civil.deletebooks();
		case 3:
			obj.electronic.deletebooks();
		}
		break;
	case 3:
		system("cls");
		cout << "******************** Select category ********************" << endl;
		cout << "------- 1. Computer" << endl << endl;
		cout << "------- 2. Civil" << endl << endl;
		cout << "------- 3. Electronic" << endl << endl;
		cout << "*********************************************************" << endl;
		cout << "Enter your choice : ";
		cin >> i;
		switch (i){
		case 1:
			obj.computer.searchbooks();
		case 2:
			obj.civil.searchbooks();
		case 3:
			obj.electronic.searchbooks();
		}
		break;
	case 4:
		system("cls");
		cout << "******************** Select category ********************" << endl;
		cout << "------- 1. Computer" << endl << endl;
		cout << "------- 2. Civil" << endl << endl;
		cout << "------- 3. Electronic" << endl << endl;
		cout << "*********************************************************" << endl;
		cout << "Enter your choice : ";
		cin >> i;
		switch (i){
		case 1:
			obj.computer.issuebook();
		case 2:
			obj.civil.issuebook();
		case 3:
			obj.electronic.issuebook();
		}
		break;
	case 5:
		view_book_list();
		break;
	case 6:
		obj.client.menu();
		break;
	case 7:
	{
		system("cls");

		cout << "Programed by KSJ, JBM, HJH, YSH, CYS" << endl;
		cout << "SoonChunHyang univ" << endl;
		cout << "Exiting in 3 second...........>";
		Sleep(3000);
		exit(0);
	}
	default:
	{
		cout << "Wrong Entry!! Please re-entered correct option";
		getch();
		mainmenu();
	}

	}
}

void view_book_list(){
	system("cls");

	cout << "*********************************Book List*****************************" << endl;
	cout << "ID\tNAME\tAUTHOR\tQUANTITY\tCATEGORY" << endl;
	for (book::information tmp : computer::books)
		cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.quantity << "\t\tcomputer" << endl;
	for (book::information tmp : civil::books)
		cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.quantity << "\t\tcivil" << endl;
	for (book::information tmp : electronic::books)
		cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.quantity << "\t\telectronic" << endl;

	getch();
	mainmenu();
}



void client::menu(){

	system("cls");

	int i;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Sign in" << endl << endl;
	cout << "------ 2. View Information" << endl << endl;
	cout << "********************************************************" << endl << endl;
	cout << "Enter your choice:";
	cin >> i;

	switch (i)
	{
	case 1:
		sign();
	case 2:
		information();
	default:
		cout << "Wrong Entry!!";
		getch();
		menu();
	}
}

void client::sign(){

	system("cls");

	member tmp;
	char flag;

	cout << "Enter the ID : ";
	cin >> tmp.id;

	for (member tmp : members)
		if (tmp.id == tmp.id){ //이미 존재하는 ID이면
			cout << "Already exist ID." << endl;
			getch();
			sign(); //다시 실행
		}

	cout << "Enter the name : ";
	cin >> tmp.name;
	cout << "Enter the age : ";
	cin >> tmp.age;
	cout << "Enter the phone : ";
	cin >> tmp.phone;
	cout << "Enter the residence : ";
	cin >> tmp.residence;
	cout << "Enter the pw : ";
	cin >> tmp.pw;

	members.push_back(tmp);

	cout << "The record is successfully saved." << endl;
	cout << "Sign in other client? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		sign();
	else mainmenu();
}

void client::information(){

	system("cls");

	cout << "*********************************Member List*****************************" << endl;
	cout << "ID\tPW\tNAME\tAGE\tPHONE\tRESIDENCE" << endl;
	for (member tmp : members)
		cout << tmp.id << "\t" << tmp.pw << "\t" << tmp.name << "\t" << tmp.age << "\t" << tmp.phone << "\t" << tmp.residence << endl;

	getch();
	mainmenu();
}



void computer::addbooks(){

	system("cls");

	information tmp;
	char flag;

	//책 정보 입력
	cout << "Book ID : ";
	cin >> tmp.id;
	cout << "Book Name : ";
	cin >> tmp.name;
	cout << "Book Author : ";
	cin >> tmp.Author;
	cout << "Book Quantity : ";
	cin >> tmp.quantity;

	books.push_back(tmp); //책을 벡터에 추가
	book_count++; //현재 책 개수 증가

	cout << "The record is successfully saved." << endl;
	cout << "Add other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		addbooks();
	else mainmenu();
}

void computer::deletebooks(){

	system("cls");

	string tmp;
	char flag;
	int i;

	//삭제할 책의 제목 입력
	cout << "Enter the book name to delete : ";
	cin >> tmp;

	for (i = 0; i < book_count; i++)
		if (books[i].name == tmp){
			books.erase(books.begin() + i); //벡터에서 원소 삭제
			book_count--; //현재 책 개수 감소
			break;
		}

	//올바른 책의 이름을 입력하지 않았다면
	if (i == book_count){ //반복제어변수 i를 통해 판별
		cout << "Enter the correct book name." << endl;
		cout << "Wait 3 seconds";
		for (int j = 0; j < 3; j++){
			cout << ".";
			Sleep(1000);
		}

		deletebooks(); //deletebooks() 다시 실행
	}

	cout << "The record is successfully deleted." << endl;
	cout << "Delete other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		deletebooks();
	else mainmenu();
}

void computer::searchbooks(){

	system("cls");

	int select;
	char flag;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Search by ID" << endl << endl;
	cout << "------ 2. Search by Name" << endl << endl;
	cout << "------ 3. Search by Author" << endl;
	cout << "****************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Search by ID
	case 1:{

		system("cls");
		int id, i;

		//찾으려는 책의 ID입력
		cout << "Enter the book ID : ";
		cin >> id;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].id == id){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : computer" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Name
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : computer" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Author
	case 3:{

		system("cls");
		bool flag = false; //책을 찾은 여부에 대한 bool 변수
		int i;
		string author;

		//찾으려는 책의 ID입력
		cout << "Enter the book Author : ";
		cin >> author;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].Author == author){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : computer" << endl;
				cout << "******************************" << endl << endl;
				flag = true;
			}

		//책을 찾지 못했다면
		if (flag == false)
			cout << endl << "No record found." << endl;
		break;
	}

	default:
		searchbooks();
	}

	cout << "Search other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		searchbooks();
	else mainmenu();
}

void computer::issuebook(){

	system("cls");

	int  select;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Issue book" << endl << endl;
	cout << "------ 2. remove issued book" << endl << endl;
	cout << "------ 3. View issued book" << endl;
	cout << "********************************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Issue book
	case 1:{

	restart:

		system("cls");
		int i;
		string name, client_ID;
		information tmp;
		bool flag = false;
		char flag_;

		//현재 시간 설정
		time_t Time;
		time(&Time);
		struct tm * LT = localtime(&Time);
		int month = LT->tm_mon + 1;
		int year = LT->tm_year + 1900;
		int day = LT->tm_mday;

		//회원 ID입력
		cout << "Enter the Client ID : ";
		cin >> client_ID;

		//존재하지 않는 회원 ID면
		for (client::member tmp : client::members){
			if (tmp.id == client_ID)
			flag = true;
		}

		if (flag == false){
			cout << "Enter the correct client ID.";
			getch();
			issuebook(); //다시 실행
		}

	F: //goto flag

		//대여하려는 책의 이름입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				tmp.id = books[i].id;
				tmp.name = books[i].name;
				tmp.Author = books[i].Author;
				tmp.quantity = books[i].quantity;
				tmp.clent_name = client_ID;
				tmp.issued.yy = year; tmp.issued.mm = month; tmp.issued.dd = day; //빌린 날짜
				tmp.duedate.yy = year; tmp.duedate.mm = month; tmp.duedate.dd = day + 7; //반납 날짜
				issued_book.push_back(tmp); //빌려간 책 리스트에 추가
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count){
			cout << endl << "No record found." << endl;
			getch();
			goto F;
		}

		cout << "The book is successfully issued." << endl;
		cout << "Issue other book? (Y/N) : ";
		cin >> flag_;

		if (flag_ == 'Y')
			goto restart;
		else mainmenu();

		break;
	}

		   //remove
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < issued_book.size(); i++)
			if (issued_book[i].name == name){
				issued_book.erase(issued_book.begin() + i); //리스트에서 삭제
				cout << "The book is successfully removed.";
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;

		getch();
		mainmenu();
	}

		   //View issued book list
	case 3:{

		system("cls");

		cout << "*********************************Issued book List*****************************" << endl;
		cout << "ID\tNAME\tAUTHOR\tCLIENT\tISSUED DATE\tDUE DATE" << endl;
		for (information tmp : issued_book)
			cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.clent_name << "\t" << tmp.issued.yy << tmp.issued.mm << tmp.issued.dd
			<< "\t" << tmp.duedate.yy << tmp.duedate.mm << tmp.duedate.dd << endl;

		getch();
		mainmenu();
	}

	default:
		issuebook();
	}
}

void civil::addbooks(){

	system("cls");

	information tmp;
	char flag;

	//책 정보 입력
	cout << "Book ID : ";
	cin >> tmp.id;
	cout << "Book Name : ";
	cin >> tmp.name;
	cout << "Book Author : ";
	cin >> tmp.Author;
	cout << "Book Quantity : ";
	cin >> tmp.quantity;

	books.push_back(tmp); //책을 벡터에 추가
	book_count++; //현재 책 개수 증가

	cout << "The record is successfully saved." << endl;
	cout << "Add other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		addbooks();
	else mainmenu();
}

void civil::deletebooks(){

	system("cls");

	string tmp;
	char flag;
	int i;

	//삭제할 책의 제목 입력
	cout << "Enter the book name to delete : ";
	cin >> tmp;

	for (i = 0; i < book_count; i++)
		if (books[i].name == tmp){
			books.erase(books.begin() + i);
			book_count--;
			break;
		}

	//올바른 책의 이름을 입력하지 않았다면
	if (i == book_count){ //반복제어변수 i를 통해 판별
		cout << "Enter the correct book name." << endl;
		cout << "Wait 3 seconds";
		for (int j = 0; j < 3; j++){
			cout << ".";
			Sleep(1000);
		}

		deletebooks(); //deletebooks() 다시 실행
	}

	cout << "The record is successfully deleted." << endl;
	cout << "Delete other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		deletebooks();
	else mainmenu();
}

void civil::searchbooks(){

	system("cls");

	int select;
	char flag;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Search by ID" << endl << endl;
	cout << "------ 2. Search by Name" << endl << endl;
	cout << "------ 3. Search by Author" << endl;
	cout << "****************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Search by ID
	case 1:{

		system("cls");
		int id, i;

		//찾으려는 책의 ID입력
		cout << "Enter the book ID : ";
		cin >> id;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].id == id){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : civil" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Name
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : civil" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Author
	case 3:{

		system("cls");
		bool flag = false; //책을 찾은 여부에 대한 bool 변수
		int i;
		string author;

		//찾으려는 책의 ID입력
		cout << "Enter the book Author : ";
		cin >> author;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].Author == author){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : civil" << endl;
				cout << "******************************" << endl << endl;
				flag = true;
			}

		//책을 찾지 못했다면
		if (flag == false)
			cout << endl << "No record found." << endl;
		break;
	}

	default:
		searchbooks();
	}

	cout << "Search other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		searchbooks();
	else mainmenu();
}

void civil::issuebook(){

	system("cls");

	int  select;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Issue book" << endl << endl;
	cout << "------ 2. remove issued book" << endl << endl;
	cout << "------ 3. View issued book" << endl;
	cout << "********************************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Issue book
	case 1:{

	restart:

		system("cls");
		int i;
		string name, client_name;
		information tmp;
		bool flag = false;
		char flag_;

		//현재 시간 설정
		time_t Time;
		time(&Time);
		struct tm * LT = localtime(&Time);
		int month = LT->tm_mon + 1;
		int year = LT->tm_year + 1900;
		int day = LT->tm_mday;

		//회원 ID입력
		cout << "Enter the Client ID : ";
		cin >> client_name;

		//존재하지 않는 회원 ID면
		for (client::member tmp : client::members)
			flag = true;

		if (flag == false){
			cout << "Enter the correct client ID.";
			getch();
			issuebook(); //다시 실행
		}

	F: //goto flag

		//대여하려는 책의 이름입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				tmp.id = books[i].id;
				tmp.name = books[i].name;
				tmp.Author = books[i].Author;
				tmp.quantity = books[i].quantity;
				tmp.clent_name = client_name;
				tmp.issued.yy = year; tmp.issued.mm = month; tmp.issued.dd = day; //빌린 날짜
				tmp.duedate.yy = year; tmp.duedate.mm = month; tmp.duedate.dd = day + 7; //반납 날짜
				issued_book.push_back(tmp); //빌려간 책 리스트에 추가
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count){
			cout << endl << "No record found." << endl;
			getch();
			goto F;
		}

		cout << "The book is successfully issued." << endl;
		cout << "Issue other book? (Y/N) : ";
		cin >> flag_;

		if (flag_ == 'Y')
			goto restart;
		else mainmenu();

		break;
	}

		   //remove
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < issued_book.size(); i++)
			if (issued_book[i].name == name){
				issued_book.erase(issued_book.begin() + i); //리스트에서 삭제
				cout << "The book is successfully removed.";
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;

		getch();
		mainmenu();
	}

		   //View issued book list
	case 3:{

		system("cls");

		cout << "*********************************Issued book List*****************************" << endl;
		cout << "ID\tNAME\tAUTHOR\tCLIENT\tISSUED DATE\tDUE DATE" << endl;
		for (information tmp : issued_book)
			cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.clent_name << "\t" << tmp.issued.yy << tmp.issued.mm << tmp.issued.dd
			<< "\t" << tmp.duedate.yy << tmp.duedate.mm << tmp.duedate.dd << endl;

		getch();
		mainmenu();
	}

	default:
		issuebook();
	}
}

void electronic::addbooks(){

	system("cls");

	information tmp;
	char flag;

	//책 정보 입력
	cout << "Book ID : ";
	cin >> tmp.id;
	cout << "Book Name : ";
	cin >> tmp.name;
	cout << "Book Author : ";
	cin >> tmp.Author;
	cout << "Book Quantity : ";
	cin >> tmp.quantity;

	books.push_back(tmp); //책을 벡터에 추가
	book_count++; //현재 책 개수 증가

	cout << "The record is successfully saved." << endl;
	cout << "Add other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		addbooks();
	else mainmenu();
}

void electronic::deletebooks(){

	system("cls");

	string tmp;
	char flag;
	int i;

	//삭제할 책의 제목 입력
	cout << "Enter the book name to delete : ";
	cin >> tmp;

	for (i = 0; i < book_count; i++)
		if (books[i].name == tmp){
			books.erase(books.begin() + i);
			book_count--;
			break;
		}

	//올바른 책의 이름을 입력하지 않았다면
	if (i == book_count){ //반복제어변수 i를 통해 판별
		cout << "Enter the correct book name." << endl;
		cout << "Wait 3 seconds";
		for (int j = 0; j < 3; j++){
			cout << ".";
			Sleep(1000);
		}

		deletebooks(); //deletebooks() 다시 실행
	}

	cout << "The record is successfully deleted." << endl;
	cout << "Delete other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		deletebooks();
	else mainmenu();
}

void electronic::searchbooks(){

	system("cls");

	int select;
	char flag;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Search by ID" << endl << endl;
	cout << "------ 2. Search by Name" << endl << endl;
	cout << "------ 3. Search by Author" << endl;
	cout << "****************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Search by ID
	case 1:{

		system("cls");
		int id, i;

		//찾으려는 책의 ID입력
		cout << "Enter the book ID : ";
		cin >> id;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].id == id){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : electronic" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Name
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : electronic" << endl;
				cout << "******************************" << endl;
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;
		break;
	}

		   //Search by Author
	case 3:{

		system("cls");
		bool flag = false; //책을 찾은 여부에 대한 bool 변수
		int i;
		string author;

		//찾으려는 책의 ID입력
		cout << "Enter the book Author : ";
		cin >> author;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].Author == author){
				cout << "******************************" << endl;
				cout << "ID : " << books[i].id << endl;
				cout << "Name : " << books[i].name << endl;
				cout << "Author : " << books[i].Author << endl;
				cout << "Quantity : " << books[i].quantity << endl;
				cout << "Category : electronic" << endl;
				cout << "******************************" << endl << endl;
				flag = true;
			}

		//책을 찾지 못했다면
		if (flag == false)
			cout << endl << "No record found." << endl;
		break;
	}

	default:
		searchbooks();
	}

	cout << "Search other book? (Y/N) : ";
	cin >> flag;

	if (flag == 'Y')
		searchbooks();
	else mainmenu();
}

void electronic::issuebook(){

	system("cls");

	int  select;

	cout << "********************SELECT CATEGOIES********************" << endl;
	cout << "------ 1. Issue book" << endl << endl;
	cout << "------ 2. remove issued book" << endl << endl;
	cout << "------ 3. View issued book" << endl;
	cout << "********************************************************" << endl << endl;
	cout << "Enter your choice : ";
	cin >> select;

	switch (select){

		//Issue book
	case 1:{

	restart:

		system("cls");
		int i;
		string name, client_name;
		information tmp;
		bool flag = false;
		char flag_;

		//현재 시간 설정
		time_t Time;
		time(&Time);
		struct tm * LT = localtime(&Time);
		int month = LT->tm_mon + 1;
		int year = LT->tm_year + 1900;
		int day = LT->tm_mday;

		//회원 ID입력
		cout << "Enter the Client ID : ";
		cin >> client_name;

		//존재하지 않는 회원 ID면
		for (client::member tmp : client::members)
			flag = true;

		if (flag == false){
			cout << "Enter the correct client ID.";
			getch();
			issuebook(); //다시 실행
		}

	F: //goto flag

		//대여하려는 책의 이름입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < book_count; i++)
			if (books[i].name == name){
				tmp.id = books[i].id;
				tmp.name = books[i].name;
				tmp.Author = books[i].Author;
				tmp.quantity = books[i].quantity;
				tmp.clent_name = client_name;
				tmp.issued.yy = year; tmp.issued.mm = month; tmp.issued.dd = day; //빌린 날짜
				tmp.duedate.yy = year; tmp.duedate.mm = month; tmp.duedate.dd = day + 7; //반납 날짜
				issued_book.push_back(tmp); //빌려간 책 리스트에 추가
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count){
			cout << endl << "No record found." << endl;
			getch();
			goto F;
		}

		cout << "The book is successfully issued." << endl;
		cout << "Issue other book? (Y/N) : ";
		cin >> flag_;

		if (flag_ == 'Y')
			goto restart;
		else mainmenu();

		break;
	}

		   //remove
	case 2:{

		system("cls");
		int i;
		string name;

		//찾으려는 책의 ID입력
		cout << "Enter the book Name : ";
		cin >> name;

		//책 탐색
		for (i = 0; i < issued_book.size(); i++)
			if (issued_book[i].name == name){
				issued_book.erase(issued_book.begin() + i); //리스트에서 삭제
				cout << "The book is successfully removed.";
				break;
			}

		//책을 찾지 못했다면
		if (i == book_count)
			cout << endl << "No record found." << endl;

		getch();
		mainmenu();
	}

		   //View issued book list
	case 3:{

		system("cls");

		cout << "*********************************Issued book List*****************************" << endl;
		cout << "ID\tNAME\tAUTHOR\tCLIENT\tISSUED DATE\tDUE DATE" << endl;
		for (information tmp : issued_book)
			cout << tmp.id << "\t" << tmp.name << "\t" << tmp.Author << "\t" << tmp.clent_name << "\t" << tmp.issued.yy << tmp.issued.mm << tmp.issued.dd
			<< "\t" << tmp.duedate.yy << tmp.duedate.mm << tmp.duedate.dd << endl;

		getch();
		mainmenu();
	}

	default:
		issuebook();
	}
}
