#include<iostream>
#include<string>
using namespace std;

//���麯���ͳ�����                         		//  ���麯��    ֻҪ��һ�����麯����������Ϊ������ 
class Base                                     //  �������ص㣺 
{                                             // 1���޷�ʵ��������    ���磺Base a��new Base���ᱨ�� 
	public:                                   // 2�������������  ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ����� 
		virtual void func()=0;
};

class son :public Base
{
	public:
		virtual void func()
		{
			cout<<"func��������"<<endl;
		}
};

void test01()
{
	//Base b;     //�������޷�ʵ��������
	//new Base;  //�������޷�ʵ��������
	//son a;   //���������д�����еĴ��麯���������޷�ʵ�������� 
	Base *base=new son;
	base->func(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
