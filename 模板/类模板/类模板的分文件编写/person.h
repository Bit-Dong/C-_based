#ifndef __PRESON_H_
#define __PRESON_H_

#include<iostream>
#include<string>
using namespace std;

//��ģ���г�Ա��������ʵ��
template<class T1,class T2>
class Person
{
	public:
		//��Ա������������
		Person(T1 name,T2 age);
		void showPerson();
	public:
		T1 Name;
		T2 Age; 
};

#endif
