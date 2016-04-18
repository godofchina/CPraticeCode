#include <stdio.h>

int main()
{
	//结构体的定义 成员赋值
	struct student
	{
		char *name;
		int id;
	};

	struct student xiaobai = {"xiaobai",1};
	printf("xiaobai's name:%s\n", xiaobai.name);
	struct student xiaohong = {"xiaohong",2};
	printf("xiaohong's name:%s\n", xiaohong.name);
	struct student xiaohei = xiaohong;
	printf("xiaohei's name:%s\n", xiaohei.name);
	struct student xiaolan;
	xiaolan.name = "xiaolan";
	xiaolan.id   = 5;
	printf("xiaolan's name:%s\n", xiaolan.name);

	//结构体的初始化定义的简单写法
	struct
	{
		char *name;
		char *nickname;
	}primary;
	primary.name = "alex";
	primary.nickname = "ally";
	printf("primary's name:%s\n", primary.name);

	//结构体的嵌套
	struct teacher
	{
		int id;
		struct
		{
			char *province;
			char *city;
		}address;
	};

	struct teacher nj;
	nj.id = 1;
	nj.address.province = "shanxi";
	nj.address.city  	= "yuncheng";
	printf("teacher nj's address province:%s\n", nj.address.province);

	//结构体与指针
	struct student *xiaolu;
	xiaolu->name = "donkey";
	xiaolu->id   = 6;
	printf("xiaolu's name:%s\n", xiaolu->name);

	typedef struct test
	{
		struct test *next;
	}to, *ta;

	ta temp;
	temp->next = NULL;
	
	// printf("pointer's struct ta:%d\n", temp.next);
	// printf("test's mem:%d\n", sizeof(to));

	//结构体和数组
	struct datatype
	{
		int arr[3];
		int temp;
	};
	struct datatype array[3] = {
		{12,12,12,0},
		{13,13,13,1},
		{14,14,14,2}
	};
	printf("third arr:%d\n", array[0].arr[0]);
	return 0;
}
