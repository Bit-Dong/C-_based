#include<iostream>
#include<string>
#include<list>
using namespace std;

void printList(const list<int> &l)
{
	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//list�����������ʹ�С����
void test01()
{
	list<int> l1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //�������ֵ 
	} 
	printList(l1);
	
	if(l1.empty())    //Ϊ�� ��������Ϊ��
	{
		cout<<"l1Ϊ��"<<endl;
	}
	else
	{
		cout<<"l1��Ϊ��"<<endl;
		cout<<"l1�Ĵ�СΪ��"<<l1.size()<<endl;
	}
	
//����ָ����С
	l1.resize(15,1);     //�������ذ汾������ָ��Ĭ�����ֵ  �����趨�Ĵ�С����Ϊ15�������Ĳ�����1��䣨���趨�Ļ���Ĭ����0��䣩 
	printList(l1);
	
	l1.resize(5);       //�趨�Ĵ�С����Ϊ5 
	printList(l1);   //�������ָ���ĳ��ȱ�ԭ�����ˣ��������ֻ�ɾ���� 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
