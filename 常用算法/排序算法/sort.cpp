#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

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
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	//sortĬ�ϴ�С��������
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
	
	//�Ӵ�С����
	sort(v.begin(),v.end(),greater<int>());        //functional  α���� 
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
