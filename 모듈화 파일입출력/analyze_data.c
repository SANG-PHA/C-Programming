#include "pgm.h"
#include "analyze_data.h"

double analyze_data()
{
	double total_salary = 0;

	for (int i = 0; employee[i].is_using == TRUE; i++){
		employee[i].projected_salary = employee[i].current_salary * 1.1;
		total_salary = total_salary + employee[i].projected_salary;
	}

	return total_salary;
}
