#include<iostream>
#include<string>
using namespace std;

void test01()
{
	pair<string,int> p("Tom",20);
	cout<<"������"<<p.first <<"     ���䣺"<<p.second<<endl;
	
	pair<string,int> p2=make_pair("Jerry",10);
	cout<<"������"<<p2.first<<"   ���䣺"<<p2.second<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
