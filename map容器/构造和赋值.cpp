#include<iostream>
#include<map>
#include<string>
using namespace std;

/*
��飺 
map������Ԫ�ض���pair
pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

���ʣ�
map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

�ŵ㣺
���Ը���keyֵ�����ҵ�valueֵ
 
map��multimap����
map���������������ظ�keyֵԪ��
multimap�������������ظ�keyֵԪ��

�ܽ�: map������Ԫ�ض��ǳɶԳ��֡���������ʱ��Ҫʹ�ö���

*/

void PrintMap(map<int,int> &m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"    key = "<<(*it).first<<"   value = "<<it->second;
	}
	cout<<endl;
}

void test01()
{
	//����map���� 
	map<int,int> m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));
	m1.insert(pair<int,int>(4,40));
	PrintMap(m1);
	
	map<int,int>m2(m1);    //�������� 
	PrintMap(m2);
	
	map<int,int>m3;        //��ֵ 
	m3=m2;
	PrintMap(m3); 
	 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
 
