#include<iostream>
using namespace std;
void SelectSort(int a[],int n)
//��a[0..n-1]Ԫ�ؽ��е�����ѡ������
{  int i,j,k;
   for (i=0;i<n-1;i++)	//����n-1������
   {   k=i;			//��k��¼ÿ������������СԪ�ص�λ��
       for (j=i+1;j<n;j++)	//��a[i+1..n-1]���������СԪ��a[k]
	   if (a[j]<a[k]) 
	      k=j;	
       if (k!=i)		//��a[k]������СԪ��,��a[k]��a[i]����
	   swap(a[i],a[k]);
   }
}
int main()
{
	int a[]={5,9,4,2,1};
	SelectSort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
}
