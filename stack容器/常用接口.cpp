#include<iostream>
#include<string>
#include<stack>
using namespace std;

//ջ�������ýӿ�
void test01()
{
	//����ջ���� ջ������������Ƚ����
	stack<int> s;
	
	//��ջ
	s.push(10); 
	s.push(20); 
	s.push(30); 
	
	while(!s.empty())
	{
		cout<<"ջ��Ԫ��Ϊ��"<<s.top()<<endl;
		s.pop();   //����ջ��Ԫ�� 
	}
	cout<<"ջ�Ĵ�СΪ��"<<s.size()<<endl; 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
