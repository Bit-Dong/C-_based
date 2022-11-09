#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

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
			if(this->Name==p.Name&&this->Age==p.Age)
				return true;
			else
				return false;
		} 
	public:
		string Name;
		int Age;
};

//�����������Ͳ��� 
void test01()
{
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	
	//�����������Ƿ��� 5 ���Ԫ��
	vector<int>::iterator it=find(v.begin(),v.end(),50);
	if(it==v.end())
		cout<<"û���ҵ���"<<endl;
	else
		cout<<"�ҵ�Ԫ�أ�"<<*it<<endl;  
}

//�Զ����������Ͳ��� 
void test02()
{
	vector<Person> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person p10("bbb",20);
	vector<Person>::iterator it=find(v.begin(),v.end(),p10);
	if(it==v.end())
		cout<<"û���ҵ���"<<endl;
	else
		cout<<"�ҵ�Ԫ�� "<<"  ������"<<it->Name<<"    ���䣺"<<it->Age<<endl;  
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
