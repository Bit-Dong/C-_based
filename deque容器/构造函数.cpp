#include<iostream>
#include<string>
#include<deque>
using namespace std;

//  �ܽ�: deque������vector�����Ĺ��췽ʽ����һ��,���ʹ�ü���

void PrintDeque(const deque<int> &d)       // ��const��Ϊֻ�� 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  ֻ�������� 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	deque<int> d;
	for(int i=9;i>=0;i--)
	{
		d.push_front(i);
	}
	PrintDeque(d);
	
	deque<int>d2(d.begin(),d.end());    //���丳ֵ 
	PrintDeque(d2);
	
	deque<int>d3(10,100);       //��ֵ 10��100 
	PrintDeque(d3);       
	
	deque<int>d4(d3);       //�������� 
	PrintDeque(d4);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
