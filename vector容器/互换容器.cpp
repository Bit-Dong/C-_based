#include<iostream>
#include<string>
#include<vector>
using namespace std;

//ʵ������������Ԫ�ؽ��л��� 
//  swap(vwc);   ��vec�뱾���Ԫ�ػ��� 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector �������в��롢ɾ������ 
void test01()
{
	cout<<"����ǰ��"<<endl;
	vector<int> v1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	
	vector<int> v2;  //Ĭ�Ϲ���
	for(int i=9;i>=0;i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	
	cout<<"������"<<endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

} 

//ʵ����;
//����swap���������ڴ�ռ� 
void test02()
{
	vector<int> v;  
	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
	}
	cout<<"���ʱ��"<<endl;
	cout<<"v������Ϊ��"<<v.capacity()<<endl;
	cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;	
	
	//����ָ����С
	cout<<endl<<"����ָ����С��"<<endl; 
	v.resize(3);     
	cout<<"v������Ϊ��"<<v.capacity()<<endl;
	cout<<"v�Ĵ�СΪ��"<<v.size()<<endl; 
	
	//����swap�����ڴ�
	cout<<endl<<"��������������н�����"<<endl;
	vector<int>(v).swap(v);     //��������������н����������������ջᱻϵͳ�Զ��ͷ� 
	cout<<"v������Ϊ��"<<v.capacity()<<endl;
	cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
} 
