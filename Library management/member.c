#include "pgm.h"
#include "member.h"

void member()
{
	system("cls");
	int i;
	gotoxy(20, 5);
	printf("********************SELECT CATEGOIES********************");
	gotoxy(20, 7);
	printf("----- 1. Sign in");
	gotoxy(20, 9);
	printf("----- 2. View Information");
	gotoxy(20, 11);
	printf("----- 3. Recommend book");
	gotoxy(20, 13);
	printf("****************************************");
	gotoxy(20, 15);
	printf("Enter your choice:");

	switch (getch())
	{
	case '1':  //issue book
		sign();
	break;
	case '2':  //show issued book list
		information();
	case '3':
		recommend();
	break;
	default:
		gotoxy(10, 18);
		printf("\aWrong Entry!!");
		getch();
		member();
		break;
	}
	gotoxy(1, 30);
	returnfunc();



}

void sign()
{
	system("cls");
	fp = fopen("members.dat", "ab+");
	if (getmember() == 1)
	{
		fseek(fp, 0, SEEK_END);
		fwrite(&m, sizeof(m), 1, fp);
		fclose(fp);
		gotoxy(21, 14);
		printf("The record is sucessfully saved");
		gotoxy(21, 15);
		printf("Sign in any more?(Y / N):");
		if (getch() == 'n')
			mainmenu();
		else
			system("cls");
		sign();
	}
}

void information()
{ //id pw name age phone residence
	int j;
	system("cls");
	gotoxy(1, 1);
	printf("*********************************Member List*****************************");
	gotoxy(2, 2);
	printf(" ID              PW            NAME          AGE     PHONE        RESIDENCE ");
	j = 4;
	fp = fopen("members.dat", "rb");
	while (fread(&m, sizeof(m), 1, fp) == 1)
	{
		gotoxy(3, j);
		printf("%s", m.id);
		gotoxy(19, j);
		printf("%s", m.pw);
		gotoxy(34, j);
		printf("%s", m.name);
		gotoxy(47, j);
		printf("%d", m.age);
		gotoxy(54, j);
		printf("%d", m.phone);
		gotoxy(68, j);
		printf("%s", m.residence);
		printf("\n\n");
		j++;
	}
	fclose(fp);
	gotoxy(35, 25);
	returnfunc();
}

void recommend()
{
	srand(time(NULL));
	char tmp_id[20], tmp_book[20];
	int c = 0, flag = 0;
	fm = fopen("members.dat", "rb+");
	fp = fopen("Bibek.dat", "rb");

	system("cls");
	gotoxy(20, 5);
	printf("Enter Member ID : ");
	scanf("%s", tmp_id);

	while (fread(&m, sizeof(m), 1, fm) == 1){
		if (strcmp(tmp_id, m.id) == 0){
			c = 1;
			gotoxy(20, 7);
			printf("--- Recommend Category : %s", m.cat);
			
			while (fread(&a, sizeof(a), 1, fp)){
				if ((rand() % 2) == 1){ //난수를 발생시켜 추천 책 선택
					strcpy(tmp_book, a.name);
					flag = 1;
				}
			}
			if (flag == 0)
				strcpy(tmp_book, a.name);
			gotoxy(20, 9);
			printf("--- Recommend Book : %s", tmp_book);
		}
	}

	fclose(fm);
	fclose(fp);
	if (c == 0){ //존재하지 않는 member ID 일 때
		gotoxy(20, 7);
		printf("There are no exist ID");
		gotoxy(20, 8);
		printf("Press any key to countinue.....");
		getch();
		recommend();
	}
}

int getmember()
{
	char t[20];
	gotoxy(20, 3); printf("Enter the Information Below");
	gotoxy(20, 4); printf("**************************************************");
	gotoxy(20, 5);
	printf("----");
	gotoxy(20, 6);
	printf("----");
	gotoxy(20, 7);
	printf("----");
	gotoxy(20, 8);
	printf("----");
	gotoxy(20, 9);
	printf("----"); 
	gotoxy(20, 10);
	printf("----"); 
	gotoxy(20, 11);
	printf("----"); 
	gotoxy(20, 12);
	printf("**************************************************");
	
	gotoxy(21, 6);
	printf("ID:\t");
	gotoxy(31, 6);
	scanf("%s", t);
	if (checkid_m(t) == 0) // ID중복 불가
	{
		gotoxy(21, 13);
		printf("\aThe member id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	strcpy(m.id, t);
	gotoxy(21, 7);
	printf("Member Name:"); gotoxy(35, 7);
	scanf("%s", m.name);
	gotoxy(21, 8);
	printf("Age:"); gotoxy(35, 8);
	scanf("%d", &m.age);
	gotoxy(21, 9);
	printf("Phone number:"); gotoxy(35, 9);
	scanf("%d", &m.phone);
	gotoxy(21, 10);
	printf("Residence:"); gotoxy(35, 10);
	scanf("%s", m.residence);
	gotoxy(21, 11);
	printf("Password:"); gotoxy(35, 11);
	scanf("%s", m.pw);
	return 1;
}

int checkid_m(char t[])  //check whether the book is exist in library or not
{
	rewind(fp);
	while (fread(&m, sizeof(m), 1, fp) == 1)
		if (strcmp(m.id, t) == 0)
			return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}
