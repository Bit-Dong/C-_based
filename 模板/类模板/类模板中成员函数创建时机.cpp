#include<iostream>
#include<string>
using namespace std;

//��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ� 
//   1����ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ��� 
//   2����ģ���еĳ�Ա�����ڵ���ʱ�Ŵ��� 

class Person1
{
public:
	void showPerson1()
	{
		cout<<"Person1 show"<<endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout<<"Person2 show"<<endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�������������
	
	void fun1()
	{
		obj.showPerson1();
	} 
	void fun2()
	{
		obj.showPerson2();
	} 
};

void test01()
{
	MyClass<Person1> m;
	m.fun1();
//	m.fun2();    ��������,˵���������òŻ�ȥ������Ա����
}

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
