#include<iostream>
#include<string>
#include<deque>
using namespace std;

//��deque�����Ĵ�С���� (deque����û����������)

// empty();    �ж������Ƿ�Ϊ�� 
// capacity();  ���������� 
// size();    ����������Ԫ�صĸ��� 
// resize(int num);  ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
//                                            ��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ�� 
// resize(int num,elem);   ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
//                                                  ��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ�� 

void printDeque(const deque<int> &d)       // ��const��Ϊֻ�� 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  ֻ�������� 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//deque�����������ʹ�С����
void test01()
{
	deque<int> d1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);           //�������ֵ 
	} 
	printDeque(d1);
	
	if(d1.empty())    //Ϊ�� ��������Ϊ��
	{
		cout<<"d1Ϊ��"<<endl;
	}
	else
	{
		cout<<"d1��Ϊ��"<<endl;
		cout<<"d1�Ĵ�СΪ��"<<d1.size()<<endl;
	}
	
//����ָ����С
	d1.resize(15,1);     //�������ذ汾������ָ��Ĭ�����ֵ  �����趨�Ĵ�С����Ϊ15�������Ĳ�����1��䣨���趨�Ļ���Ĭ����0��䣩 
	printDeque(d1);
	
	d1.resize(5);       //�趨�Ĵ�С����Ϊ5 
	printDeque(d1);   //�������ָ���ĳ��ȱ�ԭ�����ˣ��������ֻ�ɾ���� 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
