#define INCL_DOSFILEMGR
#include <os2.h>

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(int argc, char **argv)
{
    FILE *input, *output;
    int j;
    char buffer[81];
    
    if(argc<3)
    {
        puts("CleanUUD:  Removes the > and spaces from quoted uuencoded files");
        printf("Syntax:\n\t%s input.uud output.uud\n", argv[0]);
        exit(0);
    }

    if( (input=fopen(argv[1], "r"))==NULL)
    {
        puts("Error:\n\tCould not open input filename!");
        exit(1);
    }
    
    if ((output=fopen(argv[2], "w+"))==NULL)
    {
        puts("Error:\n\tCould not create output filename!");
        exit(2);
    }
    while(fgets(buffer,80, input)!=NULL)
    {
        if(buffer[0]=='>')
        {
            j=1;
            while( ((buffer[j]=='>') || (buffer[j]==' ')) && (buffer[j]!='\0') )
                j++;
            fputs(buffer+j, output);    
        }
        else
            fputs(buffer, output);
    }
    fclose(input);
    fclose(output);
}
