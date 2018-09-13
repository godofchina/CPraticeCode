#include <stdio.h>
#include <stdlib.h>

void copy(char *from,  char *to)
{
    FILE *f1, *f2;
    char ch;
    //从from中读取内容
    if ((f1 = fopen(from, "r")) == NULL) {
        printf("Unable to open file %s\n", from);
        exit(0);
    }

    if (fopen(to, "r")) {
        printf("File %s already exists\n", to);
        exit(0);
    }
    
   f2 = fopen(to, "w");

    while((ch = getc(f1)) != EOF) {
        fputc(ch, f2);
    }

    fclose(f1);
    fclose(f2);

}
