#include<iostream>
#include<string>
#include<deque>
#include<algorithm> 
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

	d1.push_back(10); 
	d1.push_back(20); 
	d1.push_front(100); 
	d1.push_front(200);      
// 200 100 10 20
	cout<<"����ǰ��"<<endl;
	PrintDeque(d1);
	
	//����  Ĭ��������� ��С���� ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort��������
	sort(d1.begin(),d1.end()); 
	cout<<"�����"<<endl;
	PrintDeque(d1);  
	

}


int main()
{
	test01();
	
	system("pause");
	return 0;
}
