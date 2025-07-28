#include"myheader.h"
void save(RECORD* ptr)
{
        FILE *fp=NULL;
        fp=fopen("record.txt","w");
        if(ptr==NULL)
        {
                printf("no nodes to save\n");

        }
        else
        {
        while(ptr)
        {
                fwrite(ptr,size,1,fp);
                ptr=ptr->link;
        }
        }
        fclose(fp);
}

