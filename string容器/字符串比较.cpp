#include<iostream>
#include<string>
using namespace std;

//string �ַ����Ƚ�
/*
���������� �ַ���֮��ıȽ�
�ȽϷ�ʽ�� �ַ����Ƚ��ǰ��ַ�����ASCII����бȽ� 
           = ���� 0
		   > ���� 1
		   < ����-1 
����ԭ�ͣ�
        int compare(const string &s) const;   //���ַ���s�Ƚ� 
        int compare(const char *s) const;     //���ַ���s�Ƚ�
*/ 

void test01()
{
	string s1="a";         // a --- 97   b=98....
	string s2="A";         // A --- 65   B=66....
	
	int ret=s1.compare(s2);
	if(ret==0)       cout<<"s1 = s2"<<endl;
	else if(ret>0)   cout<<"s1 > s2"<<endl;
	else             cout<<"s1 < s2"<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
