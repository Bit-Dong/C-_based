#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
bool binary_search(iterator beg, iterator end,value);
����ָ����Ԫ�أ��鵽����true ����false
ע��:�����������в�����
beg ��ʼ������    end����������     value���ҵ�Ԫ��
*/

void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	//  v.push_back(2);  ���ʱ�������У��ṹδ֪��
	//  ע�⣺������������������� 
	//  �����������Ƿ��� 9 ���Ԫ��
	bool ret=binary_search(v.begin(),v.end(),9);
	
	if(ret)
		cout<<"�鵽�ˣ�"<<endl;
	else
		cout<<"û�鵽��"<<endl; 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
