#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
replace(iterator beg,iterator end��oldvalue��newvalue) ;
�������� ��Ԫ���滻����Ԫ��
 beg ��ʼ������   end����������    oldvalue ��Ԫ��     newalue��Ԫ��
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
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	cout<<"�滻ǰ��"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	
	cout<<"�滻��"<<endl;
	replace(v1.begin(),v1.end(),5,500);
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
