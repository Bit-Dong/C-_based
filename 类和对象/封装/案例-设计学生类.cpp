#include<iostream>
#include<string>
using namespace std;


class student
{
	//����Ȩ��
	public:    //����Ȩ��
	                                           //���е����Ժ���Ϊ ����ͳһ��Ϊ����Ա�� 
	//����                                    //����   ��Ա����  ��Ա���� 
	string name;                              //��Ϊ   ��Ա����  ��Ա���� 
	string num;
	
	//��Ϊ
//ѧ��c1��	
	string xingming()
	{
		return name;
	}
	string xuehao()
	{
		return num;
	}
	

    //��Ϊ
//ѧ��c2�� 
	void show()    //��ʾ 
	{
	    cout<<"������"<<name<<"  ѧ��:"<<num<<endl; 
    }
    //��������ֵ
    void setname(string name1)     
    {
        name=name1;
    }
    //��ѧ�Ÿ�ֵ 
    void setnum(string num1)    
    {
        num=num1;
	}
	
};

int main()
{
//����1�� 
	student c1;
	c1.name="����";
	c1.num="2006702-03";
	cout<<"������"<<c1.xingming()<<"  ѧ�ţ�"<<c1.xuehao()<<endl;

//����2��	
	student c2;
	c2.setname("����");
	c2.setnum("123123");
	c2.show();
	
	system("pause");
}
