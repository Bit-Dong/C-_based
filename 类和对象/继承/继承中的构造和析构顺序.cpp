#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout<<"Base�Ĺ��캯��!"<<endl;
		}
		~Base()
		{
			cout<<"Base����������!"<<endl;
		}
};

class son :public Base
{
	public:
		son()
		{
			cout<<"son�Ĺ��캯��!"<<endl;
		}
		~son()
		{
			cout<<"son����������!"<<endl;
		}	
};

void test01()
{
	son s1;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
