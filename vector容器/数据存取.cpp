#include<iostream>
#include<string>
#include<vector>
using namespace std;

//��vector�����е����ݽ��д�ȡ����  

// at(int idx);    ��������idx��ָ������   
// operator[];     ��������idx��ָ������ 
// front();        ���������е�һ������Ԫ�� 
// back();         �������������һ������Ԫ�� 


//��vector�����е����ݽ��д�ȡ����
void test01()
{
	vector<int> v1;  //Ĭ�Ϲ���

	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	} 
	
	//����[]��ʽ��������Ԫ��
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	
	//����at��ʽ����Ԫ��
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	} 
	cout<<endl;
	
	//��ȡ��һ��Ԫ��
	cout<<"��һ��Ԫ��Ϊ��"<<v1.front()<<endl;
	
	//��ȡ���һ��Ԫ��
	cout<<"���һ��Ԫ��Ϊ��"<<v1.back()<<endl; 

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
