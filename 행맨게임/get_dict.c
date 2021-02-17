#include "pgm.h"
#include "get_dict.h"

void get_dict()
{
	FILE *fp = NULL; 
	fp = open_file(fp); //파일 오픈

	for (int i = 0; i < NUM_OF_DICT; i++)
		fscanf(fp, "%s", dict[i]);
	
	fclose(fp);
}

FILE* open_file(FILE *fp)
{
	fp = fopen("dict.txt", "r");

	if (fp == NULL)
		printf("파일을 열지 못하였습니다.");
	else
		return fp;
}
