#include<iostream>
#include<string>
using namespace std;                                  //�������ʹ����������ԣ� 1�����Խ������ָ���ͷ�������� 
                                                     //                        2������Ҫ�о���ĺ���ʵ�� 
class Animal                                         // �������ʹ����������� ����Ǵ������� �������ڳ����࣬�޷�ʵ�������� 
{                                                   //  �������﷨�� virtual ~����(){}                   
	public:                                         // ���������﷨��virtual ~����()=0;   ����::~����(){} 
		Animal()
		{
			cout<<"Animal���캯������"<<endl;
		}
		
//		//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
//		virtual ~Animal()     
//		{
//			cout<<"Animal������������"<<endl;
//		}
		
		//��������   ��Ҫ��������Ҫʵ��
		//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ�������� 
		 virtual ~Animal()=0;
		
		//���麯��                                      //�ܽ᣺ 
		virtual void speak()=0;                         //   1�������������������������ͽ��ͨ������ָ���ͷ�������� 
	                                                    //   2�����������û�ж������ݣ����Բ�дΪ�������������� 
};                                                      //   3��ӵ�д���������������Ҳ���ڳ����� 
Animal::~Animal()
{
	cout<<"Animal������������"<<endl;
}


class Cat : public Animal
{
	public:
		Cat(string name)
		{
			cout<<"Cat���캯������"<<endl; 
			Name=new string(name);
		}
		
		~Cat()
		{
			if(Name!=NULL)
			{
				cout<<"Cat������������"<<endl;
				delete Name;
				Name=NULL;
			}
		}
		
		virtual void speak()
		{
			cout<<*Name<<"Сè��˵��"<<endl;
		}
		string *Name; 
};

void test01()
{
	Animal *animal=new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ�򲻻��������������������������������ж������ԣ������ڴ�й©
	delete animal;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
