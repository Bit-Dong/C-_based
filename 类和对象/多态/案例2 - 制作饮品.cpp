#include<iostream>
#include<string>
using namespace std;

//��̬����2   ������Ʒ
class AbstractDrinking
{
	public:
		//��ˮ
		virtual void Boil()=0; 
		//���� 
		virtual void Brew()=0;
		//���뱭�� 
		virtual void PourInCup()=0;
		//���븨�� 
		virtual void PutSomething()=0;
		
		//������Ʒ
		void makeDrink()
		{
			Boil();
			Brew();
			PourInCup();
			PutSomething();
		} 
};

//��������
class Coffee : public  AbstractDrinking
{
	public:
		//��ˮ
		virtual void Boil()
		{
			cout<<" 1����ũ��ɽȪ"<<endl;
		}
		//���� 
		virtual void Brew()
		{
			cout<<" 2�����ݿ���"<<endl;
		}
		//���뱭�� 
		virtual void PourInCup()
		{
			cout<<" 3�����뱭��"<<endl;
		}
		//���븨�� 
		virtual void PutSomething()
		{
			cout<<" 4�������Ǻ�ţ��"<<endl;
		}
}; 

//��������
class Tea : public  AbstractDrinking
{
	public:
		//��ˮ
		virtual void Boil()
		{
			cout<<" 1��������"<<endl;
		}
		//���� 
		virtual void Brew()
		{
			cout<<" 2�����ݲ�Ҷ"<<endl;
		}
		//���뱭�� 
		virtual void PourInCup()
		{
			cout<<" 3�����뱭��"<<endl;
		}
		//���븨�� 
		virtual void PutSomething()
		{
			cout<<" 4���������"<<endl;
		}
}; 

void doWork(AbstractDrinking *abs)
{
	abs->makeDrink();
	delete abs;
}

test01()
{
	cout<<"�������ȣ�"<<endl;
	doWork(new Coffee);
	cout<<endl<<"---------------"<<endl; 
	cout<<"������Ҷ��"<<endl;
	doWork(new Tea);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
