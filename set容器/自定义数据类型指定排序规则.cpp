#include<iostream>
#include<string>
#include<set>
using namespace std;

class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		string Name;
		int Age;
};

class ComparePerson
{
	public:
		bool operator()(const Person &p1,const Person &p2)
		{
			//���������������  ����
			return p1.Age>p2.Age; 
		}
};

void test01()
{
	//�Զ����������� ����ָ���������
	set<Person,ComparePerson> s;
	
	//����Person����
	Person p1("����",54);
	Person p2("�ܳ�",58);
	Person p3("�Է�",50);
	Person p4("���",46);
	
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	
	for(set<Person,ComparePerson>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<"������"<<it->Name<<"   ���䣺"<<it->Age<<endl;
	}
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
