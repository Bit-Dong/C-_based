#include<iostream>
using namespace std;

//�������ص�ע����� 
//            1�� ������Ϊ���ص�����
//            2�� ����������������Ĭ�ϲ���

//������Ϊ�������� 
void func(int &a)
{
	cout<<"func(int &a)�ĵ��ã�"<<endl; 
}

void func(const int &a)
{
	cout<<"func(const int &a)�ĵ��ã�"<<endl; 
}

//����������������Ĭ�ϲ���
void func2(int a,int b=10)   //int b=10����Ĭ�ϲ��� 
{
	cout<<"func2(int a,int b=10)�ĵ��ã�"<<endl; 
}

void func2(int a)
{
	cout<<"func2(int a)�ĵ��ã�"<<endl; 
}

int main()
{
	int a=10;
	func(a);     //������const�� 
	func(10);    //������const�� 
	
//	fun2(10);    //����  ��������������Ĭ�ϲ��������ֶ����ԣ�������������������� 
	func2(10,20); 
}
