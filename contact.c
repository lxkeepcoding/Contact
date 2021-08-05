#define _CRT_SECURE_NO_WARNINGS   1

#include"contact.h"

//通过名字查找
static int FindByName(struct Contact *pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}

	//没找到
	return -1;
}

//交换
void Swap(struct peoInfo *pc1, struct peoInfo * pc2)
{
	struct peoInfo tmp;
	tmp = *pc1;
	*pc1 = *pc2;
	*pc2 = tmp;

}

//初始化通讯录
void InitContact(struct Contact *pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));//memset是用来设置内存的
}

//增加一个人的信息
void AddContact(struct Contact *pc)
{
	if (pc->sz == MAX)
	{
		printf("The address book is full and cannot be added\n");
	}
	else
	{
		printf("Please enter the name\n");
		scanf("%s", pc->data[pc->sz].name);
		printf("Please enter the age\n");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("Please enter sex\n");
		scanf("%s", pc->data[pc->sz].sex);
		printf("Please enter telephone number\n");
		scanf("%s", pc->data[pc->sz].tele);
		printf("Please enter the address\n");
		scanf("%s", pc->data[pc->sz].adrr);

		pc->sz++;

		printf("Successfully adding\n");
	}
}


//打印通讯录中的信息
void ShowContact(const struct Contact *pc)
{
	if (pc->sz == 0)
	{
		printf("\n");
		printf("*********************************************\n");
		printf("*How lonely. You don't have a friend to call*\n");
		printf("*********************************************\n");
		printf("\n");
	}
	else
	{
		int i = 0;
		//-左对齐
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-15s\n", "name", "age", "sex", "telephone", "address");
		printf("\n");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-15s\t %-4d\t %-5s\t %-12s\t %-15s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].adrr);
		}
	}
}


//删除一个人的信息
void DelContact(struct Contact *pc)
{
	char name[NAME_MAX];
	if (pc->sz == 0)//判断是否为空通讯录
	{
		printf("\n");
		printf("***********************************************\n");
		printf("*How lonely. You don't have a friend to delete*\n");
		printf("***********************************************\n");
		printf("\n");
	}
	else
	{
		//1.找到要删除的人
		printf("Please enter the name of the person you want to delete\n");
		scanf("%s", name);
		int pos = FindByName(pc, name);//检查有没有这个人
		if (pos == -1)
		{
			printf("The name can`t be found\n");
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz-1 ; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			printf("Sucessfully delete\n");

		}
		
	}
}


//查找指定联系人
void SearchContact(struct Contact *pc)
{
	char name[NAME_MAX];
	printf("Please enter the name you want to find\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("The name can`t be found\n");
	else
	{
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-15s\n", "name", "age", "sex", "telephone", "address");
		printf("\n");
		printf("%-15s\t %-4d\t %-5s\t %-12s\t %-15s\n",
				pc->data[pos].name,
				pc->data[pos].age,
				pc->data[pos].sex,
				pc->data[pos].tele,
				pc->data[pos].adrr);
		printf("\n");
	}
}


//修改信息
void ModifyContact(struct Contact *pc)
{
	char name[NAME_MAX];
	printf("Please enter the name you want to change\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("The name can`t be found\n");
	else
	{
		int input = 0;
		do
		{
			printf("Please what you want to change\n");
			printf("\n");
			printf("Note that you can only choose from the following options\n");
			printf("\n");
			printf("************************************\n");
			printf("********    1.name       ***********\n");
			printf("********    2.age        ***********\n");
			printf("********    3.sex        ***********\n");
			printf("********    4.tele       ***********\n");
			printf("********    5.adrr       ***********\n");
			printf("********    0.exit       ***********\n");
			printf("************************************\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("Please enter the name\n");
				scanf("%s", pc->data[pos].name);
				break;
			case 2:
				printf("Please enter the age\n");
				scanf("%d", &(pc->data[pos].age));
				break;
			case 3:
				printf("Please enter sex\n");
				scanf("%s", pc->data[pos].sex);
				break;
			case 4:
				printf("Please enter telephone number\n");
				scanf("%s", pc->data[pos].tele);
				break;
			case 5:
				printf("Please enter the address\n");
				scanf("%s", pc->data[pos].adrr);
				break;
			}
		} while (input);
		
		
		
		printf("Modified to complete\n");
	}

}

//清空
void EmptyContact(struct Contact *pc)
{
	assert(pc != NULL);
	pc->sz = 0;
	printf("Successfully empty\n");
}

//排序
void SortContact(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);

	//按照年龄排序(采用冒泡)
	//for(i=0; i<pc->sz-1; i++)   //趟数
	//{
	//  for(j=0; j<pc->sz-i-1; j++ )  //比较次数
	//  {
	//      if(pc->data[j].age > pc->data[j+1].age)
	//      {
	//          Swap(&pc->data[j],&pc->data[j+1]);
	//      }
	//  }
	//}
	//ShowContact(pc);


	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}