#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
/*
merge(iterator beg1��iterator end1�� iterator beg2��iterator end2��iterator dest);
����Ԫ�غϲ������洢����һ������
ע��:�������������������,�ϲ���Ҳ������� 
 beg1����1��ʼ������    end1����1����������   beg2����2��ʼ������    end2����2����������    destĿ��������ʼ������
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
		v2.push_back(i+5);
	}
	vector<int>v3;
	v3.resize(v1.size()+v2.size());   //����Ŀ�������ռ� 
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());    //�ϲ������������� 
	for_each(v3.begin(),v3.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
