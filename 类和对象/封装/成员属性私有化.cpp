#include<iostream>
#include<string>
using namespace std;

//  ��Ա����˽�л�
//   1���Լ����Կ��ƶ�дȨ��
//   2������д���Լ�����ݵ���Ч��

//�������
class people                          //        ��������Ϊ    �ɶ���д 
{                                     //        ��������Ϊ    ֻ�� 
	public:                           //        Ů��������Ϊ  ֻд 
		//��������  
		void setname(string name1)
		{
			name=name1;
		}
		
		//��ȡ����
		string getname()
		{
			return name;
		}
		
		//��ȡ����
		int getage()
		{
			age=20;
			return age;
		} 
		 
		//����Ů����
		void setgirlfriend(string girlfriend1)
		{
			girlfriend=girlfriend1;
		}
		
				
	
	private:
		string name;            //����Ϊ�ɶ���д 
	    int age;                //����Ϊֻ�� 
		string girlfriend;      //����Ϊֻд 
}; 

int main()
{ 
// ����cΪ������� 
	people c;
	
//�������������ȡ
    c.setname("����");
	cout<<"������"<<c.getname()<<endl;
	
//����Ķ�ȡ
    cout<<"���䣺"<<c.getage()<<endl;
	
//Ů���ѵ�����
    c.setgirlfriend("�Ծ�"); 
	
} 
