#include <stdio.h>
#include <stdlib.h>

void get_time(struct time* start_time, struct  time* end_time);
struct time elapsed_time(struct time start_time, struct  time end_time);

struct time{
	int hour;
	int min;
	int sec;
};

int main(void)
{
	struct time start_time , end_time;
	struct time result_time;

	get_time(&start_time, &end_time);
	result_time = elapsed_time(start_time, end_time);

	printf("실행 시간 : (%d:%d:%d)", result_time.hour, result_time.min, result_time.sec);

	getch();
	return 0;
}

void get_time(struct time* start_time, struct  time* end_time)
{
	printf("시작 시간을 입력 하시오(hour:min:sec) : ");
	scanf("%d:%d:%d", &(start_time->hour), &(start_time->min), &(start_time->sec));
	printf("종료 시간을 입력 하시오(hour:min:sec) : ");
	scanf("%d:%d:%d", &(end_time->hour), &(end_time->min), &(end_time->sec));
}

struct time elapsed_time(struct time start_time, struct time end_time)
{
	struct time result;

	//sec 계산
	if (end_time.sec < start_time.sec) //strat_time.sec이 end_time.sec보다 클 때
	{
		if (end_time.min > 0) //end_time.min이 0보다 크면
			end_time.min = end_time.min - 1;
		else //end_time.min이 0보다 작으면
		{
			end_time.hour = end_time.hour - 1;
			end_time.min = end_time.min + (60 - 1);
		}
		result.sec = end_time.sec + (60 - start_time.sec);
	}
	else //start_time.sec 이 end_time.sec보다 작을 때
		result.sec = end_time.sec - start_time.sec;

	//min계산
	if (end_time.min < start_time.min)
	{
		end_time.hour = end_time.hour - 1;
		result.min = end_time.min + (60 - start_time.min);
	}
	else
		result.min = end_time.min - start_time.min;

	//hour계산
	if (end_time.hour > start_time.hour) //end_time.hour이 start_time.hour보다 클 때
		result.hour = end_time.hour - start_time.hour;
	else //end_time.hour이 start_time.hour보다 작을 때. 즉, 전날 실행된 프로그램
		result.hour = end_time.hour + (24 - start_time.hour);

	return result; //결과가 저장된 구조체 반환
}
