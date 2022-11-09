#include<iostream>
#include<string>
using namespace std;

//C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ� 

//��ͨʵ�� 
class Calculator
{
	public:
		int getResult(string oper)
		{
			if(oper == "+")
			{
				return A+B;
			}
			else if(oper == "-")
			{
				return A-B;
			}
			else if(oper == "*")
			{
				return A*B;
			}
		}
	public:
		int A;
		int B;
};
void test01()
{
	Calculator c;
	int A=10;
	int B=10;
	cout<<A<<" + "<<B<<" = "<<c.getResult("+")<<endl;
	cout<<A<<" - "<<B<<" = "<<c.getResult("-")<<endl;
	cout<<A<<" * "<<B<<" = "<<c.getResult("*")<<endl;
} 


//��̬ʵ��
//����������� 
// ��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstractCalculator
{
	public:		
		virtual int getResult()
		{
			return 0;
		}
	
	public:
		int A;
		int B; 
};

//�ӷ������� 
class AddCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A+B;
		}
};
//����������
class SubCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A-B;
		}
};
//�˷������� 
class MulCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A*B;
		}
};

void test02()
{
	//�����ӷ�������
	AbstractCalculator *abc=new AddCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" + "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //�������� 
	
	//��������������
	abc=new SubCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" - "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //��������  
	
	//�����˷�������
	abc=new MulCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" * "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //�������� 
 

}

int main()
{
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
