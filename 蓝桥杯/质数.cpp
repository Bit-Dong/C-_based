/*
����֪����һ��������2���ڶ��������� 3������������5... 
��������2019�������Ƕ��٣�
*/

#include <iostream>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���
  int flag=0;
  int num=2;
  for(int i=5;i<20000;i++){
    flag=0;
    for(int j=2;j<i;j++){
      if(i%j==0){
        flag=1;
        break;
      }
    }
    if(flag==0){
      num++;
      if(num==2019) cout<<i;
    }
  }

  return 0;
}
