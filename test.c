#define _CRT_SECURE_NO_WARNINGS   1

//************************************
//ͨѶ¼                             *
//����1000���˵���Ϣ                 *
//����                               *
//����                               *
//�Ա�                               *
//�绰                               *
//סַ                               *
//���ܣ�1.����һ���˵���Ϣ           *
//      2.ɾ��һ���˵���Ϣ           *
//      3.����һ���˵���Ϣ           *
//      4.�޸�һ��ָ����ϵ��         *
//      5.��ʾ��������Ϣ             *
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
	struct Contact con;//������һ��ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼����ַ���ṹ�崫�δ���ַЧ�ʸߣ�����Ҫ�����޸�con��
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}