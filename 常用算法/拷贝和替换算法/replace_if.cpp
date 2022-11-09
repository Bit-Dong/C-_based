#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
replace_if(iterator beg, iterator end��_pred��newvalue) ;
�������滻Ԫ�أ������������滻��ָ��Ԫ��
 beg��ʼ������    end����������     _predν��    newvalue�滻����Ԫ��
*/

class myprint
{
	public:
		int operator()(int val)
		{
			cout<<val<<" ";
		}
};

class Greater5
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
};

void test01()
{
	vector<int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	cout<<"�滻ǰ��"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	
	cout<<"�滻��"<<endl;
	replace_if(v1.begin(),v1.end(),Greater5(),500);
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
