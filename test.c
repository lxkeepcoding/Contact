#define _CRT_SECURE_NO_WARNINGS   1

//************************************
//通讯录                             *
//保存1000个人的信息                 *
//名字                               *
//年龄                               *
//性别                               *
//电话                               *
//住址                               *
//功能：1.增加一个人的信息           *
//      2.删除一个人的信息           *
//      3.查找一个人的信息           *
//      4.修改一个指定联系人         *
//      5.显示所有人信息             *
//************************************



#include"contact.h"
void menu()
{
	printf("****************************************\n");
	printf("*******1.add       2.del       *********\n");
	printf("*******3.search    4.modify    *********\n");
	printf("*******5.show      6.sort      *********\n");
	printf("*******7empty      0.exit      *********\n");
	printf("****************************************\n");
	printf("****************************************\n");
}
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};
void test()
{
	int input=0;
	struct Contact con;//创建出一个通讯录
	InitContact(&con);//初始化通讯录传地址（结构体传参传地址效率高，并且要可以修改con）
	do
	{
		menu();
		printf("please make your choice >>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EMPTY:
			break;
			EmptyContact(&con);
		case EXIT:
			printf("please quit>>\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}