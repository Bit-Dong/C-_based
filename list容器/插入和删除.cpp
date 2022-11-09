#include<iostream>
#include<string>
#include<list>
using namespace std;

void PrintList(const list<int> &d)       // ��const��Ϊֻ�� 
{
	for(list<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  ֻ�������� 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	list<int> l1;

//������� 
	//β��
	l1.push_back(10); 
	l1.push_back(20); 
	//ͷ��
	l1.push_front(100); 
	l1.push_front(200);      
	
	// 200 100 10 20
	PrintList(l1);
	
//ɾ������
	//βɾ
	l1.pop_back();
	// 200 100 10
	PrintList(l1);
	//ͷɾ
	l1.pop_front();
	//100 10
	PrintList(l1);	
	
//insert����
	l1.insert(l1.begin(),1000);    //��ͷ������1000 
	// 1000 100 10
	PrintList(l1);
	
	l1.insert(l1.begin(),2,10000);    //��ͷ����������10000 
	// 10000 10000 1000 100 10
	PrintList(l1); 
	
//����������в���
	list<int> l2;
	l2.push_back(1); 
	l2.push_back(2);
	l2.push_back(3);
	l1.insert(l1.begin(),l2.begin(),l2.end());    //��l1��ͷ������ ����[l2.begin(),l2.end()] 
	// 1 2 3 10000 10000 1000 100 10
	PrintList(l1); 
}

//ɾ������ 
void test02()
{
	list<int> l1;
	
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_front(100); 
	l1.push_front(200);  
	
//ɾ��
	list<int> ::iterator it=l1.begin();
	it++;   //��itָ��ڶ�����
	l1.erase(it);   //ɾ��itָ��������
	//  200 10 20
	PrintList(l1);
	l1.remove(200);    //ɾ����200��ͬ���� 
//�����䷽ʽɾ��
//	l1.erase(l1.begin(),l1.end());    //ɾ��l1��ȫ������
	
//���
//	l1.clear();
	PrintList(l1); 
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
}
