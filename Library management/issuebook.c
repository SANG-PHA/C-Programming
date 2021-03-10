#include "pgm.h"
#include "issuebook.h"

int tt;

void issuebooks(void)  //function that issue books from library
{

	system("cls");
	printf("********************************ISSUE SECTION**************************");
	gotoxy(10, 5);
	printf("-------- 1. Issue a Book");
	gotoxy(10, 7);
	printf("-------- 2. View Issued Book");
	gotoxy(10, 9);
	printf("-------- 3. Search Issued Book");
	gotoxy(10, 11);
	printf("-------- 4. Remove Issued Book");
	gotoxy(10, 14);
	printf("Enter a Choice:");
	switch (getch())
	{
	case '1':  //issue book
	{
		issue();
	}
	break;
	case '2':  //show issued book list
	{
		view();
	}
	break;
	case '3':   //search issued books by id
	{
		search();
	}
	break;
	case '4':  //remove issued books from list
	{
		remove_();
	}
	default:
		gotoxy(10, 18);
		printf("\aWrong Entry!!");
		getch();
		issuebooks();
		break;
	}
	gotoxy(1, 30);
	returnfunc();
}

void issue()
{
	system("cls");
	
	//현재 시간 설정
	time_t Time;
	time(&Time);
	struct tm * LT = localtime(&Time);
	int month = LT->tm_mon + 1;
	int year = LT->tm_year + 1900;
	int day = LT->tm_mday;

	int c = 0, flag = 0; // 조건문에 필요한 변수
	char another = 'y';
	F: //goto flag
	while (another == 'y')
	{
		system("cls");
		gotoxy(15, 4);
		printf("***Issue Book section***");
		gotoxy(10, 6);
		printf("Enter the Book Id:");
		scanf("%d", &tt);
		fp = fopen("Bibek.dat", "rb");
		fs = fopen("Issue.dat", "ab+"); 
		fm = fopen("members.dat", "rb");
		if (checkid(tt) == 0) //issues those which are present in library
		{
			gotoxy(10, 8);
			printf("The book record is available");
			gotoxy(10, 9);
			printf("There are %d unissued books in library ", a.quantity);
			gotoxy(10, 10);
			printf("Enter member name:"); //책을 빌려갈 멤버 이름 입력
			scanf("%s", a.stname);
			while (fread(&m, sizeof(m), 1, fm) == 1){
				if (strcmp(a.stname, m.name) == 0){
					flag = 1;
					break;
				}
			}
			fclose(fm);
			if (flag == 0){
				gotoxy(10, 11);
				printf("not exist member");
				gotoxy(10, 12);
				printf("Press any key to countinue.....");
				getch();
				goto F;
			}
			gotoxy(10, 12);
			printf("The name of book is %s", a.name);
			gotoxy(10, 13);
			a.issued.dd = day;
			a.issued.mm = month;
			a.issued.yy = year;
			printf("Issued date=%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
			gotoxy(10, 14);
			printf("The BOOK of ID %d is issued", a.id);
			a.duedate.dd = a.issued.dd + RETURNTIME;   //for return date
			a.duedate.mm = a.issued.mm;
			a.duedate.yy = a.issued.yy;
			if (a.duedate.dd > 30)
			{
				a.duedate.mm += a.duedate.dd / 30;
				a.duedate.dd -= 30;

			}
			if (a.duedate.mm > 12)
			{
				a.duedate.yy += a.duedate.mm / 12;
				a.duedate.mm -= 12;

			}

			//멤버의 마지막 대출한 책의 카테고리 파일에 업데이트
			fm = fopen("members.dat", "rb+");
			while (fread(&m, sizeof(m), 1, fm) == 1)
			{
				if (strcmp(a.stname, m.name) == 0)
				{
					strcpy(m.cat, a.cat);
					fseek(fm, ftell(fm) - sizeof(m), 0);
					fwrite(&m, sizeof(m), 1, fm);
					fclose(fm);
				}
			}

			gotoxy(10, 15);
			printf("To be return:%d-%d-%d", a.duedate.yy, a.duedate.mm, a.duedate.dd);
			fseek(fs, sizeof(a), SEEK_END);
			fwrite(&a, sizeof(a), 1, fs);
			fclose(fs);
			c = 1;
		}
		if (c == 0) //파일에서 못 찾았을 때
		{
			gotoxy(10, 11);
			printf("No record found");
		}
		gotoxy(10, 15);
		printf("Issue any more(Y/N):");
		fflush(stdin);
		another = getche();
		fclose(fp);
		flag = 0;
	}
}

void view()
{
	system("cls");
	int j = 4;
	printf("*******************************Issued book list*******************************\n");
	gotoxy(2, 2);
	printf("MEMBER NAME     CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
	fs = fopen("Issue.dat", "rb");
	while (fread(&a, sizeof(a), 1, fs) == 1)
	{

		gotoxy(2, j);
		printf("%s", a.stname);
		gotoxy(18, j);
		printf("%s", a.cat);
		gotoxy(30, j);
		printf("%d", a.id);
		gotoxy(36, j);
		printf("%s", a.name);
		gotoxy(51, j);
		printf("%d-%d-%d", a.issued.yy, a.issued.mm, a.issued.dd);
		gotoxy(65, j);
		printf("%d-%d-%d", a.duedate.yy, a.duedate.mm, a.duedate.dd);
		gotoxy(50, 25);
		j++;

	}
	fclose(fs);
	gotoxy(1, 25);
	returnfunc();
}

void search()
{
	system("cls");
	gotoxy(10, 6);
	printf("Enter Book ID:");
	int p, c = 0;
	char another = 'y';
	while (another == 'y')
	{

		scanf("%d", &p);
		fs = fopen("Issue.dat", "rb");
		while (fread(&a, sizeof(a), 1, fs) == 1)
		{
			if (a.id == p)
			{
				issuerecord();
				gotoxy(10, 12);
				printf("Press any key.......");
				getch();
				issuerecord();
				c = 1;
			}

		}
		fflush(stdin);
		fclose(fs);
		if (c == 0)
		{
			gotoxy(10, 8);
			printf("No Record Found");
		}
		gotoxy(10, 13);
		printf("Try Another Search?(Y/N)");
		another = getch();
	}
}

void remove_()
{
	system("cls");
	int b;
	FILE *fg;  //declaration of temporary file for delete
	char another = 'y';
	while (another == 'y')
	{
		gotoxy(10, 5);
		printf("Enter book id to remove:");
		scanf("%d", &b);
		fs = fopen("Issue.dat", "rb+");
		while (fread(&a, sizeof(a), 1, fs) == 1)
		{
			if (a.id == b)
			{
				issuerecord();
				findbook = 't';
			}
			if (findbook == 't')
			{
				gotoxy(10, 12);
				printf("Do You Want to Remove it?(Y/N)");
				if (getch() == 'y')
				{
					fg = fopen("record.dat", "wb+");
					rewind(fs);
					while (fread(&a, sizeof(a), 1, fs) == 1)
					{
						if (a.id != b)
						{
							fseek(fs, 0, SEEK_CUR);
							fwrite(&a, sizeof(a), 1, fg);
						}
					}
					fclose(fs);
					fclose(fg);
					remove("Issue.dat");
					rename("record.dat", "Issue.dat");
					gotoxy(10, 14);
					printf("The issued book is removed from list");

				}

			}
			if (findbook != 't')
			{
				gotoxy(10, 15);
				printf("No Record Found");
			}
		}
		gotoxy(10, 16);
		printf("Delete any more?(Y/N)");
		another = getch();
	}
}

void issuerecord()  //display issued book's information
{
	system("cls");
	gotoxy(10, 8);
	printf("The Book has taken by Mr. %s", a.stname);
	gotoxy(10, 9);
	printf("Issued Date:%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
	gotoxy(10, 10);
	printf("Returning Date:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
}
