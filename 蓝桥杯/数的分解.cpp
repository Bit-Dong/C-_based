/*
��Ŀ����
�� 2019�ֽ�� 3��������ͬ��������֮�ͣ�����Ҫ��ÿ��������������
������2��4��һ���ж����ֲ�ͬ�ķֽⷽ����
ע�⽻�� 3��������˳����Ϊͬһ�ַ��������� 1000+1001+18��
1001+1000+18����Ϊͬһ�֡�
*/
#include <iostream>
using namespace std;

bool check(int n){
  for(int i=0;n!=0;i++){
    if(n%10==2||n%10==4) return false;
    else n/=10;
  }
  return true;
}

int main()
{
  int num=0;
  for(int num1=1;num1<=2019/3;num1++){
    if(check(num1)){
      for(int num2=num1+1;num2<=(2019-num1)/2;num2++){
        if(check(num2)){
          int num3=2019-num1-num2;
          if(check(num3)&&num3>num2) num++;
        }
      }
    }
  }
  cout<<num;
  return 0;
}
