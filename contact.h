#include<stdio.h>
#include<string.h>
#include<assert.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 20
#define ADRR_MAX 30
#define MAX 1000


//����һ���˵���Ϣ�Ľṹ��
struct peoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char adrr[ADRR_MAX];
};


//ͨѶ¼��Ϣ�Ľṹ��
struct Contact
{
	//ͨѶ¼���1000������Ϣ�Ŀռ�
	struct peoInfo data[MAX];
	//ͨѶ¼��ǰ��ŵ�����Ϣ����
	int sz;
};



//����������

//��ʼ��ͨѶ¼����
void InitContact(struct Contact *pc);

//����һ���˵���Ϣ
void AddContact(struct Contact *pc);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact *pc);

//ɾ��һ���˵���Ϣ
void DelContact(struct Contact *pc);

//����ָ����ϵ��
void SearchContact(struct Contact *pc);

//�޸���Ϣ
void ModifyContact(struct Contact *pc);

//���
void EmptyContact(struct Contact *pc);

//����
void SortContact(struct Contact *pc);