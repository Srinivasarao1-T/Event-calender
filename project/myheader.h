#ifndef _MYHEADER_H_
#define _MYHEADER_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<unistd.h>
typedef struct dob
{
        int day;
        int mon;
        int year;
}DOB;
typedef struct
{
        int hr;
        int min;
}TIME;
typedef struct node
{
        char id[15];
        char name[20];
        DOB db;
        TIME tm;
        char des[100];
        struct node *link;

}RECORD;
extern char month[12][5];
extern int size;
//char month[12][5]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
//int size=sizeof(RECORD)-sizeof(RECORD*);
#endif
/*int checkleap(int a)
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
}*/

