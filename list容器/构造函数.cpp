#include<iostream>
#include<string>
#include<list>
using namespace std;

void printList(const list<int> &l)
{
	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//list ��������
void test01()
{
	list<int> l1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //�������ֵ 
	} 
	printList(l1);
	
//ͨ�����䷽ʽ���й���
	list<int> l2(l1.begin(),l1.end());     //��l1��ֵ����l2 
	printList(l2);
	
//n��elem��ʽ����
	list<int> l3(10,100);        //��10��Ϊ100����ֵ ����l3
	printList(l3);
	
//��������
	list<int> l4(l3);          //��l3��ֵ������l4 
	printList(l4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
