#include"myheader.h"
void find(RECORD *ptr)
{
        RECORD *temp=ptr;
        if(ptr==NULL)
        {
                puts("-----NO EVENTS ARE AVALIBLE------------");
                return;
        }
        puts("Enter the event id:");
        char str[15];
        __fpurge(stdin);
        fgets(str,15,stdin);
        str[strlen(str)-1]='\0';
        while(temp!=NULL)
        {
                if(strcmp(str,temp->id)==0)
                {
                        break;
                }
                temp=temp->link;
        }
        if(temp!=NULL)
        {
                puts("Your event id");
                puts(temp->id);
                puts("Event is");
                puts(temp->name);
                puts("Date/time");
                printf("(%d/%d/%d)/(%d:%d)\n",temp->db.day,temp->db.mon,temp->db.year,temp->tm.hr,temp->tm.min);
                puts(temp->des);
        }
        else{
                puts("-----NO EVENTS ARE AVALIBLE------------");
        }
}

