#include<iostream>
#include<string>
#include<queue>
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

void test01()
{
	//��������
	queue<Person> p;     
	
	//׼������
	Person p1("������",40);
	Person p2("�����",70);
	Person p3("��˽�",60);
	Person p4("ɳʦ��",50);
	
	//��� 
	p.push(p1);
	p.push(p2);
	p.push(p3);
	p.push(p4); 
	
	cout<<"����ǰ ���д�С��"<<p.size()<<endl;
	
	//�ж϶����Ƿ�Ϊ�գ���Ϊ�� ȡ��ͷ�Ͷ�β������
	cout<<"�𲽳��ӣ�"<<endl; 
	while(!p.empty()) 
	{
		cout<<endl<<"��ͷԪ�� --- ����Ϊ��"<<p.front().Name<<"   ��ͷԪ�� --- ����Ϊ��"<<p.front().Age<<endl;
		cout<<"��βԪ�� --- ����Ϊ��"<<p.back().Name<<"   ��βԪ�� --- ����Ϊ��"<<p.back().Age<<endl;
		
		//����
		p.pop(); 
	}
	cout<<"������ɣ�"<<endl<<endl;
	cout<<"���Ӻ� ���д�С��"<<p.size()<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
