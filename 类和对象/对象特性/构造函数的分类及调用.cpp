#include<iostream>
using namespace std;

//���캯���ķ��ࣺ 
//      1�����ղ��������Ϊ�вκ��޲ι���  �޲��ֳ�ΪĬ�Ϲ��캯��
//      2���������ͷ����Ϊ��ͨ����Ϳ�������

//���캯���ĵ��÷�ʽ��
//        ���ŷ�����ʾ������ʽת����

class Person
{
	public:
	
	//�޲ι��� 
		Person()
		{
			cout<<"Person���޲ι��캯�����ã�"<<endl;
		}
	//�вι���	
		Person(int a)
		{
			age=a;
			cout<<"Person���вι��캯�����ã�"<<endl;
		}
	
	//��������
	 	Person(const Person &p)
		{
			//������������ϵ���������,������������
			age=p.age;
			cout<<"Person�Ŀ������캯�����ã�"<<endl;
		}
			
		~Person()
		{
			cout<<"Person�������������ã�"<<endl; 
		}
		
	int age; 
}; 

//���÷�ʽ 
void txt()
{
//���ŷ�
//	Person p1;        //Ĭ�Ϻ�������
//	Person p2(10);    //�вκ�������
//	Person p3(p2);    //������������ 
//ע������:
//     ����Ĭ�Ϻ���ʱ��Ҫ�� ()
//     ��Ϊ�������д��룬����������Ϊ��һ��������������������Ϊ�ڴ������� 
//     Person p1();   ������ void func();

//��ʾ��
//    Person p1;
//	Person p2=Person(10);   //�вι��� 
//	Person p3=Person(p2);   //��������
	
	//Person(10);   //��������  �ص㣺��ǰ��ִ�н�����ϵͳ������������������ 
	//cout<<"aaaaa"<<endl; 
//ע�����
//     ��Ҫ���ÿ������캯������ʼ���������󣬱���������Ϊ Person(p3)�ȼ���Person p3 ;�������� 
//     Person(p3);

//��ʽת����
    Person p4=10;      //�൱�� д�� Person p4 = Person(10); �вι���
	Person p5=p4;      //�������� 
}

int main()
{
	txt();
	
	system("pause");
} 
