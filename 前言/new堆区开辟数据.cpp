#include<iostream>
#include<string>

using namespace std;

/*int *fuc()
{
	int *p=new int(1102);   //���������������� 
	return p;              //�������ݶ�Ӧ���͵�ָ�� 
} 
int main()
{
	int *p=fuc();
	cout<<*p<<endl;
	delete p;           //�ͷ� 
	cout<<*p<<endl;	    //������� 
	system("pause");
} */

int *arr=new int[10];     //������������ 
int txt()
{
	for(int i=0;i<10;i++)
	{
		arr[i]=i;
		cout<<arr[i]<<"   ";    //������� 
	}
}

int main()
{
	txt();
	system("pause");
}
