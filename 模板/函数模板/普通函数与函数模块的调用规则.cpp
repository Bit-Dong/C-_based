#include<iostream>
#include<string>
using namespace std;

//��ͨ�����ͺ���ģ��ĵ��ù���
//  1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ���� 
//  2������ͨ����ģ������б��� ǿ�Ƶ��ú���ģ�� 
//  3������ģ��Ҳ���Է������� 
//  4���������ģ����Բ������õ�ƥ�� ���ȵ��ú���ģ�� 

                                           //�ܽ�:��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����

//��ͨ����
void myPrint(int a,int b)
{
	cout<<"���õ���ͨ����"<<endl;
} 

template<typename T>
void myPrint(T a,T b)
{
	cout<<"���õĺ���ģ��"<<endl;
}

template<typename T>
void myPrint(T a,T b,T c)
{
	cout<<"���õ����غ���ģ��"<<endl;
}


void test01()
{
	int a=10;
	int b=20;
	int c=30;
	char c1='a';
	char c2='b';
	myPrint(a,b);      //  1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	myPrint<>(a,b);    //  2������ͨ����ģ������б��� ǿ�Ƶ��ú���ģ�� 
	myPrint(a,b,c);    //  3������ģ��Ҳ���Է�������
	myPrint(c1,c2);    //  4���������ģ����Բ������õ�ƥ�� ���ȵ��ú���ģ�� 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
