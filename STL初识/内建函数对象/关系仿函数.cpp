#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

/*
ʵ�ֹ�ϵ�Ա� 

template<class T> bool equal_to<T>            //���� 
template<class T> bool not_equal_to<T>        //������ 
template<class T> bool greater<T>             //����  
template<class T> bool greater_equal<T>       //���ڵ���  
template<class T> bool less<T>                //С��  
template<class T> bool less_equal<T>          //С�ڵ���  
*/ 

void test01()
{
	vector<int> v;
	
	v.push_back(5);
	v.push_back(9);
	v.push_back(4);
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	
	cout<<"ԭʼ����"<<endl;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;

	cout<<"sortĬ������(����)��"<<endl; 
	sort(v.begin(),v.end());
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;

	cout<<"����"<<endl; 
	sort(v.begin(),v.end(),greater<int>());         //STL�ڽ��º���  ���ڷº��� 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
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
