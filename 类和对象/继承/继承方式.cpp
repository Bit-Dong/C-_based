#include<iostream>
#include<string>
using namespace std;

//�����̳� 
class  Base1
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son1 : public Base1
{
	public:
		void func()
		{
			A=10;  //�����еĹ���Ȩ�޳�Ա  ����������Ȼ�ǹ���Ȩ�� 
			B=10;  //�����еı���Ȩ�޳�Ա  ����������Ȼ�Ǳ���Ȩ�� 
//			C=10;   //�����е�˽��Ȩ�޳�Ա  �����з��ʲ��� 
		}
};
test01()
{
	son1 s1;
	s1.A=100;
//	s1.B=100;   //��son1�� B�Ǳ���Ȩ�� ������ʲ��� 
}


//�����̳� 
class  Base2
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son2 : public Base2
{
	public:
		void func()
		{
			A=10;  //�����еĹ���Ȩ�޳�Ա  ���������Ǳ���Ȩ�� 
			B=10;  //�����еı���Ȩ�޳�Ա  ����������Ȼ�Ǳ���Ȩ�� 
//			C=10;   //�����е�˽��Ȩ�޳�Ա  �����з��ʲ��� 
		}
};
test02()
{
	son2 s2;
//	s2.A=100;   //��son2�� A�Ǳ���Ȩ�� ������ʲ���
//	s2.B=100;   //��son2�� B�Ǳ���Ȩ�� ������ʲ��� 
}


//˽�м̳� 
class  Base3
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son3 : public Base3
{
	public:
		void func()
		{
			A=10;  //�����еĹ���Ȩ�޳�Ա  ����������˽��Ȩ�� 
			B=10;  //�����еı���Ȩ�޳�Ա  ����������˽��Ȩ�� 
//			C=10;   //�����е�˽��Ȩ�޳�Ա  �����з��ʲ��� 
		}
};
class Grandson3 : public son3
{
	public:
		void func()
		{
//			A=10;  //����son3�� A��Ϊ��˽��Ȩ��  Grandson3���ʲ��� 
//			B=10;  //����son3�� B��Ϊ��˽��Ȩ��  Grandson3���ʲ��� 
//			C=10;   
		}	
};
test03()
{
	son3 s3;
//	s3.A=100;   //��son3�� A��˽��Ȩ�� ������ʲ���
//	s3.B=100;   //��son3�� B��˽��Ȩ�� ������ʲ��� 
}

int main()
{
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
}
