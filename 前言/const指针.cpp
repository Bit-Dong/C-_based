#include<iostream>
using namespace std;

int main()
{
	int a=10;
	int b=20;

	//1. ����ָ��  const���ε���ָ�룬ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը�
	const int *p1=&a;
	p1=&b;   //��ȷ
//	*p1=100;  ����
    cout<<p1<<endl;
	cout<<*p1<<endl;
	
	//2. ָ�볣��  const���ε��ǳ�����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
	int * const p2=&a;
//	p2=&b;  ����
	*p2=100;  //��ȷ
	cout<<p2<<endl;
	cout<<*p2<<endl;
	
	//3. const������ָ�������γ���
	const int * const p3=&a;
//	p3=&b;    ����
//	*p3=100;  ���� 
	cout<<p3<<endl;
	cout<<*p3<<endl;
	
	system("pause");
	return 0;
} 
