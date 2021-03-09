//프로그램에 공통적으로 필요한 함수와 변수들은 main.c모듈에 선언하여 pgm.h 헤더파일을 통해
//다른 모듈에서 사용할 수 있도록 하였습니다.

#include "pgm.h"
#include "supervise.h"
#include "search.h"
#include "issuebook.h"
#include "member.h"

void Password();
void mainmenu(void);

char password[10] = { "pokhara" };
char catagories[][15] = { "Computer", "Electronics", "Electrical", "Civil", "Mechnnical", "Architecture" };

COORD coord = { 0, 0 }; // sets coordinates to 0,0

int main()

{
	mainmenu();
	getch();
	return 0;

}

void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void mainmenu()
{
	//loaderanim();
	system("cls");
	//	textbackground(13);
	int i;
	gotoxy(20, 3);
	printf("******************** MAIN MENU ********************");
	//show_mouse();
	gotoxy(20, 5);
	printf("------- 1. Add Books   ");
	gotoxy(20, 7);
	printf("------- 2. Delete books");
	gotoxy(20, 9);
	printf("------- 3. Search Books");
	gotoxy(20, 11);
	printf("------- 4. Issue Books");
	gotoxy(20, 13);
	printf("------- 5. View Book list");
	gotoxy(20, 15);
	printf("------- 6. Edit Book's Record");
	gotoxy(20, 17);
	printf("------- 7. About Member");
	gotoxy(20, 19);
	printf("------- 8. Close Application");
	gotoxy(20, 20);
	printf("*****************************************************");
	gotoxy(20, 21);
	t();
	gotoxy(20, 22);
	printf("Enter your choice:");
	switch (getch())
	{
	case '1':
		addbooks();
		break;
	case '2':
		deletebooks();
		break;
	case '3':
		searchbooks();
		break;
	case '4':
		issuebooks();
		break;
	case '5':
		viewbooks();
		break;
	case '6':
		editbooks();
		break;
	case '7':
		member();
		break;
	case '8':
	{
		system("cls");
		gotoxy(16, 3);
		printf("Programmers....");
		gotoxy(16, 4);
		printf("1. Bibek Subedi       (066/BCT/506)");
		gotoxy(16, 5);
		printf("   Mobile:9846311430  E-mail:subedi_bibek@yahoo.co.in");
		gotoxy(16, 7);
		printf("2. Dinesh Subedi      (066/BCT/512)");
		gotoxy(16, 8);
		printf("   Mobile:9841569394  E-mail:smokindinesh@gmail.com");
		gotoxy(16, 10);
		printf("3. Sijan Bhandari      (066/BCT/537)");
		gotoxy(16, 11);
		printf("   Mobile:9849516774   E-mail:sijan_nasa@yahoo.com");
		gotoxy(16, 13);
		printf("With  the Unexplainable Help of Mr.Ashok Basnet");
		gotoxy(16, 15);
		printf("수정 : 김상진, 전병무, 홍종현, 최윤선, 유선희");
		gotoxy(10, 19);
		printf("Exiting in 3 second...........>");
		//flushall();
		delay(3000);
		exit(0);
	}
	default:
	{
		gotoxy(10, 23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if (getch())
			mainmenu();
	}

	}
}

void returnfunc(void)
{
	{
		printf(" Press ENTER to return to main menu");
	}
a:
	if (getch() == 13) //allow only use of enter
		mainmenu();
	else
		goto a;
}

int t(void) //for time
{
	time_t t;
	time(&t);
	printf("date and time:%s\n", ctime(&t));

	return 0;
}

void loaderanim()
{
	int loader;
	system("cls");
	gotoxy(20, 10);
	printf("LOADING........");
	printf("\n\n");
	gotoxy(22, 11);
	for (loader = 1; loader<20; loader++)
	{
		delay(100); printf("%c", 219);
	}
}

int getdata()
{
	int t;
	gotoxy(20, 3); printf("Enter the Information Below");
	gotoxy(20, 4); printf("**************************************************");
	gotoxy(20, 5);
	printf("----"); gotoxy(46, 5); printf("----");
	gotoxy(20, 6);
	printf("----"); gotoxy(46, 6); printf("----");
	gotoxy(20, 7);
	printf("----"); gotoxy(46, 7); printf("----");
	gotoxy(20, 8);
	printf("----"); gotoxy(46, 8); printf("----");
	gotoxy(20, 9);
	printf("----"); gotoxy(46, 9); printf("----");
	gotoxy(20, 10);
	printf("----"); gotoxy(46, 10); printf("----");
	gotoxy(20, 11);
	printf("----"); gotoxy(46, 11); printf("----");
	gotoxy(20, 12);
	printf("**************************************************");
	gotoxy(21, 5);
	printf("Category:");
	gotoxy(31, 5);
	printf("%s", catagories[s - 1]);
	gotoxy(21, 6);
	printf("Book ID:\t");
	gotoxy(30, 6);
	scanf("%d", &t);
	if (checkid(t) == 0)
	{
		gotoxy(21, 13);
		printf("\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	a.id = t;
	gotoxy(21, 7);
	printf("Book Name:"); gotoxy(33, 7);
	scanf("%s", a.name);
	gotoxy(21, 8);
	printf("Author:"); gotoxy(30, 8);
	scanf("%s", a.Author);
	gotoxy(21, 9);
	printf("Quantity:"); gotoxy(31, 9);
	scanf("%d", &a.quantity);
	gotoxy(21, 10);
	printf("Price:"); gotoxy(28, 10);
	scanf("%f", &a.Price);
	gotoxy(21, 11);
	printf("Rack No:"); gotoxy(30, 11);
	scanf("%d", &a.rackno);
	return 1;
}

int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while (fread(&a, sizeof(a), 1, fp) == 1)
		if (a.id == t)
			return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}
