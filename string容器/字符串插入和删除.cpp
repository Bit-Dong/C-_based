#include<iostream>
#include<string>
using namespace std;
//         插入和删除的起始下标都是从0开始 
//  对string字符串进行插入和删除字符操作
/*
	string &insert(int pos,const char *s);           //插入字符串 
	string &insert(int pos,const string &str);       //插入字符串 
	string &insert(int pos,int n,char c);            //在指定位置插入n个字符c 
	string &erase(int pos,int n=npos);               //删除从pos开始的n个字符 
*/ 

void test01()
{
	string str="hello";
	
	//插入
	str.insert(1,"111");     // h111ello
	cout<<"str = "<<str<<endl;
	
	 //删除
	 str.erase(1,3);       //删除第1-3个字符 
	 cout<<"str = "<<str<<endl; 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
