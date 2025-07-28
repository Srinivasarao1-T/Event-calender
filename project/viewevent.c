#include"myheader.h"
void view_event(RECORD *ptr)
{
        RECORD *temp=ptr;
        if(ptr==NULL)
        {
                puts("-----NO EVENTS ARE AVALIBLE------------");
                return;
        }
        puts("---------EVENT AVALIBLE-----------");
        while(temp!=NULL)
        {
           puts(temp->id);
           temp=temp->link;
        }
}

