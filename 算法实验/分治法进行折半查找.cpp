/*
���η������۰����
*/

#include<iostream>
#include<algorithm>
using namespace std;
int BinSearch(int a[],int low,int high,int k)
//�������㷨
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==k)
            return mid;
        if(a[mid]>k)
            return BinSearch(a,low,mid-1,k);
        else
            return BinSearch(a,mid+1,high,k);
    }
    return -1;
}
int main()
{
    int i;
    int k=2;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    i=BinSearch(a,0,9,k);
    if(i!=-1)
    {
        cout<<"�ҵ�,λ���ǣ�"<<i<<endl;
    }
    else cout<<"δ�ҵ�"<<endl;
    return 0;
}
