#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
adjacent_find(iterator beg, iterator end) ;
���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
beg��ʼ������   end����������
*/
 
void test01()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(0);
	v.push_back(6);
	v.push_back(6);

	vector<int>::iterator it=adjacent_find(v.begin(),v.end());
	if(it==v.end())
		cout<<"û���ҵ���"<<endl;
	else
		cout<<"�ҵ������ظ�Ԫ��Ϊ�� "<<*it<<endl;  
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
