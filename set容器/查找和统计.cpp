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

//���� 
void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	 
	set<int>::iterator pos=s1.find(4);        //���ڷ��ظ�Ԫ�صĵ������������ڷ���set.end() 
	if(pos!=s1.end())
	{
		cout<<"�ҵ�Ԫ�أ�"<<*pos<<endl;
	}
	else
	{
		cout<<"δ�ҵ���Ԫ�أ�"<<endl;
	}
}

//ͳ��
void test02()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	int num=s1.count(5);      //���ظ����� set�����ۼӣ�setֻ�᷵��0��1 
	cout<<"num = "<<num<<endl;
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
