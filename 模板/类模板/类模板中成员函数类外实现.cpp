#include<iostream>
#include<string>
using namespace std;

//��ģ���г�Ա��������ʵ��
template<class T1,class T2>
class Person
{
	public:
		//��Ա������������
		Person(T1 name,T2 age);
		void showPerson();
	public:
		T1 Name;
		T2 Age; 
};

//���캯�� ����ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
	this->Name=name;
	this->Age;
} 

//��Ա���� ����ʵ��
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
	cout<<"������"<<this->Name<<"���䣺"<<this->Age<<endl;
}

void test01()
{
	Person<string,int>p("Tom",20);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
