#include<iostream>
#include<string>            //ע����� 
                                   //���ñ����ʼ�� 
using namespace std;              //�����ڳ�ʼ���󣬲����Ըı� 

int main()
{
	int a=10;
	int &b=a;    //���ó�ʼ�� 
	int c=20;
	b=c;        //��ֵ���������Ǹ�����    
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
		
	system("pause");
}
