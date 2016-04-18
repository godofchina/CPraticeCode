#include <stdio.h>
void main()
{
　　union number
　　{
		/*定义一个联合*/
	　　int i;
	　　struct
	　　{
			/*在联合中定义一个结构*/
		　　char first;
		　　char second;
	　　}half;
　　}num;

　　num.i=0x4241; /*联合成员赋值*/
　　printf("%c%c\n", num.half.first, num.half.second);
　　num.half.first='a'; /*联合中结构成员赋值*/
　　num.half.second='b';
　　printf("%x\n", num.i);
　　getchar();
}