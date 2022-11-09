#include<iostream>
#include<string>
using namespace std;

//����ͬ����� 
//1������CPU�� 
class CPU
{
	public:
		//����ļ��㺯��
		virtual void calculate()=0; 
};
//2�������Կ��� 
class VideoCard
{
	public:
		//�������ʾ����
		virtual void display()=0; 
};
//3�������ڴ����� 
class Memory
{
	public:
		//����Ĵ洢����
		virtual void storage()=0; 
};

//������
class Computer
{
	public:
		Computer(CPU *c,VideoCard *v,Memory *m)
		{
			cpu=c;
			vc=v;
			mem=m; 
		}
			//�ṩ�������� �ͷ�3���������
	~Computer()
	{
		//�ͷ�CPU���
		if(cpu!=NULL)
		{
			delete cpu;
			cpu=NULL;
		}
		//�ͷ��Կ����
		if(vc!=NULL)
		{
			delete vc;
			vc=NULL;
		} 
		//�ͷ��ڴ������
		if(mem!=NULL)
		{
			delete mem;
			mem=NULL;
		}  
	} 
		//�ṩ�����ĺ���
		void work()
		{
			//���������������������Ӧ�ӿ� 
			cpu->calculate();
			vc->display();
			mem->storage();
		} 
	private:
		CPU *cpu;        //CPU�����ָ�� 
		VideoCard *vc;   //�Կ����ָ�� 
		Memory *mem;     //�ڴ������ָ�� 
}; 

//���峧��
//Intel����
class IntelCPU : public CPU
{
	public:
		virtual void calculate()
		{
			cout<<"Intel��CPU��ʼ�����ˣ�"<<endl;
		}
}; 
class IntelVideoCard : public VideoCard
{
	public:
		virtual void display()
		{
			cout<<"Intel���Կ���ʼ��ʾ�ˣ�"<<endl;
		}
}; 
class IntelMemory : public Memory
{
	public:
		virtual void storage()
		{
			cout<<"Intel���ڴ�����ʼ�洢�ˣ�"<<endl;
		}
}; 

//Lenovo����
class LenovoCPU : public CPU
{
	public:
		virtual void calculate()
		{
			cout<<"Lenovo��CPU��ʼ�����ˣ�"<<endl;
		}
}; 
class LenovoVideoCard : public VideoCard
{
	public:
		virtual void display()
		{
			cout<<"Lenovo���Կ���ʼ��ʾ�ˣ�"<<endl;
		}
}; 
class LenovoMemory : public Memory
{
	public:
		virtual void storage()
		{
			cout<<"Lenovo���ڴ�����ʼ�洢�ˣ�"<<endl;
		}
};  

void test01()
{
	//��һ̨�������
	CPU *intelcpu=new IntelCPU;
	VideoCard *intelcard=new IntelVideoCard;
	Memory *intelmem=new IntelMemory;
	
	//������һ̨����
	cout<<"��һ̨���Կ�ʼ������"<<endl;
	Computer *computer1=new Computer(intelcpu,intelcard,intelmem);
	computer1->work();
	delete computer1;
	
	//�����ڶ�̨����
	cout<<"-------------------------------" <<endl;
	cout<<"�ڶ�̨���Կ�ʼ������"<<endl;
	Computer *computer2=new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
	computer2->work();
	delete computer2;
	
	//��������̨����
	cout<<"-------------------------------" <<endl;
	cout<<"����̨���Կ�ʼ������"<<endl;
	Computer *computer3=new Computer(new LenovoCPU,new IntelVideoCard,new LenovoMemory);
	computer3->work();
	delete computer3;
	
} 

int main()
{
	test01();
	system("pause");
	return 0;
}
