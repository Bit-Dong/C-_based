#include<iostream>

using namespace std;

//�����������ķ���ֵ 
//1.��Ҫ���ؾֲ�����������
int & txt1()
{
	int a=10;   //�ֲ����������ջ��
	return a; 
 } 

//2.�����ĵ��ÿ�����Ϊ��ֵ
int & txt2()
{
	static int b=20;   //��̬�����������ȫ������ȫ�����ϵ������ڳ����������ϵͳ�ͷ�
	return b; 
 } 
int main()
{
	int &re1=txt1();           //re1Ϊa�ı��� 
	cout<<"re1="<<re1<<endl;   //��һ�ν����ȷ������Ϊ���������˱��� 
	cout<<"re1="<<re1<<endl;   //�ڶ��ν����������Ϊa���ڴ��Ѿ��ͷ� 
	
	int &re2=txt2();           //re2Ϊb�ı��� 
	cout<<"re2="<<re2<<endl;   
	cout<<"re2="<<re2<<endl;
	txt2()=1000;
	cout<<"re2="<<re2<<endl;   
	cout<<"re2="<<re2<<endl;
	
	system("pause");
}
