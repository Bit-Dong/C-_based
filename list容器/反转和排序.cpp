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

bool myCompare(int val1,int val2)
{
	return val1>val2;
}

//��ת������
void test01()
{
	list<int> l;
	l.push_back(5); 
	l.push_back(8); 
	l.push_back(3); 
	l.push_back(6); 
	cout<<"����ǰ��";
	printList(l);
	
	//��ת
	l.reverse();
	cout<<endl<<"��ת��";
	printList(l);
	
	//����
	l.sort();     //Ĭ�Ϲ������� ��С����
	cout<<endl<<"��С��������";
	printList(l);
	
	l.sort(myCompare);   //ָ������ �Ӵ�С
	cout<<endl<<"�Ӵ�С����";
	printList(l); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
