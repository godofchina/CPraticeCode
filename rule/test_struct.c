#include <stdio.h>

typedef struct 
{
	char *name;
	int id;
}student, *teacher;

//为什么要这样用
void test(teacher *ergou)
{
	(*ergou)->name = "李狗娃";
	printf("%s\n", (*ergou)->name);
	// return void;
}

void test_a(student *haha)
{
	haha->name = "hahaa";
	printf("%s\n", haha->name);
}

int main()
{
	// student gouge;
	teacher ergou;
	ergou->name = "王二狗";
	printf("%s\n", ergou->name);
	// gouge.id   = 1;
	test(&ergou);
	student haha;
	test_a(&haha);
	return 0;
}