#include<iostream>
#include<string>
#include<deque>
using namespace std;

//�ܽ᣺deque��ֵ��ʽ�Ƚϼ򵥣�ʹ��operator=����assign������ 
//  ��deque�������и�ֵ
// deque &operator=(const deque &vec);   ���صȺŲ����� 
// assign(beg,end);        ��[begin()��end())�����е����ݿ�����ֵ������ 
// assign(n,elem);         ��n��elem������ֵ������ 

void printDeque(const deque<int> &d)       // ��const��Ϊֻ�� 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  ֻ�������� 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//deque ������ֵ
void test01()
{
	deque<int> d1;  //Ĭ�Ϲ���
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);           //�������ֵ 
	} 
	printDeque(d1);
	
//��ֵ operator=
	deque<int> d2;
	d2=d1; 
	printDeque(d2);
	
//assign
	deque<int> d3;
	d3.assign(d1.begin(),d1.end());    //����assign���䷽ʽ(����ҿ�)  ��d1��ֵ��d3    
	printDeque(d3);
	
//n��elem��ʽ��ֵ
	deque<int> d4;
	d4.assign(10,100);        //10��100��ֵ��d4 
	printDeque(d4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
