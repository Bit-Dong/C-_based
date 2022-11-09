#include<iostream>
#include<string>
#include<vector>
using namespace std;

//    ����vector����
//   vector<T> v;                     ����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯�� 
//   vector(v.begin(),v.end());       ��v[begin(),end())�����е�Ԫ�ؿ��������� 
//   vector(n,elem);                  ���캯����n��elem���������� 
//   vector(const vector &vec);       �������캯�� 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector ��������
void test01()
{
	vector<int> v1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //�������ֵ 
	} 
	printVector(v1);
	
//ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(),v1.end());     //��v1��ֵ����v2 
	printVector(v2);
	
//n��elem��ʽ����
	vector<int> v3(10,100);        //��10��Ϊ100����ֵ ����v3
	printVector(v3);
	
//��������
	vector<int> v4(v3);          //��v3��ֵ������v4 
	printVector(v4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
