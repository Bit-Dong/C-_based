/*
�ݹ�ʵ�ּ�ѡ������
*/

#include<iostream>
using namespace std;
void SelectSort(int a[], int n, int i)
{   int j, k;
    if (i==n-1) return;	//����ݹ��������
    else
    {
    	k=i;			//k��¼a[i..n-1]����СԪ�ص��±�
    	for (j=i+1;j<n;j++)  	//��a[i..n-1]������СԪ��
		    if (a[j]<a[k])
		        k=j;
	    if (k!=i)		//����СԪ�ز���a[i]
	        swap(a[i],a[k]);	//a[i]��a[k]����
     	SelectSort(a,n,i+1);
    	
    	
	}
}
int main()
{
	int a[10]={5,4,6,2,1,0,3,8,7,9};
	SelectSort(a,10,0);
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<' ';
 } 
