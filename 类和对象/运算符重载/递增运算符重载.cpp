#include<iostream>
#include<string>
using namespace std;

class MyInteger
{
	friend ostream & operator<<(ostream &out,MyInteger myint);   //ȫ�ֺ�������Ԫ�����Է���˽��Ȩ�� 
	public:
		MyInteger()
		{
			Num=0;
		}

	//ǰ��++
	MyInteger &operator++()     //��������Ϊ��һֱ��һ�����ݽ��е�������
	{
		Num++;  
		return *this;
	} 
	//����++
	MyInteger operator++(int)   // operator++(int)  int����ռλ������������������ǰ�úͺ��õ���
	{
		MyInteger temp=*this;   //��¼��ǰ�����ֵ�� Ȼ���ñ����ֵ��һ1�� ���Ƿ��ص�����ǰ��ֵ�� �ﵽ�ȷ��غ�++ 
		Num++;
		return temp; 
	} 
	private:
		int Num;

};

//ֻ������ȫ�ֺ����������������
ostream & operator<<(ostream &out,MyInteger myint)   
{
	out<<myint.Num;
	return out;
}

//ǰ��++  ��++ �ٷ��� 
void test01()
{
	MyInteger myInt;
	cout<<++myInt<<endl;
	cout<<myInt<<endl;
}

//����++  �ȷ��� ��++ 
void test02()
{
	MyInteger myInt;
	cout<<myInt++<<endl;
	cout<<myInt<<endl;
}

int main()
{ 
	
	test01();
	test02();
	system("pause");
	return 0; 
}
