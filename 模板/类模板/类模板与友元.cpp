#include<iostream>
#include<string>
using namespace std;

//ȫ�ֺ�������ʵ��----ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ��---��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

template<class T1,class T2>
class Person;

//ȫ�ֺ�������ʵ�� 
template<class T1,class T2>
void PrintPerson2(Person<T1,T2> p)
{
	cout<<"����ʵ��-----������"<<p.Name<<"���䣺"<<p.Age<<endl;
}

template<class T1,class T2>
class Person
{
	//ȫ�ֺ�������ʵ�� 
	friend void PrintPerson(Person<T1,T2> p)
	{
		cout<<"������"<<p.Name<<"���䣺"<<p.Age<<endl;
	}

	//ȫ�ֺ�������ʵ�� 
	//�ӿ�ģ��<>�����б�
	//���ȫ�ֺ��� ������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ��� 
	friend void PrintPerson2<>(Person<T1,T2> p);
	
	public:
		Person(T1 name,T2 age)
		{
			this->Name=name;
			this->Age=age;
		}
		
	private:
		T1 Name;
		T2 Age; 
};


//ȫ�ֺ���������ʵ�� 
void test01()
{
	Person<string,int>p("Nie",20);
	PrintPerson(p);
}


void test02()
{
	Person<string,int>p("Dong",20);
	PrintPerson2(p);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
