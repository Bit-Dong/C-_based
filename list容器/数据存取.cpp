#include<iostream>
#include<string>
#include<list>
using namespace std;

void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	//l[0] ��������[]����list�����е�Ԫ��
	//l.at(0) ��������at��ʽ����list�����е�Ԫ��
	//ԭ����list�����������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�
	cout<<"��һ��Ԫ��Ϊ��"<<l.front()<<endl;
	cout<<"���һ��Ԫ��Ϊ��"<<l.back()<<endl;
	
	//��֤�������ǲ�֧��������ʵ�
	list<int>::iterator it=l.begin();
	it++;    //֧��˫��
	it--;
	//it=it+1     //��֧��������� 	
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
