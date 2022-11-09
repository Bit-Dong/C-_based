#include<iostream>
#include<string>
using namespace std;

//ʵ��ͨ�� �������������ĺ��� 
//���� �Ӵ�С 
//�㷨  ѡ�� 
//����  char���顢int����

//��������ģ��
template<typename T>      //typename�����滻�� class 
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}   

//�����㷨
template<class T>  
void mySort(T arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		int max=i;
		for(int j=i+1;j<len;j++)
		{
			if(arr[max]<arr[j])
			{
				max=j;
			}
		}
		if(max!=i)
		{
			mySwap(arr[max],arr[i]);
		}
	}
}

//�ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 


// ����char����
void test01()     
{
	char charArr[]="badfec";
	int len=sizeof(charArr)/sizeof(char);
	mySort(charArr,len);
	printArray(charArr,len);
}

// ����int����
void test02()     
{
	int intArr[]={2,5,1,6,8,4,7,5,0,1,3};
	int len=sizeof(intArr)/sizeof(int);
	mySort(intArr,len);
	printArray(intArr,len);
}


int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
