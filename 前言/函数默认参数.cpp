#include<iostream>
#include<string>

using namespace std;

//��������Լ��������ݣ������Լ������ݣ����û�У���ô��Ĭ��ֵ 
//�﷨�� ����ֵ���� ������ ���β� = Ĭ��ֵ��
int func(int a,int b=10,int c=20)
{
	return a+b+c;
}
 
//ע������
//1�� ���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�������Ĭ��ֵ 

//2�� �������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//    ������ʵ��ֻ����һ����Ĭ�ϲ��� 
int func2(int a,int b);   //���� 

int func2(int a=11,int b=22)   //ʵ�� 
{
	return a+b;
}

int main()
{
	//cout<<func(10)<<endl; 
    //cout<<func(10,10,100);
	cout<<func2()<<endl;
	 
	system("pause");
}
