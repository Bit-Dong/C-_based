#include<iostream>
using namespace std;

//���Բ ��ϵ���� 

///////����
class Point
{
	public:
		//����X 
		void setX(int x)
		{
			X=x;
		}
		//��ȡX
		int getX()
		{
			return X;
		}
		
		//����Y
		void setY(int y)
		{
			Y=y;
		}
		//��ȡY
		int getY()
		{
			return Y;
		}
		
	private:
	    int X;
		int Y; 
};

///////Բ�� 
class Circle
{
	public:
		//���ð뾶
		void setR(int r)
		{
			R=r;
		}
		//��ȡ�뾶
		int getR()
		{
			return R;
		}
		
		//����Բ��
		void setCenter(Point center)
		{
			Center=center;
		}
		//��ȡԲ�� 
		Point getCenter()
		{
			return Center;
		}
		
	private:
		int R;
		Point Center;        //�����У���������һ�����������еĳ�Ա 
};

//�жϵ��Բ�Ĺ�ϵ
void judge(Circle &c,Point &p)
{
	int distance=( (c.getCenter().getX() - p.getX() ) * (c.getCenter().getX() - p.getX() ) +  (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY())   );
	int t=c.getR()*c.getR();
	if(distance>t)
	{
		cout<<"����Բ�⣡"<<endl;
	}
	else if(distance==t)
	{
		cout<<"����Բ�ϣ�"<<endl;
	}
	else 
	{
		cout<<"����Բ�ڣ�"<<endl;
	}
}

int main()
{
	Circle c;
	c.setR(5);
	Point cen;
	cen.setX(0);
	cen.setY(0);
	c.setCenter(cen);
	
	Point p;
	p.setX(2);
	p.setY(5); 
	 
	judge(c,p);
	
	system("pause");
}










//********************************// 

/*#include<iostream>
using namespace std;

class Circle
{
	public:
		//���Բ�İ뾶
		void setR(int r)
		{
			R=r;
		}
		//��ȡԲ�İ뾶
		int getR()
		{
			return R;
		} 
	
	
	private:
		int R;
};

class Point
{
	public:
		//���õ㵽Բ�뾶�ľ���
		void setL(int l)
		{
			L=l;
		}
		//��ȡ�㵽Բ�뾶�ľ���
		int getL()
		{
			return L;
		}
		
	private:
	    int L; 
};

int main()
{
	Circle c1;
	c1.setR(5);
	
	Point l1;
	l1.setL(2);
	
	if(c1.getR()>l1.getL())
	{
		cout<<"����Բ�ڣ�"<<endl;
	}
	else if(c1.getR()==l1.getL())
	{
		cout<<"����Բ�ϣ�"<<endl;
	}
	else
	{
		cout<<"����Բ�⣡"<<endl;
	}
	
	system("pause");
}*/
