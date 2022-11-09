#include <iostream>
#include <string>
#include"MyArray.hpp"
using namespace std;

//��ӡ�������
void printIntArray(MyArray<int>& arr)
{
	cout<<"����Ԫ��Ϊ��";
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<endl;
	
	cout<<"��������Ϊ��"<<arr.getCapacity()<<endl;
	cout<<"����Ԫ�ظ���Ϊ��"<<arr.getSize()<<endl; 
	cout<<endl;
}

void test01()
{
	MyArray<int>arr1(5);
//	MyArray<int>arr2(arr1);    //�������� 
//	MyArray<int>arr3(100);     //�вι��� 
//	arr3=arr1;                 //operator= ���� 

	for(int i=0;i<5;i++)
	{
		arr1.Push_Back(i);
	}
	cout<<"����arr1�ľ�����Ϣ��"<<endl;
	printIntArray(arr1);
	
	
	MyArray<int>arr2(arr1);
	cout<<"����arr2�ľ�����Ϣ��"<<endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout<<"arr2βɾ�����ϢΪ��"<<endl;
	printIntArray(arr2);
}


class Person
{
public:
	Person(){};
	Person(string name,int age)
	{
		this->Name=name;
		this->Age=age;
	}
	
	string Name;
	int Age;
};

void printPersonArray(MyArray<Person> &arr)
{
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<"������"<<arr[i].Name<<"  ���䣺"<<arr[i].Age<<endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	
	Person p1("�����",99);
	Person p2("��˽�",88);
	Person p3("ɳ����",77);
	Person p4("������",66);
	Person p5("С����",55);
	
	//�����ݲ��뵽������
	arr.Push_Back(p1); 
	arr.Push_Back(p2); 
	arr.Push_Back(p3); 
	arr.Push_Back(p4); 
	arr.Push_Back(p5); 
	
	//��ӡ����
	printPersonArray(arr);
	
	//�������
	cout<<"arr����Ϊ��"<<arr.getCapacity()<<endl;
	
	//�����С 
	cout<<"arr��СΪ��"<<arr.getSize()<<endl;
	
}

int main()
{
//	test01();
	test02();	
	system("pause");
	return 0;
}
