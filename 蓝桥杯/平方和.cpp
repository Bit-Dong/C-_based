/*
С������λ�к���2��0��1��9�����ֺܸ���Ȥ����1��40��������������1��2��9��10��32��39��40����28�������ǵĺ���574��ƽ������14362��
ע�⣬ƽ������ָ��ÿ�����ֱ�ƽ������͡�
���ʣ���1��2019�У���������������ƽ�����Ƕ���?
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���
  long long sum=0;
  for(int i=1;i<=2019;i++){
    string str=to_string(i);
    if(str.find("2")==-1&&str.find("0")==-1&&str.find("1")==-1&&str.find("9")==-1) continue;
    else sum+=i*i;
  }
  cout<<sum;
  return 0;
}
