#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
#include<numeric>
using namespace std;

/*
accumulate(iterator beg, iterator end, value) ;
��������Ԫ���ۼ��ܺ�
beg ��ʼ������    end����������    value ��ʼֵ
*/

void test01()
{
	vector<int>v;
	for(int i=0;i<=100;i++)
	{
		v.push_back(i);
	}
	
	int S=accumulate(v.begin(),v.end(),0);
	cout<<"S = "<<S<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
