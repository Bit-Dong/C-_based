#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		Base()
		{
			A=100;
		}
		
		void func()
		{
			cout<<"Base - func()����"<<endl;
		}
		
		void func(int a)
		{
			cout<<"Base - func(int a)����"<<endl;
		}
		
	public:
		int A;
};

class son : public Base
{
	public:
		son()
		{
			A=200;
		}
		
//      �������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա���� 
//      �������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
		
		void func()
		{
			cout<<" son - func()����"<<endl;
		} 
	public:
		int A;
};

void test01()
{
	son s;
	
	cout<<" son�µ� A = "<<s.A<<endl;
	cout<<"Base�µ� A = "<<s.Base::A<<endl;
	
	s.func();
	s.Base::func();
	s.Base::func(10);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
