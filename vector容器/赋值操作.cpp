#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�ܽ᣺vector��ֵ��ʽ�Ƚϼ򵥣�ʹ��operator=����assign������ 
//  ��vector�������и�ֵ
// vector &operator=(const vector &vec);   ���صȺŲ����� 
// assign(beg,end);        ��[begin()��end())�����е����ݿ�����ֵ������ 
// assign(n,elem);         ��n��elem������ֵ������ 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector ������ֵ
void test01()
{
	vector<int> v1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //�������ֵ 
	} 
	printVector(v1);
	
//��ֵ operator=
	vector<int> v2;
	v2=v1; 
	printVector(v2);
	
//assign
	vector<int> v3;
	v3.assign(v1.begin(),v1.end());    //����assign���䷽ʽ(����ҿ�)  ��v1��ֵ��v3    
	printVector(v3);
	
//n��elem��ʽ��ֵ
	vector<int> v4;
	v4.assign(10,100);        //10��100��ֵ��v4 
	printVector(v4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
