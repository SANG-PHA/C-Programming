ar#include "pgm.h"
#include "search.h"

void searchbooks()
{
	system("cls");
	int d;
	printf("*****************************Search Books*********************************");
	gotoxy(20, 10);
	printf("----- 1. Search By ID");
	gotoxy(20, 14);
	printf("----- 2. Search By Name");
	gotoxy(20, 18);
	printf("----- 3. Search By Author");
	gotoxy(15, 20);
	printf("Enter Your Choice");
	fp = fopen("Bibek.dat", "rb+"); //open file for reading propose
	rewind(fp);   //move pointer at the begining of file
	switch (getch())
	{
	case '1':
	{
		system("cls");
		gotoxy(25, 4);
		printf("****Search Books By Id****");
		gotoxy(20, 5);
		printf("Enter the book id:");
		scanf("%d", &d);
		gotoxy(20, 7);
		printf("Searching........");
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				delay(2);
				gotoxy(20, 7);
				printf("The Book is available");
				gotoxy(20, 8);
				printf("****************************************");
				gotoxy(20, 9);
				printf("---- ID:%d", a.id); gotoxy(47, 9); printf("----");
				gotoxy(20, 10);
				printf("---- Name:%s", a.name); gotoxy(47, 10); printf("----");
				gotoxy(20, 11);
				printf("---- Author:%s ", a.Author); gotoxy(47, 11); printf("----");
				gotoxy(20, 12);
				printf("---- Qantity:%d ", a.quantity); gotoxy(47, 12); printf("----");
				gotoxy(20, 13);
				printf("---- Price:Rs.%.2f", a.Price); gotoxy(47, 13); printf("----");
				gotoxy(20, 14);
				printf("---- Rack No:%d ", a.rackno); gotoxy(47, 14); printf("----");
				gotoxy(20, 15);
				printf("****************************************");
				findbook = 't';
			}

		}
		if (findbook != 't')  //checks whether conditiion enters inside loop or not
		{
			gotoxy(20, 8);
			printf("****************************************");
			gotoxy(20, 9); printf("----");  gotoxy(38, 9); printf("----");
			gotoxy(20, 10);
			printf("****************************************");
			gotoxy(22, 9); printf("\aNo Record Found");
		}
		gotoxy(20, 17);
		printf("Try another search?(Y/N)");
		if (getch() == 'y')
			searchbooks();
		else
			mainmenu();
		break;
	}
	case '2':
	{
		char s[15];
		system("cls");
		gotoxy(25, 4);
		printf("****Search Books By Name****");
		gotoxy(20, 5);
		printf("Enter Book Name:");
		scanf("%s", s);
		int d = 0;
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (strcmp(a.name, (s)) == 0) //checks whether a.name is equal to s or not
			{
				gotoxy(20, 7);
				printf("The Book is available");
				gotoxy(20, 8);
				printf("****************************************");
				gotoxy(20, 9);
				printf("---- ID:%d", a.id); gotoxy(47, 9); printf("----");
				gotoxy(20, 10);
				printf("---- Name:%s", a.name); gotoxy(47, 10); printf("----");
				gotoxy(20, 11);
				printf("---- Author:%s", a.Author); gotoxy(47, 11); printf("----");
				gotoxy(20, 12);
				printf("---- Qantity:%d", a.quantity); gotoxy(47, 12); printf("----");
				gotoxy(20, 13);
				printf("---- Price:Rs.%.2f", a.Price); gotoxy(47, 13); printf("----");
				gotoxy(20, 14);
				printf("---- Rack No:%d ", a.rackno); gotoxy(47, 14); printf("----");
				gotoxy(20, 15);
				printf("****************************************");
				d++;
			}

		}
		if (d == 0)
		{
			gotoxy(20, 8);
			printf("****************************************");
			gotoxy(20, 9); printf("----");  gotoxy(38, 9); printf("----");
			gotoxy(20, 10);
			printf("****************************************");
			gotoxy(22, 9); printf("\aNo Record Found");
		}
		gotoxy(20, 17);
		printf("Try another search?(Y/N)");
		if (getch() == 'y')
			searchbooks();
		else
			mainmenu();
		break;
	}
	case '3': //저자로 책 검색
	{
		char s[15];
		system("cls");
		gotoxy(25, 4);
		printf("****Search Books By Author****");
		gotoxy(20, 5);
		printf("Enter Book Author:");
		scanf("%s", s);
		int d = 0; //파일에서 찾은 저자의 횟수
		int cursor = 7; //Y축 커서 초기값 7
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (strcmp(a.Author, (s)) == 0) //checks whether a.name is equal to s or not
			{
				gotoxy(20, cursor);
				printf("The Book is available");
				cursor++;
				gotoxy(20, cursor);
				printf("****************************************");
				cursor++;
				gotoxy(20, cursor);
				printf("---- ID:%d", a.id); gotoxy(47, 9); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("---- Name:%s", a.name); gotoxy(47, 10); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("---- Author:%s", a.Author); gotoxy(47, 11); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("---- Qantity:%d", a.quantity); gotoxy(47, 12); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("---- Price:Rs.%.2f", a.Price); gotoxy(47, 13); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("---- Rack No:%d ", a.rackno); gotoxy(47, 14); printf("----");
				cursor++;
				gotoxy(20, cursor);
				printf("****************************************");
				cursor++;
				d++;
			}

		}
		if (d == 0)
		{
			gotoxy(20, 8);
			printf("****************************************");
			gotoxy(20, 9); printf("----");  gotoxy(38, 9); printf("----");
			gotoxy(20, 10);
			printf("****************************************");
			gotoxy(22, 9); printf("\aNo Record Found");
		}
		if (cursor == 7)
			gotoxy(20, 17);
		else gotoxy(20, cursor);
		printf("Try another search?(Y/N)");
		if (getch() == 'y')
			searchbooks();
		else
			mainmenu();
		break;
	}
	default:
		getch();
		searchbooks();
	}
	fclose(fp);
}

void viewbooks(void)  //show the list of book persists in library
{
	int i = 0, j;
	system("cls");
	gotoxy(1, 1);
	printf("*********************************Book List*****************************");
	gotoxy(2, 2);
	printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
	j = 4;
	fp = fopen("Bibek.dat", "rb");
	while (fread(&a, sizeof(a), 1, fp) == 1)
	{
		gotoxy(3, j);
		printf("%s", a.cat);
		gotoxy(16, j);
		printf("%d", a.id);
		gotoxy(22, j);
		printf("%s", a.name);
		gotoxy(36, j);
		printf("%s", a.Author);
		gotoxy(50, j);
		printf("%d", a.quantity);
		gotoxy(57, j);
		printf("%.2f", a.Price);
		gotoxy(69, j);
		printf("%d", a.rackno);
		printf("\n\n");
		j++;
		i = i + a.quantity;
	}
	gotoxy(3, 25);
	printf("Total Books =%d", i);
	fclose(fp);
	gotoxy(35, 25);
	returnfunc();
}
