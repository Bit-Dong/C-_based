#include<iostream>
#include<string>
using namespace std;

//����ҳ�� 
class BasePage
{
	public:
		void header()
		{
			cout<<"��ҳ�������Ρ���¼��ע��...������ͷ����"<<endl;
		}
		
		void footer()
		{
			cout<<"�������ġ�����������վ�ڵ�ͼ...�������ײ���"<<endl;
		}
		
		void left()
		{
			cout<<"Java��Python��C++...�����������б�"<<endl;
		}
};

//Javaҳ��
class Java : public BasePage
{
	public:
		void content()
		{
			cout<<"Javaѧ����Ƶ"<<endl;
		}
}; 

//Pythonҳ��
class Python : public BasePage
{
	public:
		void content()
		{
			cout<<"Pythonѧ����Ƶ"<<endl;
		}
}; 

//C++ҳ��
class CPP : public BasePage
{
	public:
		void content()
		{
			cout<<"C++ѧ����Ƶ"<<endl;
		}
}; 

test01()
{
	//Javaҳ��
	Java ja;
	cout<<"Java������Ƶҳ�����£�"<<endl;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout<<"-----------------------"<<endl;
	
	//Pythonҳ��
	Python py;
	cout<<"Python������Ƶҳ�����£�"<<endl;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout<<"-----------------------"<<endl;
	
	//C++ҳ��
	CPP cpp;
	cout<<"C++������Ƶҳ�����£�"<<endl;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout<<"-----------------------"<<endl;	 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
