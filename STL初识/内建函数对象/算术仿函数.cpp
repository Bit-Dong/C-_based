#include<iostream>
#include<functional>
using namespace std;

/*
ʵ����������
����negate��һԪ���㣬�������Ƕ�Ԫ����

template<class T> T plus<T>          //�ӷ��º��� 
template<class T> T minus<T>         //�����º��� 
template<class T> T multiplies<T>    //�˷��º��� 
template<class T> T divides<T>       //�����º��� 
template<class T> T modulus<T>       //ȡģ�º��� 
template<class T> T negate<T>        //ȡ���º��� 
*/ 

//negate
void test01()
{
	negate<int> n;
	cout<<n(50)<<endl;
} 

void test02()
{
	plus<int>p1;
	cout<<p1(20,10)<<endl; 
	
	minus<int>p2;
	cout<<p2(20,10)<<endl; 
	
	multiplies<int>p3;
	cout<<p3(20,10)<<endl; 
	
	divides<int>p4;
	cout<<p4(20,10)<<endl; 
	
	modulus<int>p5;
	cout<<p5(20,10)<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
