#include"myheader.h"
RECORD *add_event(RECORD *ptr)
{
        RECORD *new=calloc(1,sizeof(RECORD));
        puts("Enter the event name");
        scanf("%s",new->name);
        /*puts("Enter the day month year");
        scanf("%d%d%d",&new->db.day,&new->db.mon,&new->db.year);*/
//      puts("Enter the year");
        new->db.year=2025;
        int flag=0;
        /*if(checkleap(new->db.year))
        {
                flag=1;
        }*/

        int a;
m:      puts("Enter the mon (1-12)");
        scanf("%d",&new->db.mon);
        a=new->db.mon;
        if(!(a>0&&a<13))
        {
                printf("-----INVALID OPTION-----\n");
                goto m;
        }
d:      puts("Enter the day(1-31)");
        scanf("%d",&new->db.day);
        if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
        {
                if(!(new->db.day>0&&new->db.day<32)) {
                printf("-----INVALID OPTION-----\n");
                        goto d;
                }
        }
         if(a==4||a==6||a==9||a==11)
         {
                if(!(new->db.day>0&&new->db.day<31)){
                printf("-----INVALID OPTION-----\n");
                        goto d;
                }
         }
         if(a==2&&flag==1)
         {
                if(!(new->db.day>0&&new->db.day<30)) {
                printf("-----INVALID OPTION-----\n");
                        goto d;
                }
         }
         if(a==2)
         {
                if(!(new->db.day>0&&new->db.day<29)) {
                printf("-----INVALID OPTION-----\n");
                        goto d;
                }
         }
h:     puts("Time is in 24hrs formate");
        puts("Enter the event time hrs:");
        scanf("%d",&new->tm.hr);
        a=new->tm.hr;
       if(!(a>=0&&a<=23))
       {
                printf("-----INVALID OPTION-----\n");
                        goto h;
       }
mi:       puts("Enter the event time min:");
       scanf("%d",&new->tm.min);
       if(!(new->tm.min<=59&&new->tm.min>=0))
       {
                printf("-----INVALID OPTION-----\n");
                        goto mi;
       }
       puts("Enter the description");
      __fpurge(stdin);
       fgets(new->des,100,stdin);
       //new->link=ptr;
       //srand(getpid());
       //a=rand()%100;
       new->id[0]='E';
       new->id[1]='V';
       new->id[2]=((new->db.year/10)%10)+48;
       new->id[3]=(new->db.year%10)+48;
       memmove(new->id+4,month[new->db.mon-1],3);
       new->id[7]=(new->db.day/10)+48;
       new->id[8]=(new->db.day%10)+48;
       new->id[9]='\0';
       if(ptr==NULL)
       {
             printf("--------EVENT IS BOOKED----------\n");
                       printf("your event id is %s\n",new->id);
               return new;
       }
       else{
               RECORD *temp=ptr;
               while(temp!=NULL)
               {
                       if(strcmp(temp->id,new->id)==0)
                       {
                               break;
                       }
                       temp=temp->link;

               }
               if(temp==NULL)
               {
                       printf("--------EVENT IS BOOKED----------\n");
                       printf("your event id is %s\n",new->id);
                       new->link=ptr;
                       ptr=new;
               }
               else
               {
                       printf("--------NO VACANCY----------\n");
                       free(new);
                       new=NULL;
               }
       }

       return ptr;
}

