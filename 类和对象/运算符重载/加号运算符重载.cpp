#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
		Person(){};  //Ĭ�Ϲ��� 
		Person(int a,int b)   //�вι��� ǰ��ͱ�����������һ��Ĭ�Ϲ��� 
		{
			A=a;
			B=b;
		}
		
		//��Ա����ʵ��+����������� 
		Person operator+(const Person &p)     //���� ��Person p3=p1.operator+(p2)    ���Լ�Ϊ p3=p1+p2; 
		{
			Person temp;
			temp.A=this->A+p.A;
			temp.B=this->B+p.B;
			return temp;
		}
		
		int A;
		int B;
}; 

//ȫ�ֺ���ʵ��+�����������     //���ʣ� Person p3=operator+(p1,p2)    ���Լ�Ϊ p3=p1+p2;
Person operator+( Person &p1,Person &p2)
{
	Person temp(0,0);
	temp.A=p1.A+p2.A;
	temp.B=p1.B+p2.B;
	return temp;
}

//��������� Ҳ���Է�����������
Person operator+( Person &p3,int val)
{
	Person tep;
	tep.A=p3.A+val;
	tep.B=p3.B+val;
	return tep;
} 

void test01()
{
	Person p1(10,10);
	Person p2(20,20);
	
	//��Ա������ʽ 
	Person p3=p1+p2;
	cout<<"A:"<<p3.A<<" B:"<<p3.B<<endl;
	
	//��������ط����������� 
	Person p4=p3+10;
	cout<<"A:"<<p4.A<<" B:"<<p4.B<<endl;
}

int main()
{
	
	test01();
	system("pause");
	return 0;
} 
