#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
find_if(iterator beg,iterator end��_Pred) ;
��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
 beg ��ʼ������   end����������    _Pred ��������ν��(����bool���͵ķº���)
*/

//������������
class GreatFive
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
}; 
void test01()
{
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	
	//���������д��� 5 ��Ԫ��
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreatFive());
	if(it==v.end())
		cout<<"û���ҵ���"<<endl;
	else
		cout<<"�ҵ�����5��Ԫ�أ�"<<*it<<endl;
}



//�Զ����������Ͳ��� 
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

class Greater20
{
	public:
		bool operator()(Person &p)
		{
			return p.Age>30;
		}
}; 

 
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
	
	vector<Person>::iterator it=find_if(v.begin(),v.end(),Greater20());
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
