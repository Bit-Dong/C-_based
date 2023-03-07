/*
���η����п���
*/

#include<iostream>
using namespace std;
int Partition(int a[],int s,int t)	//�����㷨
{   int i=s,j=t;
    int temp=a[s];	//�����еĵ�1����¼��Ϊ��׼
    while(i!=j)
    {
        while(j>i&&a[j]>=temp)
            j--;   //��������ɨ�裬�ҵ�1���ؼ���С��tmp��a[j]
        a[i]=a[j];	//��a[j]ǰ�Ƶ�a[i]��λ��
        while(i<j&&a[i]<temp)
            i++;//��������ɨ�裬�ҵ�1���ؼ��ִ���tmp��a[i]
        a[j]=a[i];	//��a[i]���Ƶ�a[j]��λ��
    }
    a[i]=temp;
    return i;
}
void QuickSort(int a[],int s,int t)
//��a[s..t]Ԫ�����н��е�������
{  if (s<t) 			//���������ٴ���2��Ԫ�ص����
   {   int i=Partition(a,s,t);
       QuickSort(a,s,i-1);	//���������еݹ�����
       QuickSort(a,i+1,t);	//���������еݹ�����
   }
}
int main()
{
    int a[10]={5,4,6,2,10,0,3,8,7,9};
    QuickSort(a,0,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
