#include<iostream>
#include<string>
#include<vector>
using namespace std;

//��vector�����������ʹ�С����

// empty();    �ж������Ƿ�Ϊ�� 
// capacity();  ���������� 
// size();    ����������Ԫ�صĸ��� 
// resize(int num);  ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
//                                            ��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ�� 
// resize(int num,elem);   ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
//                                                  ��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ�� 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector�����������ʹ�С����
void test01()
{
	vector<int> v1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //�������ֵ 
	} 
	printVector(v1);
	
	if(v1.empty())    //Ϊ�� ��������Ϊ��
	{
		cout<<"v1Ϊ��"<<endl;
	}
	else
	{
		cout<<"v1��Ϊ��"<<endl;
		cout<<"v1������Ϊ��"<<v1.capacity()<<endl;
		cout<<"v1�Ĵ�СΪ��"<<v1.size()<<endl;
	}
	
//����ָ����С
	v1.resize(15,100);     //�������ذ汾������ָ��Ĭ�����ֵ  �����趨�Ĵ�С����Ϊ15�������Ĳ�����100��䣨���趨�Ļ���Ĭ����0��䣩 
	printVector(v1);
	
	v1.resize(5);       //�趨�Ĵ�С����Ϊ5 
	printVector(v1);   //�������ָ���ĳ��ȱ�ԭ�����ˣ��������ֻ�ɾ���� 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
