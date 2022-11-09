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

void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	printSet(s1);
	
	//ɾ��
	s1.erase(s1.begin());       //ɾ����ͷλ����
	printSet(s1);
	
	s1.erase(5);    //ɾ����5��ͬ����
	printSet(s1);
	
	s1.erase(s1.begin(),s1.end());    //ȫɾ 
	s1.clear();    //��� 
	printSet(s1); 
	
}

int main()
{
	test01();

	system("pause");
	return 0;
}
