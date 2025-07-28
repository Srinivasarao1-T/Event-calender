#include"myheader.h"
RECORD *delete(RECORD *ptr)
{
        RECORD *temp=ptr,*pre=NULL;
        if(ptr==NULL)
        {
                printf("-----------NO EVENTSFOUND------------\n");
                return NULL;
        }
        puts("Enter the Event id\n");
        char str[20];
        __fpurge(stdin);
        fgets(str,20,stdin);
        str[strlen(str)-1]='\0';
        if(strcmp(ptr->id,str)==0)
        {
                printf("--------EVENT FOUND DELETED----------\n");
                ptr= ptr->link;
                free(temp);
                return ptr;
        }
        while(temp!=NULL)
        {
                //pre=temp;
                if(strcmp(temp->id,str)==0)
                {
                        break;
                }
                pre=temp;
                temp=temp->link;
        }
        if(temp!=NULL)
        {
             pre->link=temp->link;
             free(temp);
             return ptr;
        }
        else{
                puts("-------------EVENT NOT FOUND----------");
                return ptr;
        }
}

