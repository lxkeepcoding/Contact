#include<stdio.h>
#include<string.h>
#include<assert.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 20
#define ADRR_MAX 30
#define MAX 1000


//描述一个人的信息的结构体
struct peoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char adrr[ADRR_MAX];
};


//通讯录信息的结构体
struct Contact
{
	//通讯录存放1000个人信息的空间
	struct peoInfo data[MAX];
	//通讯录当前存放的人信息条数
	int sz;
};



//函数的声明

//初始化通讯录函数
void InitContact(struct Contact *pc);

//增加一个人的信息
void AddContact(struct Contact *pc);

//打印通讯录中的信息
void ShowContact(const struct Contact *pc);

//删除一个人的信息
void DelContact(struct Contact *pc);

//查找指定联系人
void SearchContact(struct Contact *pc);

//修改信息
void ModifyContact(struct Contact *pc);

//清空
void EmptyContact(struct Contact *pc);

//排序
void SortContact(struct Contact *pc);