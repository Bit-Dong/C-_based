#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
swap(container c1��container c2);
��������������Ԫ��
c1����1  c2����2
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
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	for(int i=10;i>0;i--)
	{
		v2.push_back(i);
	}
	cout<<"����ǰ��"<<endl;
	cout<<"v1:"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	cout<<"v2:"<<endl;
	for_each(v2.begin(),v2.end(),myprint());
	cout<<endl;
	cout<<"------------------------"<<endl;
	cout<<"������"<<endl;
	swap(v1,v2);
	cout<<"v1:"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	cout<<"v2:"<<endl;
	for_each(v2.begin(),v2.end(),myprint());
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
