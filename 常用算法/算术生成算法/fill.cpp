#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
#include<numeric>
using namespace std;

/*
fill(iterator beg, iterator end, value) ;
 �����������Ԫ��
 beg��ʼ������   end����������   value����ֵ
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
	vector<int>v;
	
	for(int i=0;i<=5;i++)
	{
		v.push_back(i);
	} 
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl<<"��СΪ��"<<v.size()<<endl;
	v.resize(8);
	fill(v.begin(),v.end(),66);         // [v.begin(),v.end()]�������  �Ḳ�������ڵ�����ֵ 
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl<<"��СΪ��"<<v.size()<<endl;;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
