#include<iostream>
#include<functional>
#include<vector>
#include<functional> 
#include<algorithm>
using namespace std;

/*
ʵ�ֹ�ϵ�Ա� 

template<class T> bool logical_and<T>           //�߼��� 
template<class T> bool logical_or<T>            //�߼���
template<class T> bool logical_not<T>           //�߼��� 
*/ 

void test01()
{
	vector<bool> v;
	
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	
	for(vector<bool>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	
	//�߼���  ��v�������˵�v2�У���ִ���߼�������
	vector<bool> v2;
	v2.resize(v.size());   //������vһ����С�Ŀռ� 
	transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());  //���˲���  ��[v.begin(),v.end()]���˵� ��v2.begin()��ʼ�ĵط�    logical_not:����������ȡ�� 
	for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
