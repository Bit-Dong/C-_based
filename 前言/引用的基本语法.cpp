#include<iostream>
#include<string>
using namespace std;

int main()
{
	//���õĻ����﷨
	//��������  &���� = ԭ�� 
	int a=10;
	int &b=a;             //���ó�ʼ�� 
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	
    b=100;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;	 
	system("pause");
}
