#include<iostream>
#include<string>
using namespace std;

//ֵ����    
int txt1(int a,int b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

//��ַ����
int txt2(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
} 

//���ô���
int txt3(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
 } 
 
int main()
{
	int a=10,b=20;
	//txt1(a,b);        //ֵ���ݣ��ββ�������ʵ�� 
	//txt2(&a,&b);      //��ַ���ݣ��β�������ʵ�� 
	txt3(a,b);          //���ô��ݣ��β�������ʵ�� 
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	
	system("pause");
}
