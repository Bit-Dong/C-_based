#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

class TransForm
{
	public:
		int operator()(int val)
		{
			return 100+val;
		} 
}; 

class print
{
	public:
		void operator()(int val)
		{
			cout<<val<<"  ";
		}
};

void test01()
{
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	
	vector<int>vTarget;  //Ŀ������
	vTarget.resize((v.size()));    //Ŀ��������Ҫ��ǰ�����ٿռ�
	transform(v.begin(),v.end(),vTarget.begin(),TransForm()); 
	for_each(vTarget.begin(),vTarget.end(),print());  
	cout<<endl;   
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
