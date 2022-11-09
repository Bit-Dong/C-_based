#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		static int A;    //��̬��Ա �������� �������ʼ�� 
		
		static void func()
		{
			cout<<"Base - static void func()"<<endl;
		}
		
		static void func(int a)
		{
			cout<<"Base - static void func(int a)"<<endl;
		}
};
int Base::A=100;   //��ʼ�� 

class son :public Base
{
	public:
		static int A;    //��̬��Ա �������� �������ʼ�� 
		
		static void func()
		{
			cout<<" son - static void func()"<<endl;
		}
		
};
int son::A=200;   //��ʼ�� 

//ͬ����̬��Ա���� 
void test01()
{
	//1��ͨ���������
	cout<<"ͨ��������ʣ�"<<endl;
	son s;
	cout<<"son �� A = "<<s.A<<endl; 
	cout<<"Base�� A = "<<s.Base::A<<endl;
	
	//2��ͨ����������
	cout<<"ͨ���������ʣ�"<<endl;
	cout<<"son �� A = "<<son::A<<endl; 
	cout<<"Base�� A = "<<son::Base::A<<endl;    //��һ����������ͨ��������ʽ����   �ڶ�������������ʸ����������� 
}

//ͬ����̬��Ա����
void test02()
{
	//1��ͨ��������� 
	cout<<"ͨ���������:"<<endl;
	son s;
	s.func();
	s.Base::func();
	
	//2��ͨ����������
	cout<<"ͨ����������:"<<endl;
	son::func();
	son::Base::func();
	
//    ������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
//    �������ʸ����б����ص�ͬ����Ա��������Ҫ�������� 
	son::Base::func(100);
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
