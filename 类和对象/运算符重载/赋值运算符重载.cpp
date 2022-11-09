#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
		Person(int age)
		{
			Age=new int(age);   //���������ݿ��ٵ����� 
		}
		
	//���ظ�ֵ�����
	Person &operator=(Person &p)
	{
		if(Age!=NULL)
		{
			delete Age;
			Age=NULL;
		}
		//�������ṩ�Ĵ�����ǳ���� 
		//Age=p.Age; 
		
		//�ṩ��� ���ǳ����������
		Age=new int(*p.Age);
		
		//��������
		return *this; 
	} 
	
	~Person()
	{
		if(Age!=NULL)
		{
			delete Age;
			Age=NULL;
		}
	}
		
	int *Age;
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3=p2=p1;
	cout<<"p1������Ϊ��"<<*p1.Age<<endl;
	cout<<"p2������Ϊ��"<<*p2.Age<<endl;
	cout<<"p3������Ϊ��"<<*p3.Age<<endl;
}


int main()
{
	test01();
	
	system("pause");
	return 0;
}
