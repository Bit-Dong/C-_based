#include<iostream>
#include<string>
#include<set>
using namespace std;

//set�����Բ����ظ����ݣ���multiset����
//set�������ݵ�ͬʱ�᷵�ز���������ʾ����ɹ�
//multiset���������ݣ���˿��Բ����ظ����� 

void printSet(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
}

void test01()
{
	set<int>s;
	pair<set<int>::iterator,bool> ret=s.insert(10);
	if(ret.second)
	{
		cout<<"��һ�β���ɹ���"<<endl;
	} 
	else
		cout<<"��һ�β���ʧ�ܣ�"<<endl;
	
	ret=s.insert(10);
	if(ret.second)
	{
		cout<<"�ڶ��β���ɹ���"<<endl;
	} 
	else
		cout<<"�ڶ��β���ʧ�ܣ�"<<endl;
	
	//multset
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
	{
		cout<<*it<<" "; 
	}
	cout<<endl; 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
