// To implement absolute loader
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char line[100],name[100],addr[50];
    int startaddr,i;
    fp=fopen("input.txt","r");
    fscanf(fp,"%s",line);
    for(  i=2; line[i]!='^';i++)
    {
        name[i-2]=line[i];
    }
    name[i-2]='\0';
    printf("Program name: %s\n",name);
    while(fscanf(fp,"%s",line)!=EOF)
    {
        
        if(line[0]=='T')
        {
            for(  i=2; line[i]!='^';i++)
            {
                addr[i-2]=line[i];
            }
            addr[i-2]='\0';
            startaddr=atoi(addr);
        }
        i=12;
        while(line[i]!='$')
        {
            if(line[i]!='^')
            {
                printf("%d\t%c%c\n",startaddr,line[i],line[i+1]);
                startaddr++;
                i=i+2;
            }
            else
            {
                i++;
            }
        }
        if(line[0]=='E')
        {
            fclose(fp);
            break;
        }
    
    }
    return 0;

}