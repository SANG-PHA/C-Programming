#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void get_sentences(char* s);
void translator(char s[], char* p);
char* get_next_word(char s[], int *check1, int *index);
void display(char s[], char p[]);

int main(void)
{
	char s[SIZE], p[SIZE] = { NULL };
	int check = 0; //메인함수에서의 반복문 제어를 위한 변수 선언
	do{

		get_sentences(s); //문자열 입력
		translator(s, p); //문장을 변환
		display(s, p); //출력

		printf("하시려면 1을 입력하세요.");
		scanf("%d", &check);
		getchar(); //버퍼제거

		for (int i = 0; i < SIZE; i++)
			p[i] = NULL; //배열 p의 값 초기화

	} while (check != 1); //사용자로부터 1을 입력받으면 반복문 종료

	printf("프로그램을 종료합니다.");
	getch();
	return 0;
}

void get_sentences(char* s)
{
	printf("문자열을 입력하시오 : ");
	gets(s);
}

void translator(char s[], char* p)
{
	char *token; //분리된 단어를 받을 pointer to character 변수 선언
	int check1 = 0; //반복문 제어를 위한 변수 선언
	int index = 0; //get_next_word에서 토큰 분리를 위한 인덱스번호 저장 변수 선언

	do{
		token = get_next_word(s, &check1, &index);

		if (token[0] == 'a' || token[0] == 'e' || token[0] == 'o' || token[0] == 'i' || token[0] == 'u' ||
			token[0] == 'A' || token[0] == 'E' || token[0] == 'O' || token[0] == 'I' || token[0] == 'U') //단어의 첫 글자가 모음이면

			strcat(p, token); //배열 p에 단어를 이어붙인다
			strcat(p, "ay "); //단어 뒤에 "ay"입력
		}
		else //단어의 첫 글자가 자음이면
		{
			/*첫 글자를 단어의 맨 뒤로 옮긴다*/
			int n = strlen(token);
			char tmp_tok = token[0];
			for (int i = 0; i < n - 1; i++)
				token[i] = token[i + 1];
			token[n-1] = tmp_tok; 
			/*===============================*/

			strcat(p, token); //배열 p에 바뀐 단어를 이어붙인다
			strcat(p, "ay "); //단어 뒤에 "ay"입력
		}

	} while (check1 != 1);
}

char* get_next_word(char s[], int *check1, int *index)
{
	char token[10] = {NULL} ; //단어를 저장할 배열 선언 및 초기화
	int length = strlen(s); //입력받은 배열의 길이 저장
	int j = 0; //토큰 인덱스번호 변수 선언

	// ★★★
	for (int i = *index; i < length; i++)
	{
		if (s[i] != ' '){
			token[j] = s[i];
			j++;
		}
		else{
			*index = i + 1;
			return token;
		}
	}	
	*check1 = 1;
	// ★★★

	return token;
}

void display(char s[], char p[])
{
	printf("입력받은 배열 : ");
	puts(s);
	printf("변경된 배열 : ");
	puts(p);
	printf("\n");
}
