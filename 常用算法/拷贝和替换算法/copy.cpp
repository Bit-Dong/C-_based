#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
������ָ����Χ��Ԫ�ؿ�������һ������
copy(iterator beg, iterator end�� iterator dest);
��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
 beg��ʼ������    end ����������   destĿ����ʼ������
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
	cout<<"v1��"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	
	cout<<"v2��"<<endl;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());
	for_each(v2.begin(),v2.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
