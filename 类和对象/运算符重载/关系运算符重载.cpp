#include<iostream>
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
		
	bool operator==(Person &p)
	{
		if(this->Name==p.Name&&this->Age==p.Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
			
	bool operator!=(Person &p)
	{
		if(this->Name==p.Name&&this->Age==p.Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	string Name;
	int Age;
	
}; 

void test01()
{
	Person a("��˽�",20);
	Person b("������",20);
	
	if(a==b)  cout<<"a��b���"<<endl;
	else      cout<<"a��b�����"<<endl;
	
	if(a!=b)  cout<<"a��b�����"<<endl;
	else      cout<<"a��b���"<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
