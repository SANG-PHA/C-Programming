#include <stdio.h>
#include <stdlib.h>
#define LINE_SIZE 60
#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0
struct employee{
	int is_using;
	char last_name[MAX_SIZE];
	char first_name[MAX_SIZE];
	int soc_sec_num;
	int department;
	double current_salary;
	double projected_salary;
}employee[MAX_SIZE];
