#include<iostream>
#include<string>
using namespace std;


//�ܽ᣺
//    1��find�����Ǵ������ң�rfind�������� 
//    2��fend�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1 
//    3��replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ��� 

//���ң�����ָ���ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���

/*
int find(const string &str,int pos=0)const;       ����str��һ�γ���λ�ã���pos��ʼ���� 
int find(const char *s,int pos=0)const;           ����s��һ�γ���λ�ã���pos��ʼ���� 
int find(const char *s,int pos, int n)const;      ��posλ�ò���s��ǰn���ַ���һ��λ�� 
int find(const char c,int pos=0)const;             �����ַ�c��һ�γ���λ�� 
int rfind(const  string &str,int pos=npos)const;   ����str���һ��λ�ã���pos��ʼ���� 
int rfind(const char *s,int pos=npos)const;        ����s���һ�γ���λ�ã���pos��ʼ���� 
int find(const char *s,int pos,int n)const;        ��pos����s��ǰn���ַ����һ��λ�� 
int find(const char c,int pos=0)const;             �����ַ�c���һ�� ����λ�� 
string & replace(int pos,int n,const string& str);  �滻��pos��ʼn���ַ�Ϊ�ַ���str 
string & replace(int pos,int n,const char *s);      �滻��pos��ʼ��n���ַ�Ϊ�ַ���s 
*/ 

//�滻�Ͳ��� 
void test01()
{
	//����
	string str ="abcdefg";
	int pos=str.find("f");
	if(pos==-1)
	{
		cout<<"δ�ҵ�"<<endl;
	}
	else
	{
		cout<<"pos = "<<pos<<endl;
	}
	
	pos=str.rfind("de");
	cout<<"pos = "<<pos<<endl;
}
	
void test02()
{
	//�滻
	string str1="abcdefg";
	str1.replace(1,3,"11");    
	cout<<"str1 = "<<str1<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
