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


//list ������ֵ
void test01()
{
	list<int> l1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //�������ֵ 
	} 
	printList(l1);
	
//��ֵ operator=
	list<int> l2;
	l2=l1; 
	printList(l2);
	
//assign
	list<int> l3;
	l3.assign(l1.begin(),l1.end());    //����assign���䷽ʽ(����ҿ�)  ��l1��ֵ��l3    
	printList(l3);
	
//n��elem��ʽ��ֵ
	list<int> l4;
	l4.assign(10,100);        //10��100��ֵ��l4 
	printList(l4); 
} 

//���� 
void test02()
{
	list<int> l1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //�������ֵ 
	} 
	
	list<int> l2;
	l2.assign(10,100);        //10��100��ֵ��l4 
	cout<<"����ǰ��"<<endl;
	printList(l1); 
	printList(l2); 
	
	l1.swap(l2);
	cout<<"������"<<endl;
	printList(l1); 
	printList(l2); 
		
}

int main()
{
//	test01();
	test02();
	 
	system("pause");
	return 0;
} 
