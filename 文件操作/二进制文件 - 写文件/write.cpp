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
	ofstream ofs("person.txt",ios::out | ios::binary);
	
	//3��ָ���򿪷�ʽ 
	//ofs.open("test.txt",ios::out | ios::binary);
	
	Person p={"�½�",52};
	
	//4��д�ļ�
	ofs.write((const char *)&p,sizeof(p)); 

	
	//5���ر��ļ�
	ofs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
