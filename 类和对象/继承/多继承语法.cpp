#include<iostream>
#include<string>
using namespace std;


class Base1
{
	public:
		Base1()
		{
			A=100;
		}
	public:
		int A;
};

class Base2
{
	public:
		Base2()
		{
			A=200;
		}
	public:
		int A;
};

//�﷨��  class ���ࣺ �̳з�ʽ ����1���̳з�ʽ ����2
class son : public Base2,public Base1
{
	public:
		son()
		{
			C=300;
			D=400;
		}
	public:
		int C;
		int D;
};

//��̳����ײ�����Աͬ�������
//ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
void test01()
{
	son s;
	cout<<"sizeof son = "<<sizeof(s)<<endl;
	cout<<s.Base1::A<<endl;
	cout<<s.Base2::A<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
