#include "pgm.h"
#include "print_result.h"

void print_result(FILE* fp, double total_salary)
{
	fp = fopen("PROJECTED_RAISES.txt", "w"); //파일 w모드로 열기

	if (fp == NULL)
		printf("파일을 열지 못했습니다.\n");
	else
	{
		print_to_file(fp, total_salary); //읽어온 파일을 토큰 단위로 구조체에 저장하는 함수
	}

	fclose(fp);
}

print_to_file(FILE* fp, double total_salary)
{
	fputs("                              PROJECTED RAISES\n", stdout);
	fputs("Last Name\tFirst Name\tCurrent Weekly Salary\tProjected Weekly Salary\n", stdout);
	fputs("                                   PROJECTED RAISES\n", fp);
	fputs("Last Name\t\tFirst Name\t\tCurrent Weekly Salary\t\tProjected Weekly Salary\n", fp);

	for (int i = 0; employee[i].is_using == TRUE; i++){
		fprintf(stdout, "%s\t\t%s\t\t%.2f\t\t\t%.2f\n", employee[i].last_name, employee[i].first_name, employee[i].current_salary, employee[i].projected_salary);
		fprintf(fp, "%s\t\t\t%s\t\t\t%.2f\t\t\t\t%.2f\n", employee[i].last_name, employee[i].first_name, employee[i].current_salary, employee[i].projected_salary);
	}

	fprintf(stdout, "Total Projected Weekly Salary : %.2f", total_salary);
	fprintf(fp, "Total Projected Weekly Salary : %.2f", total_salary);
}
