/*
�ݹ�ʵ��ð������
*/
#include<iostream>
using namespace std;
void BubbleSort(int a[], int n,int i)
{   int  j;
    bool exchange;
    if (i==n-1) return;		//����ݹ��������
    else
    {
    	exchange=false;		//��exchangeΪfalse
    	for(j=n-1;j>i;j--)
		    if(a[j]<a[j-1]) //������Ԫ�ط���ʱ
		    {
		    	swap(a[j],a[j-1]);
		    	exchange=true; //����������exchangeΪtrue
			}
		
		if(exchange==false) //δ��������ʱֱ�ӷ��ء�
	    	return ;
	    else                   //��������ʱ�����ݹ����
            BubbleSort(a,n,i+1);	        
    	
	}
}
int main()
{
	int a[10]={5,4,6,2,1,0,3,8,7,9};
	BubbleSort(a,10,0);
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<' ';
 } 
