#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

class Person
{
	public:
		char Name[64];
		int Age;
};

void test01()
{
	//1������ͷ�ļ� fstream
	 
	//2������������ 
	ifstream ifs("person.txt",ios::in | ios::binary);
	
	//3���򿪷�ʽ ,���ж��Ƿ�򿪳ɹ� 
//	ifs.open("person.txt",ios::in);    //���ļ�������ͬһ�ļ������� 
	
	if(!ifs.is_open())
	{
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	
	//4�������� 
	Person p;
	ifs.read((char *)&p,sizeof(p)); 

	cout<<"������" <<p.Name<<"  ���䣺" <<p.Age<<endl;
	
	//5���ر��ļ�
	ifs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
