/*
���������������ڲ���ͷ���ĵ�����L�����һ���ݹ��㷨�������н�㡣
			��д������ʵ����򣬲�������Ӧ���ݽ��в��ԡ�
*/
#include<iostream>
#include<list>
#include<malloc.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{	ElemType data;
	struct Node *next;
} LinkNode;
void CreateList(LinkNode *&L,ElemType a[],int n)	//��a[0..n-1]����������L
{
	LinkNode *p, *r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->data=a[0];
	r=L;					//rָ��ǰβ���
	for (int i=1;i<n;i++)
	{
		p=(LinkNode *)malloc(sizeof(LinkNode));
		p->data=a[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;			//β���next����Ϊ��
}
void DispList(LinkNode *L)	//���������L
{
	LinkNode *p=L;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
LinkNode *Reverse(LinkNode *L)	//���ò���ͷ���ĵ�����L
{	LinkNode *p,*q;
	if (L==NULL || L->next==NULL)
		return L;
	p=Reverse(L->next);
	q=L->next;
	q->next=L;
	L->next=NULL;
//	L->next->next=L; 			//��L������ӵ�L->next������
//	L->next=NULL;				//��L�����Ϊ�������ú��β���
	return p;
}
int main()
{
	ElemType a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkNode *L;
	CreateList(L,a,n);
	cout<<"ʵ����:"<<endl;
	cout<<"  ����ǰL: "<<endl;
	DispList(L);
	cout<<"  ִ��L=Reverse(L)"<<endl;
	L=Reverse(L);
	cout<<"  ���ú�L: "<<endl;
	DispList(L);
	return 0;
}
