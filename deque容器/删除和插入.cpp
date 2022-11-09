#include<iostream>
#include<string>
#include<deque>
using namespace std;

void PrintDeque(const deque<int> &d)       // ��const��Ϊֻ�� 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  ֻ�������� 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	deque<int> d1;

//������� 
	//β��
	d1.push_back(10); 
	d1.push_back(20); 
	//ͷ��
	d1.push_front(100); 
	d1.push_front(200);      
	
	// 200 100 10 20
	PrintDeque(d1);
	
//ɾ������
	//βɾ
	d1.pop_back();
	// 200 100 10
	PrintDeque(d1);
	//ͷɾ
	d1.pop_front();
	//100 10
	PrintDeque(d1);	
	
//insert����
	d1.insert(d1.begin(),1000);    //��ͷ������1000 
	// 1000 100 10
	PrintDeque(d1);
	
	d1.insert(d1.begin(),2,10000);    //��ͷ����������10000 
	// 10000 10000 1000 100 10
	PrintDeque(d1); 
	
//����������в���
	deque<int> d2;
	d2.push_back(1); 
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(),d2.begin(),d2.end());    //��d1��ͷ������ ����[d2.begin(),d2.end()] 
	// 1 2 3 10000 10000 1000 100 10
	PrintDeque(d1); 
}

//ɾ������ 
void test02()
{
	deque<int> d1;
	
	d1.push_back(10); 
	d1.push_back(20); 
	d1.push_front(100); 
	d1.push_front(200);  
	
//ɾ��
	deque<int> ::iterator it=d1.begin();
	it++;   //��itָ��ڶ�����
	d1.erase(it);   //ɾ��itָ��������
	//  200 10 20
	PrintDeque(d1);
//�����䷽ʽɾ��
	d1.erase(d1.begin(),d1.end());    //ɾ��d1��ȫ������
	
//���
	d1.clear();
	PrintDeque(d1); 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
