#include<iostream>
#include<string>
using namespace std;

#include"person.cpp "    //��һ�ֽ��������ֱ�Ӱ���.cpp�ļ�
//#include<person.hpp>   //�ڶ��ֽ����������.cpp��.h�ļ�д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp   .hpp��Լ�������ƣ�������ǿ�� 

void test01()
{
	Person<string,int>p("Niedong",20);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
