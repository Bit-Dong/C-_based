#include<iostream>
#include<string>
using namespace std;

//  ��ģ��ͺ���ģ�������
//   1����ģ��û���Զ������Ƶ�ʹ�÷�ʽ
//   2����ģ����ģ������б��п�����Ĭ�ϲ���

template<class NameType=string,class AgeType=int>   //��ģ����ģ������б��п�����Ĭ�ϲ���
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->Name=name;
		this->Age=age;
	}
	void showPerson()
	{
		cout<<"name:"<<this->Name<<"   age:"<<this->Age<<endl;
	}
	
public:
	NameType Name;
	AgeType Age;			
};

//  1����ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test01()
{
//	Person P1("�����",999);    ���� �޷����Զ������Ƶ� 
	
	Person<string,int> P1("�����",999);  //��ȷ��ֻ������ʾָ������    ָ��NameType Ϊstring���ͣ�AgeTypeΪint����
	
	P1.showPerson(); 
}

//��ģ����ģ������б��п�����Ĭ�ϲ���
void test02()
{
	Person<> p("��˽�",998);
	p.showPerson(); 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
