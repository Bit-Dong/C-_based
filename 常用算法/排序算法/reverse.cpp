#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
reverse(iterator beg, iterator end );
��תָ����Χ��Ԫ��
 beg ��ʼ������  end���������� 
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
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	cout<<"��תǰ��"<<endl;
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
	
	cout<<"��ת��"<<endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	
	system("pause");
	return 0;
}
