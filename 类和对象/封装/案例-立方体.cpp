#include<iostream>	
using namespace std;

//   �����������
//         1��������������      
//         2��������� 
//         3�������Ϊ  ��ȡ�������������� 
//         4���ֱ�����ȫ�ֺ����ͳ�Ա����  �ж������������Ƿ���ͬ 
 
 
//������������ 
class Cube
{
   	public:
   		//���ó� 
   		void setL(int l)
   		{
   			L=l;
		}
		//��ȡ��
		int getL()
		{
			return L;
		}
		
   		//���ÿ� 
   		void setW(int w)
   		{
   			W=w;
		}
		//��ȡ��
		int getW()
		{
			return W;
		}		
   		
   		//���ø� 
   		void setH(int h)
   		{
   			H=h;
		}
		//��ȡ��
		int getH()
		{
			return H;
		}
		
		//��ȡ���������
		int getcalculaterS()
		{
			return 2*(L*W+L*H+W*H);
		}
		
		//��ȡ���������
		int getcalculaterV()
		{
			return L*W*H;
		}
		
//��Ա�����ж������������Ƿ���ͬ 
bool same2(Cube &c)
{
	if(H==c.getH()&&L==c.getL()&&W==c.getW())
	{
		return true;
	}
	return false;
}
		   		
   	private:
   		int L;
   		int W;
   		int H;
}; 

//ȫ�ֺ����ж������������Ƿ���ͬ
bool same1(Cube &c1,Cube &c2)
{
	if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW())
	{
		return true;
	}
	return false;
}

int main()
{
//����������c1 
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout<<"������c1�����Ϊ��"<<c1.getcalculaterS()<<endl;
	cout<<"������c1�����Ϊ��"<<c1.getcalculaterV()<<endl;

//����������c2
    Cube c2;
    c2.setL(10);
	c2.setW(10);
	c2.setH(10);
	cout<<"������c2�����Ϊ��"<<c2.getcalculaterS()<<endl;
	cout<<"������c2�����Ϊ��"<<c2.getcalculaterV()<<endl;	 

//ȫ�ֺ����ж�
    bool ref1=same1(c1,c2);
    if(ref1)
    {
    	cout<<"ȫ�ֺ����жϣ�������c1��������c2��ͬ��"<<endl;
	}
	else
	{
		cout<<"ȫ�ֺ����жϣ�������c1��������c2����ͬ��"<<endl;
	}
 
//��Ա�����ж�
    bool ref2=c1.same2(c2);
    if(ref2)
    {
    	cout<<"��Ա�����жϣ�������c1��������c2��ͬ��"<<endl;
	}
	else
	{
		cout<<"��Ա�����жϣ�������c1��������c2����ͬ��"<<endl;
	}	 
 
	system("pause");
}
