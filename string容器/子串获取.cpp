#include<iostream>
#include<string>
using namespace std;

//   ���ַ����л�ȡ��Ҫ���Ӵ� 
//   string substr(int pos=0,int n=npos) const    //������pos��ʼ��n���ַ���ɵ��ַ��� 

//��ȡ�ִ� 
void test01()
{
	string str="abcdefg";
	string subStr=str.substr(1,3);       //��ȡ��str�ĵ�1-3���ַ� 
	cout<<"subStr = "<<subStr<<endl;
} 

//ʵ�ò��������ʼ���ַ�� ��ȡ �û�����Ϣ 
void test02()
{
	string email="Niedong@qq.com";
	int pos=email.find("@");     //��ȡ���ַ�'@' ��λ��   8
	cout<<"pos = "<<pos<<endl;     //���λ����Ϣ
	
	string userName=email.substr(0,pos);
	cout<<userName<<endl; 
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
