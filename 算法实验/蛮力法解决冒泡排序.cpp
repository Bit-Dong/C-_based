#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
//��a[0..n-1]�������������ð������
{  int i,j; int tmp;
   bool exchange;
   for (i=0;i<n-1;i++)	   //����n-1������
   {	exchange=false;	   //��������ǰ��exchangeΪfalse
	for (j=n-1;j>i;j--)	   //������Ԫ�رȽ�,�ҳ���СԪ��
          if (a[j]<a[j-1])	   //������Ԫ�ط���ʱ
          {  swap(a[j],a[j-1]); //a[j]��a[j-1]���н���
             exchange=true;	   //����������exchangeΪtrue
          }
       if (exchange==false)  	   //����δ��������ʱ�����㷨
         return;
   }
}
int main()
{
	int a[]={5,9,4,2,1};
	BubbleSort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
}
