#include<iostream>
#include<map>
#include<string>
using namespace std;
 
void test01()
{
	map<int,int>m;

	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	
	map<int,int>::iterator pos=m.find(3);
	if(pos!=m.end())
	{
		cout<<"�鵽Ԫ�� key = "<< (*pos).first<<"    value = "<< (*pos).second<<endl;
	} 
	else
	{
		cout<<"δ�ҵ�Ԫ�أ�"<<endl;
	}

	//ͳ��
	//map����������ظ�keyԪ�أ�countͳ�ƶ��� ���Ҫô��0Ҫô��1 
	int num=m.count(3);
	cout<<"num = "<<num<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
