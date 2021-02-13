#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	char word[20];
	int cnt;
}list[100]; //구조체배열 선언

void read_file();
void get_line(FILE *fp);
char* tolower_token(char *token);
int check_same_word(char* token, int length, int *num);
void sort_struct();
void display(); //함수원형

int main(void)
{
	read_file(); //파일을 읽는 함수
	sort_struct();
	display();

	getch();
	return 0;
}

void read_file()
{
	FILE *fp = NULL; //파일포인터 선언

	fp = fopen("test.txt", "r"); //텍스트 파일을 'r'모드로 연다
	if (fp == NULL)
		printf("파일을 열지 못했습니다.\n");
	else
	{
		get_line(fp); //읽어온 파일을 토큰 단위로 구조체에 저장하는 함수
	}
}

void get_line(FILE *fp)
{
	char *line = NULL; //읽어들인 라인을 가리킬 포인터 선언
	char buffer[100] = { NULL, }; //읽어들인 라인을 저장할 배열 선언
	char *token = NULL; //토큰
	int length = 0; //구조체 배열의 길이 변수선언
	int same_check, index; //단어가 같은지 비교한 값을 저장할 변수와 인덱스 변수 선언

	while (1)
	{
		if (token == NULL){ //token이 NULL일 때. 즉, 새로운 파일을 열었거나 다음 줄을 읽어야 할 때
			line = fgets(buffer, sizeof(buffer), fp); //파일에서 한 줄을 읽어들인다

			if (line == NULL)
				break; //더 이상 읽을 라인이 없으면 반복문 종료

			token = strtok(line, "\n,. "); //토큰분리
			token = tolower_token(token); //문자열을 소문자로 변경
			index = check_same_word(token, length, &same_check); //앞서나온 단어와 같은지 검사
			if (same_check == 0) //같은 단어가 있으면
				list[index].cnt++; //해당 인덱스 cnt 증가
			else{ //같은 단어가 없으면
				strcpy(list[index].word, token); //다음 인덱스에 필드삽입
				list[index].cnt = 1;
				length++; //구조체 배열 길이증가
			}
		}
		else{
			token = strtok(NULL, "\n,. ");
			if (token != NULL){
				token = tolower_token(token);
				index = check_same_word(token, length, &same_check); //앞서나온 단어와 같은지 검사
				if (same_check == 0) //같은 단어가 있으면
					list[index].cnt++;
				else{ //같은 단어가 없으면
					strcpy(list[index].word, token);
					list[index].cnt = 1;
					length++;
				}
			}
		}
	}
}

char* tolower_token(char *token)
{
	int length = strlen(token);
	for (int i = 0; i < length; i++){
		if (token[i] < 97)
			token[i] += 32;
	} //아스키코드표를 참조하여 대문자를 소문자로 바꾼다.
	
	return token;
}

int check_same_word(char* token, int length, int *num)
{
	int i;

	for (i = 0; i < length; i++){
		*num = strcmp(list[i].word, token);
		if (*num == 0) //같은 단어라면 구조체배열 해당 인덱스 번호를 반환
			return i;
	}
	return length+1; //같은 단어가 없다면 새로 저장할 인덱스 번호 반환
}

void sort_struct()
{
	int tmp;
	int i, j;
	int check;
	for (i = 1; list[i].cnt != 0; i++){
		tmp = i;
		for (j = i+1; list[j].cnt != 0; j++){
			check = strcmp(list[tmp].word, list[j].word);
			if ( check > 0)
				tmp = j; 
		}
		list[0].cnt = list[i].cnt;
		strcpy(list[0].word ,list[i].word);

		list[i].cnt = list[tmp].cnt;
		strcpy(list[i].word, list[tmp].word);

		list[tmp].cnt = list[0].cnt;
		strcpy(list[tmp].word, list[0].word);
	} //구조체배열에서 list.word를 기준으로 선택정렬을 실행한다.
}

void display()
{
	printf("Word frequency table\n");
	for (int i = 1; list[i].cnt != 0; i++){
		printf("%s\t%d\n", list[i].word, list[i].cnt);
	}
}
