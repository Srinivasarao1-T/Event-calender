#include"myheader.h"
void upcoming_event(RECORD *ptr)
{
        RECORD *temp=ptr;
        if(ptr==NULL)
        {
                puts("-----NO EVENTS ARE AVALIBLE------------");
                return;
        }
        puts("Enter the month");
        int val,flag=0;
        scanf("%d",&val);
        while(temp!=NULL)
        {
                if(temp->db.mon==val)
                {
                        if(flag==0){
                        puts("-------------The events found in this month are------------");
                        flag=1;
                        }
                        printf("%s\n",temp->id);
                }
                temp=temp->link;
        }
        if(flag==0)
        {
                printf("NO EVENTS ARE FOUND\n");
        }

}

