#include<iostream>
#include<string>
using namespace std;

/*
��������ʹ���ص㣺
1������������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
2���������󳬳���ͨ���������������������Լ���״̬
3���������������Ϊ�������� 
*/

//1������������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
class MyAdd
{
	public:
		int operator()(int v1,int v2)
		{
			return v1+v2;
		}
};
void test01()
{
	MyAdd myadd;
	cout<<myadd(10,10)<<endl<<endl;
}

//2���������󳬳���ͨ���������������������Լ���״̬
class MyPrint
{
	public:
		MyPrint()
		{
			count=0;
		}
		void operator()(string test)
		{
			cout<<test<<endl;
			count++;    //ͳ��ʹ�ô��� 
		}
		int count;    //�ڲ��Լ���״̬ 
};
void test02()
{
	MyPrint myprint;
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");	
	cout<<"myprintʹ�ô���Ϊ��"<<myprint.count<<endl<<endl;
} 

//3���������������Ϊ�������� 
void doprint(MyPrint &p,string test)
{
	p(test);
}
void test03()
{
	MyPrint myprint;
	doprint(myprint,"Bit Dongge!");
}

int main()
{
	test01();
	test02();
	test03();
	
	system("pause");
	return 0;
}
