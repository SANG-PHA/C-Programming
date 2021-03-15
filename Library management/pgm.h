#pragma once

#include <windows.h>
#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

//모든 모듈에 공통적으로 필요한 함수
void gotoxy(int x, int y);
void delay(unsigned int mseconds);
void mainmenu();
void returnfunc(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void loaderanim();

#define RETURNTIME 15
extern COORD coord;
COORD max_res, cursor_size;

//list of global variable
int s;
char findbook;

FILE *fp, *ft, *fs, *fm; //list of global files that can be acceed form anywhere in program

extern char catagories[][15]; //책 카테고리 배열

struct meroDate //책의 대여일, 반납일 구조체
{
	int mm, dd, yy;
};

struct books //책 구조체
{
	int id;
	char stname[20];
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	int count;
	int rackno;
	char cat[20];
	struct meroDate issued;
	struct meroDate duedate;
};
struct books a;

struct member //회원 구조체 
{
	char name[20];
	int age;
	int phone;
	char residence[20];
	char id[20];
	char pw[20];
	char cat[20];
};
struct member m;
