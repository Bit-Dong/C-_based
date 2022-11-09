#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
count(iterator beg, iterator end, value ) ;
ͳ��Ԫ�س��ִ���
beg��ʼ������   end����������   valueͳ�Ƶ�Ԫ��
*/

//������������
void test01()
{
	vector<int>v;
	v.push_back(7);
	v.push_back(1);
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(1);
	
	int num=count(v.begin(),v.end(),1);
	cout<<"1�ĸ���Ϊ��"<<num<<endl;
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
		
		// ����==
		bool operator==(const Person &p)
		{
			if(this->Age==p.Age)
				return true;
			else
				return false;
		} 
	public:
		string Name;
		int Age;
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
	Person p("�����",40);
	
	int n=count(v.begin(),v.end(),p2); 
	cout<<"���������ͬ������������"<<n<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
