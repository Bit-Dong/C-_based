#include<iostream>
#include<string>
using namespace std;

//����Ȩ��(����)��
//        1������Ȩ��  public       ��Ա ���ڿɷ��ʣ����ⲻ�ɷ���
//        2������Ȩ��  protected    ��Ա ���ڿɷ��ʣ����ⲻ�ɷ���     ���ӿ��Է��ʸ��׵ı������� 
//        3��˽��Ȩ��  private      ��Ա ���ڿɷ��ʣ����ⲻ�ɷ���     ���Ӳ����Է��ʸ��׵�˽������ 

class people
{
	public:
		string name;
		
	protected:
		string car;
		
	private:
		string password;
		
	public:
		void func()
		{
			name="����";
			car="��ʱ��";
			password="123456789"; 
		}
		void display()
		{
			cout<<"������"<<name<<"  ���ͣ�"<<car<<"  ���룺"<<password<<endl; 
		}
};

int main()
{
	//ʵ�����������
	people c1;
	
	//  c1.car="������";         //�ᱨ���޸Ĳ���   ��ΪcarΪ����Ȩ�����ݣ���������ʲ��� 
	//  c1.password="546124";    //�ᱨ���޸Ĳ���   ��ΪpasswordΪ˽��Ȩ�����ݣ���������ʲ��� 
	
	c1.func();
	c1.display();
	
	system("pause");
	return 0;
}
