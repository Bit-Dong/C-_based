/*
����һ�����ʣ������ڵ�����ɾ��t����ĸ���ܵõ����ֵ�����С�ĵ�����ʲô��

��������
����ĵ�һ�а���һ�����ʣ��ɴ�дӢ����ĸ��ɡ�
�ڶ��а���һ�������� t�����У����ʳ��Ȳ�����100��tС�ڵ��ʳ��ȡ�
�������
���һ�����ʣ���ʾ�𰸡�
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���
  string str;
  int n;
  cin>>str;
  cin>>n;
  int f=str.length()-1;
  while(n--){
    for(int i=0;i<str.length()-1;i++){
      if(str[i]>str[i+1]){
        f=i;
        break;
      }
    }
    str[f]='0';
  }

  for(int j=0;j<str.length();j++){
    if(str[j]!='0') cout<<str[j];
  }
  return 0;
}
