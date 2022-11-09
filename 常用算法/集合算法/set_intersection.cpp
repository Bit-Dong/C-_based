#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
set_intersection(iterator beg1��iterator end1��iterator beg2��iterator end2��iterator dest);
 ���������ϵĽ���
 ע��:�������ϱ�������������  
 beg1����1��ʼ������    end1����1����������   beg2����2��ʼ������   end2����2����������    destĿ��������ʼ������
*/

class myprint
{
	public:
		int operator()(int val)
		{
			cout<<val<<" ";
		}
};


void test01()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget; 
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	for(int i=0;i<10;i++)
	{
		v2.push_back(i+5);
	}
	
	cout<<"v1:"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	cout<<"v2:"<<endl;
	for_each(v2.begin(),v2.end(),myprint());
	cout<<endl;
	
	cout<<"------------------------"<<endl;
	
	cout<<"ȡ������"<<endl;
	vTarget.resize(min(v1.size(),v2.size()));
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());    //����ȡ���������һ��Ԫ�صĵ����� 
	
	for_each(vTarget.begin(),itEnd,myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
