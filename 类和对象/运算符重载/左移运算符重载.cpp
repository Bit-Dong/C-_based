#include<iostream>
#include<string>
using namespace std;

class Person
{
	friend ostream & operator<<(ostream &out,Person &p);   //ȫ�ֺ�������Ԫ�����Է���˽��Ȩ�� 
	public:
		Person(int a,int b)   //�вι��� 
		{
			A=a;
			B=b;	
		}
		
//    ���ó�Ա�����������������p.operator<<(cout) �򻯰汾p<<cout
//    �������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
//    void operator<<( cout )
//   {
//   }	
		
	private:
		int A;
		int B;
};

//ֻ������ȫ�ֺ����������������
ostream & operator<<(ostream &out,Person &p)   //���ʣ�operator<<(out,p)   �򻯣�out<<p  
{
	out<<"A="<<p.A<<"  B="<<p.B;
	return out;
}

void test01()
{
	Person p(10,10);
	cout<<p<<"  Hello World!"<<endl;
}

int main()
{ 
	
	test01();
	system("pause");
	return 0; 
}
