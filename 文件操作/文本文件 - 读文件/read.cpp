#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

void test01()
{
	//1������ͷ�ļ� fstream
	 
	//2������������ 
	ifstream ifs;
	
	//3���򿪷�ʽ ,���ж��Ƿ�򿪳ɹ� 
	ifs.open("test.txt",ios::in);    //���ļ�������ͬһ�ļ������� 
	
	if(!ifs.is_open())
	{
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	
	//4�������� 
	
//	//��һ��
//	char buf[1024]={0};
//	while(ifs>>buf)
//	{
//		cout<<buf<<endl;
//	}
//	
//	//�ڶ���
//	char buf[1024]={0};
//	while(ifs.getline(buf,sizeof(buf))) 
//	{
//		cout<<buf<<endl;
//	}
//	
//	//������ 
//	string buf;
//	while(getline(ifs,buf))
//	{
//		cout<<buf<<endl;
//	} 
//	
	//������       //ƽ�������������� 
	char c;
	while((c=ifs.get())!=EOF)   //EOF:end of file  �ļ�β
	{
		cout<<c;
	} 
	
	//5���ر��ļ�
	ifs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
