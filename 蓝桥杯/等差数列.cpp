/*
��ѧ��ʦ��С������һ���Ȳ�������͵���Ŀ�����Ǵ��ĵ�С��������һ���ֵ����У�ֻ�ǵ�����N��������
���ڸ�����N��������С����֪��������N����������̵ĵȲ������м��
��������
����ĵ�һ�а���һ������ N���ڶ��а���N������A1,A2...An ��(ע�Ⲣ��һ���ǰ��Ȳ������е�˳�����)
���һ��������ʾ�𰸡�
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���
  int n,min=10000;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int j=0;j<n-1;j++){
    if(a[j+1]-a[j]<min){
        min=a[j+1]-a[j];
    }
  }
  int m=(a[n-1]-a[0])/min;
  if(min==0) cout<<n;
  else cout<<m+1;
  return 0;
}
