#include"myheader.h"
RECORD *sync_from_file(RECORD *head)
{
        FILE*fp;
        RECORD t,*node,*temp;
        fp=fopen("record.txt","r");
        if(fp==NULL)
                return head;
        while(fread(&t,size,1,fp))
        {
        node=calloc(1,sizeof(RECORD));
        strcpy(node->id,t.id);
        strcpy(node->name,t.name);
        node->db.day=t.db.day;
        node->db.mon=t.db.mon;
        node->db.year=t.db.year;
        node->tm.hr=t.tm.hr;
        node->tm.min=t.tm.min;
                if(head==NULL)
                        head=node;
                else
                {
                        temp=head;
                        while(temp->link)
                                temp=temp->link;
                        temp->link=node;

                }

        }
        fclose(fp);
        return head;
}

