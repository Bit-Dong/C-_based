#include<iostream>
#include<string>
#include<set>
using namespace std;

void printSet(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
}

//��С 
void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	printSet(s1);
	
  	if(s1.empty())
	{
	 	cout<<"s1Ϊ�գ�"<<endl;	
	}
	else
	{
		cout<<"s1��Ϊ�գ�"<<endl;
		cout<<"s1�Ĵ�СΪ��"<<s1.size()<<endl;
	}
}

//����
void test02() 
{
	set<int>s1;
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5);
	
	set<int>s2;
	s2.insert(10); 
	s2.insert(20); 
	s2.insert(30); 
	s2.insert(40); 
	s2.insert(50);
	
	cout<<"����ǰ��"<<endl;
	printSet(s1);
	printSet(s2);
	
	s1.swap(s2);
	cout<<"������"<<endl;
	printSet(s1);
	printSet(s2);
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
