#include "myheader.h"
void print_cal(RECORD *ptr)
{
   RECORD *temp=ptr;
   printf("calender of 2025\n");
   //printf("S\tM\tT\tW\tT\tF\tS\n");
   int a,s,t=3;
   for(int i=1;i<=12;i++)
   {
       printf("%s\n",month[i-1]);
        printf("S\tM\tT\tW\tT\tF\tS\n");
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) a=31;
        if(i==4||i==6||i==9||i==11) a=30;
        if(i==2) a=28;
        for(s=t;s>=1;s--)
        {
          printf(" \t");
        }
         for(int j=1;j<=a;j++)
         {
                 if(t==7)
                 {
                         t=0;
                         printf("\n");
                 }
                 temp=ptr;

                 while(temp!=NULL)
                 {
                         if((i==temp->db.mon)&&(j==temp->db.day))
                         {
                                 break;
                         }
                         temp=temp->link;
                 }
                 if(temp!=NULL){
                 printf("E\t");
                 }
                 else
                 {
                         printf("%d\t",j);
                 }
                 t++;
         }
         printf("\n");
   }

}

