#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι���   ����������
	MyArray(int capacity)
	{
//		cout<<"Myarray�вι������"<<endl;
		this->Capacity=capacity;
		this->Size=0;
		this->pAddress=new T[this->Capacity];
	} 
	
	//��������
	MyArray(const MyArray &arr)
	{
//		cout<<"Myarray�����������"<<endl;
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
//		this->pAddress=arr.pAddress; 
		
		//��� 
		this->pAddress=new T[arr.Capacity];
		//��arr�е����ݶ���������
		for(int i=0;i<this->Size;i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		} 
	}
	
	//operator=  ��ֹǳ��������
	MyArray & operator=(const MyArray& arr)
	{
//		cout<<"Myarray ��operator= ����"<<endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if(this->pAddress!=NULL)
		{
			delete[] this->pAddress;
			this->pAddress=NULL;
			this->Capacity=0;
			this->Size=0;
		}
		
		//���
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
		this->pAddress=new T[this->Capacity];
		for(int i=0;i<this->Size;i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		}
		return *this;
	} 
	
	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		if(this->Capacity==this->Size) 
		{
			return;
		}
		this->pAddress[this->Size]=val;  //������ĩβ�������� 
		this->Size++;  //���������С 
	} 
	
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if(this->Size==0)
		{
			return;
		}
		this->Size--; 
	} 
	
	//ͨ���±귽ʽ���������е�Ԫ��  arr[0]=100;
	T & operator[](int index)
	{
		return this->pAddress[index];
	} 
	
	//������������
	int getCapacity()
	{
		return this->Capacity;
	}
	
	//���������С
	int getSize()
	{
		return this->Size;
	} 
	

	
	//�������� 
	~MyArray()
	{
		if(this->pAddress!=NULL)
		{
//			cout<<"Myarray������������"<<endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}
	
private:
	int Capacity;   //�������� 
	int Size;       //�����С 
	T *pAddress;    //ָ��ָ��������ٵ���ʵ���� 
};
