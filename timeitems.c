#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define BUFFSIZE 69

#define CLSCREEN() fputs("\033[2J\033[1;1H", stdout)

#define STDLINE() MkLine(50, '*')

typedef struct _TimeItems {
	time_t Rest_Intervals;
	time_t Stretch_Time;
	uint32_t Repetitions;
} TimeItems;

void EllapsedTime(time_t Seconds, bool PrintSecs)
{
	if(Seconds<0) {
		fputs("Segmentation Fault", stderr);  //Intentionally done
		EXIT(EXIT_FAILURE);
	}

	time_t *TimeVar=&time;
	time_t StartTime=time(&TimeVar);

	while(true) {
		static time_t Prior_Time=0;
		time_t EllapsedTime=time(&TimeVar)-StartTime;
		if(PrintSecs && Prior_Time!=EllapsedTime) {
			printf("\t----->>>>>>You're on %ld of %ld seconds!\n", EllapsedTime, Seconds);
			Prior_Time=EllapsedTime;
		}
		if(EllapsedTime==Seconds)return;
	}

	fputs("Fuck you - unknown error", stderr);
	EXIT(EXIT_FAILURE);
}

uint32_t GetNumber()
{
	uint32_t NumbToReturn=0;
	char buff[BUFFSIZE]="\0";
	while(NumbToReturn<1 || NumbToReturn>100) {
		fputs( "\tNumber must be between 0 & 100->>>>>", stdout);
		fgets(buff, BUFFSIZE-1, stdin);
		NumbToReturn=strtol(buff, 0, 10);
	}
	return NumbToReturn;
}

TimeItems SetTimeItems(void)
{
	TimeItems SetTimeItems_TimeItems;
	memset(&SetTimeItems_TimeItems, 0, sizeof(TimeItems));

	fputs("Enter Rest Intervals in Secs:\n", stdout);
	SetTimeItems_TimeItems.Rest_Intervals=GetNumber();
	CLSCREEN();

	fputs("Enter Stretch Intervals in Secs:\n", stdout);
	SetTimeItems_TimeItems.Stretch_Time=GetNumber();
	CLSCREEN();

	fputs("Enter Total Reps:\n", stdout);
	SetTimeItems_TimeItems.Repetitions=GetNumber();
	CLSCREEN();

	return SetTimeItems_TimeItems;
}

void MkLine(uint32_t LineSize, char Symbal)
{
	for(uint32_t count=0; count<LineSize; count++)
	{
		putc(Symbal, stdout);
	}
	putc('\n', stdout);
	return;
}

void ExecuteStretch(const TimeItems ExecuteStretch_TimeItems)
{
	for(int count=0; count<=ExecuteStretch_TimeItems.Repetitions; count++)
	{
		STDLINE();
		fprintf(stdout, "You're on set: %d of %d\n", count, ExecuteStretch_TimeItems.Repetitions);
		STDLINE();
		fputs("Resting State\b\n", stdout);
		EllapsedTime(ExecuteStretch_TimeItems.Rest_Intervals, 1);
		STDLINE();
		fputs("Stretch State\b\n", stdout);
		EllapsedTime(ExecuteStretch_TimeItems.Stretch_Time, 1);
		CLSCREEN();
	}
}

int main()
{
	CLSCREEN();
	TimeItems TimeItems=SetTimeItems();
	ExecuteStretch(TimeItems);
}
