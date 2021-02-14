#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct student{
	int id;
	char name[10];
	int grade;
}student[MAX_SIZE]; //학생 정보 구조체 배열선언

void read_file();
void get_student(FILE *fp);
void check_grade(int grade_cnt[]);
int check_max_cnt(int grade_cnt[]);
void display_histogram(int grade_cnt[], int max_cnt);

int main(void)
{
	int grade_cnt[11] = { 0, }; //점수의 빈도수를 저장하는 배열 선언 및 초기화
	int max_cnt; //가장 큰 빈도수 저장 변수 선언

	read_file(); //파일을 읽는다
	check_grade(grade_cnt); //학생들의 성적에 따라 빈도 수를 구한다.
	max_cnt = check_max_cnt(grade_cnt); //가장 큰 빈도 수를 구한다.
	display_histogram(grade_cnt, max_cnt); //형식에 맞게 출력한다.

	getch();
	return 0;
}

void read_file()
{
	FILE *fp = NULL; //파일포인터 선언

	fp = fopen("grade.txt", "r"); //텍스트 파일을 'r'모드로 연다
	if (fp == NULL)
		printf("파일을 열지 못했습니다.\n");
	else
	{
		get_student(fp); //읽어온 파일을 토큰 단위로 구조체에 저장하는 함수
	}
}
	
void get_student(FILE *fp)
{
	char buffer[MAX_SIZE] = { NULL, }; //읽어들인 라인을 저장할 배열 선언
	char *token = NULL; //토큰
	
	for (int i = 0; fgets(buffer, sizeof(buffer), fp) != NULL; i++){
		//파일에서 한 줄을 읽어들임

		token = strtok(buffer, " "); //학번 저장
		student[i].id = atoi(token);

		token = strtok(NULL, " "); //이름 저장
		strcpy(student[i].name, token);

		token = strtok(NULL, " "); //성적 저장
		student[i].grade = atoi(token);	
	}
}

void check_grade(int grade_cnt[])
{
	for (int i = 0; i < MAX_SIZE; i++){
		if (student[i].grade < 10)
			grade_cnt[0]++;
		else if (student[i].grade < 20)
			grade_cnt[1]++;
		else if (student[i].grade < 30)
			grade_cnt[2]++;
		else if (student[i].grade < 40)
			grade_cnt[3]++;
		else if (student[i].grade < 50)
			grade_cnt[4]++;
		else if (student[i].grade < 60)
			grade_cnt[5]++;
		else if (student[i].grade < 70)
			grade_cnt[6]++;
		else if (student[i].grade < 80)
			grade_cnt[7]++;
		else if (student[i].grade < 90)
			grade_cnt[8]++;
		else if (student[i].grade < 100)
			grade_cnt[9]++;
		else
			grade_cnt[10]++;
	}
	//학생 성적에 따라 배열 인덱스 값을 증가시켜준다.
}

int check_max_cnt(int grade_cnt[])
{
	int max_cnt = grade_cnt[0];
	for (int i = 1; i < 11; i++){
		if (max_cnt < grade_cnt[i])
			max_cnt = grade_cnt[i];
	}
	return max_cnt;
}

void display_histogram(int grade_cnt[], int max_cnt){

	printf("=========학생 성적 빈도 수 출력 히스토그램입니다.=========\n");
	printf("빈도\n\n");
	
	for (int i = max_cnt; i > 0; i--){
		printf("%2d  ", i);
		for (int j = 0; j < 11; j++){
			printf(" ");
			if (grade_cnt[j] == i){
				printf("*");
				grade_cnt[j]--;
			}
			else printf(" ");
			printf("  ");
		}
		printf("\n");
	}

	for (int j = 0; j < 11; j++){
		if (j == 0)
			printf("     0  ");
		else if (j == 10) 
			printf("100");
		else printf("%d0  ", j);
	}
}
