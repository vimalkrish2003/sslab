#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char relocatingbits[16] = {0};

void convert(char bitmask[10])
{
    for (int i = 0; bitmask[i] != '\0'; i++)
    {
        switch (bitmask[i])
        {
        case '0':
            strcat(relocatingbits, "0");
            break;
        case '1':
            strcat(relocatingbits, "1");
            break;
        case '2':
            strcat(relocatingbits, "10");
            break;
        case '3':
            strcat(relocatingbits, "11");
            break;
        case '4':
            strcat(relocatingbits, "100");
            break;
        case '5':
            strcat(relocatingbits, "101");
            break;
        case '6':
            strcat(relocatingbits, "110");
            break;
        case '7':
            strcat(relocatingbits, "111");
            break;
        case '8':
            strcat(relocatingbits, "1000");
            break;
        case '9':
            strcat(relocatingbits, "1001");
            break;
        case 'A':
            strcat(relocatingbits, "1010");
            break;
        case 'B':
            strcat(relocatingbits, "1011");
            break;
        case 'C':
            strcat(relocatingbits, "1100");
            break;
        case 'D':
            strcat(relocatingbits, "1101");
            break;
        case 'E':
            strcat(relocatingbits, "1110");
            break;
        case 'F':
            strcat(relocatingbits, "1111");
            break;
        }
    }
 
}

int main()
{
    char input[30], name[30], bitmask[10];
    int startaddr, taddr, tlen,opcode,operandaddr;
    FILE *fp;
    printf("Enter the actual starting address :");
    scanf("%x", &startaddr);
    fp = fopen("input.txt", "r");
    fscanf(fp, "%s", input);
    printf("ADDRESS\tCONTENT\n");
    while ((strcmp(input, "E")) != 0)
    {
        printf("inside e\n");
        if (strcmp(input ,"T") == 0)
        {
            printf("inside t\n");
            fscanf(fp, "%x", &taddr);
            fscanf(fp, "%x", &tlen);
            fscanf(fp, "%s", bitmask);
            taddr+=startaddr;
            convert(bitmask);
            for(int i=0;i<tlen;i++)
            {
                fscanf(fp,"%x",&opcode);
                fscanf(fp,"%x",&operandaddr);
                if(relocatingbits[i]==1)
                {
                    operandaddr+=startaddr;
                }
                //printf("\n%x\t\t%x%x",taddr,opcode,operandaddr);
                taddr+=3;

            }

        }
        fscanf(fp,"%s",input);
    }
 
    return 0;
}

