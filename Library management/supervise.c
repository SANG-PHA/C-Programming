#include "pgm.h"
#include "supervise.h"

void addbooks(void)    //funtion that add books
{
	system("cls");
	int i;
	gotoxy(20, 5);
	printf("********************SELECT CATEGOIES********************");
	gotoxy(20, 7);
	printf("----- 1. Computer");
	gotoxy(20, 9);
	printf("----- 2. Electronics");
	gotoxy(20, 11);
	printf("----- 3. Electrical");
	gotoxy(20, 13);
	printf("----- 4. Civil");
	gotoxy(20, 15);
	printf("----- 5. Mechanical");
	gotoxy(20, 17);
	printf("----- 6. Architecture");
	gotoxy(20, 19);
	printf("----- 7. Back to main menu");
	gotoxy(20, 21);
	printf("****************************************");
	gotoxy(20, 22);
	printf("Enter your choice:");
	scanf("%d", &s);
	if (s == 7)

		mainmenu();
	system("cls");
	fp = fopen("Bibek.dat", "ab+");
	if (getdata() == 1)
	{
		strcpy(a.cat, catagories[s - 1]);
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1, fp);
		fclose(fp);
		gotoxy(21, 14);
		printf("The record is sucessfully saved");
		gotoxy(21, 15);
		printf("Save any more?(Y / N):");
		if (getch() == 'n')
			mainmenu();
		else
			system("cls");
		addbooks();
	}
}

void deletebooks()    //function that delete items from file fp
{
	system("cls");
	int d;
	char another = 'y';
	while (another == 'y')  //infinite loop
	{
		system("cls");
		gotoxy(10, 5);
		printf("Enter the Book ID to  delete:");
		scanf("%d", &d);
		fp = fopen("Bibek.dat", "rb+");
		rewind(fp);
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{

				gotoxy(10, 7);
				printf("The book record is available");
				gotoxy(10, 8);
				printf("Book name is %s", a.name);
				gotoxy(10, 9);
				printf("Rack No. is %d", a.rackno);
				findbook = 't';
			}
		}
		if (findbook != 't')
		{
			gotoxy(10, 10);
			printf("No record is found modify the search");
			if (getch())
				mainmenu();
		}
		if (findbook == 't')
		{
			gotoxy(10, 9);
			printf("Do you want to delete it?(Y/N):");
			if (getch() == 'y')
			{
				ft = fopen("test.dat", "wb+");  //temporary file for delete
				rewind(fp);
				while (fread(&a, sizeof(a), 1, fp) == 1)
				{
					if (a.id != d)
					{
						fseek(ft, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, ft); //write all in tempory file except that
					}                              //we want to delete
				}
				fclose(ft);
				fclose(fp);
				remove("Bibek.dat");
				rename("test.dat", "Bibek.dat"); //copy all item from temporary file to fp except that
				fp = fopen("Bibek.dat", "rb+");    //we want to delete
				if (findbook == 't')
				{
					gotoxy(10, 10);
					printf("The record is sucessfully deleted");
					gotoxy(10, 11);
					printf("Delete another record?(Y/N)");
				}
			}
			else
				mainmenu();
			//fflush(stdin);
			another = getch();
		}
	}
	gotoxy(10, 15);
	mainmenu();
}

void editbooks(void)  //edit information about book
{
	system("cls");
	int c = 0;
	int d, e;
	gotoxy(20, 4);
	printf("****Edit Books Section****");
	char another = 'y';
	while (another == 'y')
	{
		system("cls");
		gotoxy(15, 6);
		printf("Enter Book Id to be edited:");
		scanf("%d", &d);
		fp = fopen("Bibek.dat", "rb+");
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (checkid(d) == 0)
			{
				gotoxy(15, 7);
				printf("The book is availble");
				gotoxy(15, 8);
				printf("The Book ID:%d", a.id);
				gotoxy(15, 9);
				printf("Enter new name:"); scanf("%s", a.name);
				gotoxy(15, 10);
				printf("Enter new Author:"); scanf("%s", a.Author);
				gotoxy(15, 11);
				printf("Enter new quantity:"); scanf("%d", &a.quantity);
				gotoxy(15, 12);
				printf("Enter new price:"); scanf("%f", &a.Price);
				gotoxy(15, 13);
				printf("Enter new rackno:"); scanf("%d", &a.rackno);
				gotoxy(15, 14);
				printf("The record is modified");
				fseek(fp, ftell(fp) - sizeof(a), 0);
				fwrite(&a, sizeof(a), 1, fp);
				fclose(fp);
				c = 1;
			}
			if (c == 0)
			{
				gotoxy(15, 9);
				printf("No record found");
			}
		}
		gotoxy(15, 16);
		printf("Modify another Record?(Y/N)");
		//fflush(stdin);
		another = getch();
	}
	returnfunc();
}
