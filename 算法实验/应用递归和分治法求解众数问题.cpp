/*
��������������������n��Ԫ�صĶ��ؼ���S��ÿ��Ԫ����S�г��ֵĴ�����Ϊ��Ԫ�ص�������
			���ؼ�S����������Ԫ�س�Ϊ������?���磬S={1��2��2��2��3��5}��??���ؼ�S��������2��
			������Ϊ3��??���ڸ�������n ����Ȼ����ɵĶ��ؼ�S����̼���S ����������������
*/
#include <iostream>
#include<algorithm>
using namespace std;
#define M 100
int a[M];
int num,val,n; //����, ����,������
 
void find(int &l,int &r,int mid)//����λ�����������ұ߽�λ��
{
	l = r= mid;
 	while(a[l]==a[mid] && l>= 0) --l;
 	l++; //��ԭ
 	while(a[r]==a[mid] && r<= n-1) ++r;
 	r--;
}

void Fun(int low,int high)
{
	if(low > high) return; //���ұ߽罻�棬����
	int mid = (low + high)/2; //��λ��
	int i,j;
	find(i,j,mid);
	if(j-i+1 > num)
	{ //����
		num = j-i+1;
		val = a[mid];
 	}
 	if(i-low > num)
	{//���εݹ�
  		Fun(low,i-1);
 	}
 	if(high -j > num)
	 {
  		Fun(j+1,high);
 	}
}
int main()
{
    int  i;
    cout<<"����Ԫ�ظ�����\n";
    cin>>n;
    cout<<"����Ԫ�أ�\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
        cout<<a[i]<<",";
    Fun(0,n-1);
    cout<<endl<<"������"<<val<<" ������"<<num;
    return 0;
}
