/*
ʹ��STL�㷨sort()ʵ����������a�ĵ�������
*/

#include<iostream>
#include <algorithm>
using namespace std;
int main()  
{  int a[]={2,5,4,1,3};
   sort(a,a+5);
   for (int i=0;i<5;i++)
	printf("%d ",a[i]);	//���: 1 2 3 4 5
   printf("\n");
}
