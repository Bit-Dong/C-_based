#include<iostream>
#include<string>
using namespace std;

class C1         
{
	string name;        //Ĭ��Ȩ��Ϊ˽��Ȩ�� 
};

struct C2
{
	string name;       //Ĭ��Ȩ��Ϊ����Ȩ�� 
};

int main()
{
	                    //         struct �� class����
						//                   structĬ��Ȩ���ǹ���Ȩ�� public
						//                   classĬ��Ȩ����˽��Ȩ�� private 
	
	
//	C1 s1;
//	s1.name="С��";           //�ᱨ����class�� Ĭ��Ȩ��Ϊ˽��Ȩ��  ������ⲻ���Է��� 
//	cout<<s1.name<<endl;    
	
	C2 s2;
	s2.name="����";    //���ᱨ�� ��struct�� Ĭ��Ȩ��Ϊ����Ȩ��  ���������Է��� 
	cout<<s2.name<<endl;
	
	system("pause");
} 
