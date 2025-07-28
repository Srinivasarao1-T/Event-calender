#include "myheader.h"
char month[12][5]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
int size=sizeof(RECORD)-sizeof(RECORD*);
void  printmenu()

{
	printf("----------------------MENU------------------------\n");
	printf("a/A:Add a new event\n");
	printf("p/P:Print calender for a month /year\n");
	printf("v/V:View all saved events\n");
	printf("d/D:Delete an event\n");
	printf("s/S:save all events from file\n");
	printf("u/U:Upcoming events from file\n");
	printf("f/F:Find event on a spefic date\n");
	printf("q/Q:Quit the application\n");
}
int checkleap(int a)
{
	if((a%100==0)||(a%4==0))
	{
		if(a%400==0)
		{
                 return 1;
		}
		if(a%100==0)
		{
		return 0;
		}
		return 1;
	}
	return 0;
}
RECORD *add_event(RECORD *ptr);
void print_cal(RECORD *ptr);
RECORD *delete(RECORD *ptr);
void upcoming_event(RECORD *ptr);
void view_event(RECORD *ptr) ;
void find(RECORD *ptr);
RECORD *sync_from_file(RECORD *head);
void save(RECORD* ptr);
int main()
{
	RECORD *ptr=NULL;
	ptr=sync_from_file(ptr);
        while(1)
	{
		printmenu();
		char choice;
		__fpurge(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a':
			case 'A':ptr=add_event(ptr);
				 break;
			case 'p':
			case 'P':print_cal(ptr);
				 break;
			case 'v':
			case 'V':view_event(ptr);
				 break;
			case 'd':
			case 'D':ptr=delete(ptr);
				 break;
		        case 's':
			case 'S':save(ptr);
				 break;
			case 'u':
		        case 'U':upcoming_event(ptr);
				 break;
	         	case 'f':
			case 'F':find(ptr);
				 break;
		        case 'Q':
			case 'q':exit(0);
			default: printf("-----INVALID OPTION-----\n");
				 break;

		}
	}
}
