#include<iostream>
#include<string>
#include<vector>
using namespace std;

        //�ܽ᣺   ����������ϴ�ʱ������һ��ʼ����reserve Ԥ���ռ� 
        
//����vector�ڶ�̬��չ����ʱ����չ���� 
//  reserve(int len);  ����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��� 

void test01()
{
	vector<int> v;  
	
	//Ԥ���ռ� 
	v.reserve(10000);         //δ�Ӵ��д���ǰ num=15������Ҫ��̬��չʮ���    �Ӵ��д���ֻ��Ҫ1�Σ�����Ԥ������ 
	
	int num=0;
	int *p=NULL;
	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
		if(p!=&v[0])
		{
			p=&v[0];
			num++;
		}
	}
	cout<<"num = "<<num<<endl;

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
