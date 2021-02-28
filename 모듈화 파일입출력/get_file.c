#include "pgm.h"
#include "get_file.h"

void get_file(FILE* fp)
{
	fp = fopen("personnel.txt", "r"); //텍스트 파일을 'r'모드로 연다
	if (fp == NULL)
		printf("파일을 열지 못했습니다.\n");
	else
	{
		process_line(fp); //읽어온 파일을 토큰 단위로 구조체에 저장하는 함수
	}

	fclose(fp);
}

void process_line(FILE* fp)
{
	char buffer[LINE_SIZE];
	char* token = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fp) != NULL){
		employee[i].is_using = TRUE;

		token = strtok(buffer, " ");
		strcpy(employee[i].last_name, token);

		token = strtok(NULL, " ");
		strcpy(employee[i].first_name, token);

		token = strtok(NULL, " ");
		employee[i].soc_sec_num = atoi(token);

		token = strtok(NULL, " ");
		employee[i].department = atoi(token);

		token = strtok(NULL, " ");
		employee[i].current_salary = atof(token);

		i++;
	}
}
