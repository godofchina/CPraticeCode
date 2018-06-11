#include <stdio.h>
#define STR(x) #x
 
int main(int argc, char** argv)
{
    printf("%s\n", STR(It's a long string)); // 输出 It's a long string
    return 0;
}
