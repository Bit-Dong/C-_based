/*
������������ĳ�����ҽ���1�֡�2�ֺ�5��Ӳ�ң���Ǯn(n>=5)�һ���Ӳ���кܶ��ֶҷ���
			��дһ��ʵ���������10��Ǯ�ж����ֶҷ������г�ÿ�ֶһ���ʽ��
*/
#include<iostream>
using namespace std;
int main()  
{
	int n=10;
	int x,y,z;
	int num=0;
	
	for(z=0;z<=2;z++)
	{
		for(y=0;y<=5;y++)
		{
			for(x=0;x<=10;x++)
			{
				if(z*5+y*2+x*1==10)
				{
					cout<<"�һ���ʽ"<<++num; 
					if(z!=0) cout<<" 5�ֵ�Ӳ���У�"<<z<<"��"; 
					if(y!=0) cout<<" 2�ֵ�Ӳ���У�"<<y<<"��"; 
					if(x!=0) cout<<" 1�ֵ�Ӳ���У�"<<x<<"��"; 
					
					cout<<endl;
				}
			}
		}
	
	}
	cout<<"����"<<num<<"�ֶһ���ʽ"<<endl; 
	 
	return 0;
}
