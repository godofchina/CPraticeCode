#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch, *filename;
    printf("please enter the file name:");

    scanf("%s", filename);
    if ((fp=fopen(filename, "w")) == NULL) 
    {
        printf("Unable to open this file\n");
        exit(0);
    }

    ch = getchar();
    printf("Please enter a string in the disk (End with a #):");
    ch = getchar();
    while(ch!='#')
    {
        fputc(ch, fp);
        putchar(ch);
        ch=getchar();
    }

    fclose(fp);
    putchar(10);

    return 0;
}
