#include<iostream>
#include<string>
#include<deque>
using namespace std;


// at(int idx);    ��������idx��ָ������   
// operator[];     ��������idx��ָ������ 
// front();        ���������е�һ������Ԫ�� 
// back();         �������������һ������Ԫ�� 


//��deque���е����ݽ��д�ȡ����
void test01()
{
	deque<int> d1;
	
	d1.push_back(10); 
	d1.push_back(20); 
	d1.push_front(100); 
	d1.push_front(200); 
	
	//����[]��ʽ��������Ԫ��
	for(int i=0;i<d1.size();i++)
	{
		cout<<d1[i]<<" ";
	}
	cout<<endl;
	
	//����at��ʽ����Ԫ��
	for(int i=0;i<d1.size();i++)
	{
		cout<<d1.at(i)<<" ";
	} 
	cout<<endl;
	
	//��ȡ��һ��Ԫ��
	cout<<"��һ��Ԫ��Ϊ��"<<d1.front()<<endl;
	
	//��ȡ���һ��Ԫ��
	cout<<"���һ��Ԫ��Ϊ��"<<d1.back()<<endl; 

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
