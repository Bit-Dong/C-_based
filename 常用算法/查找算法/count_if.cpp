#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
count_if(iterator beg, iterator end��_pred) ;
 ������ͳ��Ԫ�س��ִ���
 beg ��ʼ������   end����������    _Predν��
*/

//������������
class GreaterFive
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
};

void test01()
{
	vector<int>v;
	v.push_back(7);
	v.push_back(1);
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(1);
	
	int num=count_if(v.begin(),v.end(),GreaterFive());
	cout<<"����5�ĸ���Ϊ��"<<num<<endl;
} 


//�Զ����������� 
class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		

	public:
		string Name;
		int Age;
};

class AgeGreater15
{
	public:
		bool operator()(const Person&p)
		{
			return p.Age>15;
		}
};

void test02()
{
	vector<Person> v;
	Person p1("����",10);
	Person p2("�ŷ�",20);
	Person p3("����",20);
	Person p4("����",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	int n=count_if(v.begin(),v.end(),AgeGreater15()); 
	cout<<"�������15�������Ϊ��"<<n<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
