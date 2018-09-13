#include <stdio.h>
#include "copy.h"

void copy(char *from, char *to);

int main(int argc, char **argv)
{
    printf("from is %s, to is %s\n", argv[1], argv[2]);
    char *from, *to;
    from = argv[1];
    to = argv[2]; 
    copy(from, to);
    return 0;
}
