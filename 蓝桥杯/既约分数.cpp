/*
��Ŀ����:
���һ�������ķ��Ӻͷ�ĸ�����Լ����1�����������Ϊ��Լ���������磬3/4,5/2,1/8,7/1���Ǽ�Լ������
���ʣ��ж��ٸ���Լ���������Ӻͷ�ĸ����1��2020֮�������������1��2020��
��Ŀ����:
����������ͨ�����Լ���ж�
*/

#include<iostream>
using namespace std;

int panduan(int a,int b)
{
	int c;
	if(a==1&&b==1) return 1;
	if(a>=b){
		while(c=a%b){
			a=b;
			b=c;
		}
		if(b==1) return 1;
		else return 0;
	}
	else{
		while(c=b%a){
			b=a;
			a=c;
		}
		if(a==1) return 1;
		else return 0;
	}	
}
int main(){
	int sum=0;
	for(int i=1;i<=2020;i++){
		for(int j=1;j<=2020;j++){
			sum+=panduan(i,j);
		}
	}
	cout<<sum<<endl;
	cout<<panduan(2,21);
} 
//#include<iostream>
//using namespace std;
//
//int gcd(int a,int b)
//{
//	if(a%b==0)
//		return b;
//	else
//		return gcd(b,a%b);
//}
//int main()
//{
//	int ans = 0;
//	for(int i = 1; i <= 2020; i++)
//	{
//		for(int j = 1; j <= 2020; j++)
//		{
//			if(gcd(i,j)==1)
//			{
//				ans++;
//			}
//		}
//	}
//	cout << ans <<endl;
//	return 0;
//}

