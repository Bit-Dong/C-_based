#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//vector�����д���Զ�����������
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

//��Ŷ��� 
void test01()
{
	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ�����
	vector<Person> v;
	
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	
	//�������з�����
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	//���������е����� 
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
//		cout<<"������"<<(*it).Name<<"  ���䣺"<<(*it).Age<<endl;     //�������ͬ 
		cout<<"������"<<it->Name<<"  ���䣺"<<it->Age<<endl;
	} 
}

void test02()
{
	vector<Person*> v;
	
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	
	//�������з�����
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);	
	
	//���������е����� 
	for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
	{
//		cout<<"������"<<(*it)->Name<<"  ���䣺"<<(*it)->Age<<endl;        //�������ͬ 
//		cout<<"������"<<(*(*it)).Name<<"  ���䣺"<<(*(*it)).Age<<endl;
		cout<<"������"<<(**it).Name<<"  ���䣺"<<(**it).Age<<endl;
	} 
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
}
	 
