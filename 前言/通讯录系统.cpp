#include<iostream>
#include<string>
using namespace std;
#define max 1000

//������ϵ�˽ṹ��
struct lxr
{
	string name;     //���� 
	string sex;      //�Ա� 
	int age;         //���� 
	string phone;    //�ֻ����� 
	string addr;     //��ͥ��ַ 
};
 
//����ͨѶ¼�ṹ�� 
struct txl
{
	struct lxr abc[max];
	int count;
};

void showmean()
{
	cout<<"******************************"<<endl;
	cout<<"*****   1.�����ϵ��    ******"<<endl; 
	cout<<"*****   2.��ʾ��ϵ��    ******"<<endl;
	cout<<"*****   3.ɾ����ϵ��    ******"<<endl;
	cout<<"*****   4.������ϵ��    ******"<<endl;
	cout<<"*****   5.�޸���ϵ��    ******"<<endl;
	cout<<"*****   6.�����ϵ��    ******"<<endl;
	cout<<"*****   0.�˳�ͨѶ¼    ******"<<endl;
	cout<<"******************************"<<endl;
}

//�����ϵ��
int add(struct txl *mn)
{
	if(mn->count>=max)
	{
		cout<<"ͨѶ¼������"<<endl;
		return 0;
	}
	else
	{
		cout<<"��������ϵ�˵�������"<<endl;
		string name;
		cin>>name;
		mn->abc[mn->count].name=name;
		
		cout<<"��������ϵ�˵��Ա�"<<endl;
		string sex;
		cin>>sex;
		mn->abc[mn->count].sex=sex;
		
		cout<<"��������ϵ�˵����䣺"<<endl;
		int age;
		cin>>age;
		mn->abc[mn->count].age=age;
		
		cout<<"��������ϵ�˵��ֻ����룺"<<endl;
		string phone;
		cin>>phone;
		mn->abc[mn->count].phone=phone;
		
		cout<<"��������ϵ�˵ļ�ͥ��ַ��"<<endl;
		string addr;
		cin>>addr;
		mn->abc[mn->count].addr=addr;
		
		mn->count++;
		
		cout<<"�����ϵ�˳ɹ���"<<endl;
		
	}
} 

//��ʾ��ϵ��
int display(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"������ϵ�ˣ�"<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<mn->count;i++)
		{
			cout<<" ����: "<<mn->abc[i].name<<"    �Ա�: "<<mn->abc[i].sex<<"    ����: "<<mn->abc[i].age<<"     �ֻ�����: "<<mn->abc[i].phone<<"     ��ͥ��ַ: "<<mn->abc[i].addr<<endl<<endl;
		}
	}
} 

//ɾ����ϵ�� 
int del(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"ͨѶ¼��ϵ��Ϊ�գ�"<<endl;
		return 0;
	}
	

	else
	{
		string name;
		int flag;
		cout<<"��������ɾ������ϵ��������"<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			 flag=1;
			if(mn->abc[i].name==name)
			{
				int t=i;
				flag=0;
				for(int j=t;j<mn->count;j++)
				{
					mn->abc[j]=mn->abc[j+1];
				}
				mn->count--;
				cout<<"ɾ���ɹ���"<<endl;
				break;
			}
		
		}
			if(flag==1)
			{
				cout<<"���޴��ˣ�������ѡ��"<<endl;
			}
	}
}


//������ϵ��
int find(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"������ϵ�ˣ�������ѡ��"<<endl;
		return 0;
	}
	else
	{
		int flag;
		string name;
		cout<<"��������Ҫ������ϵ�˵�������"<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			 flag=1;
			if(mn->abc[i].name==name)
			{
			    flag=0;
				cout<<"���ҳɹ�������ϵ�˵���ϢΪ��"<<endl;
				display(mn);
             	break;
			}
		
		}
			if(flag==1)
			{
				cout<<"����ʧ�ܣ�������ѡ��"<<endl;
			}
	}
}


//�޸���ϵ��
int change(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"������ϵ�ˣ�������ѡ��"<<endl;
		return 0;
	}
	else
	{
		int flag;
		string name;
		cout<<"�������޸���ϵ�˵�������"<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			flag=1;
			if(mn->abc[i].name==name)
			{
			    flag=0;
			    cout<<"���ڸ���ϵ��"<<endl; 
			    cout<<"����������:"<<endl;
			    
			    cout<<"������";
			    string name1;
			    cin>>name1;
			    mn->abc[i].name=name1;
			    
			    cout<<endl<<"�Ա�";
			    string sex1;
			    cin>>sex1;
			    mn->abc[i].sex=sex1;
			    
			    cout<<endl<<"���䣺";
			    int age1;
			    cin>>age1;
			    mn->abc[i].age=age1;
			    
			    cout<<endl<<"�ֻ����룺";
			    string phone1;
			    cin>>phone1;
			    mn->abc[i].phone=phone1;
			    
			    cout<<endl<<"��ͥ��ַ��";
			    string addr1;
			    cin>>addr1;
			    mn->abc[i].addr=addr1;
			    
			    cout<<endl<<"�޸ĳɹ���"<<endl;
				break;
			}
		
		}
			if(flag==1)
			{
				cout<<"���޴��ˣ�������ѡ��"<<endl;
			}
	}
}


//�����ϵ��
int cls(struct txl *mn)
{
	for(int j=0;j<=mn->count;j++)
	{
		mn->abc[j]=mn->abc[j+1];
		mn->count--;
	}
	cout<<"��ճɹ���"<<endl;
}

 
int main()
{
	struct txl mn;
	mn.count=0;
	while(1)
	{
		showmean();
		int t;
		cout<<"������ѡ�����:"<<endl;
		cin>>t;
		switch(t)
		{
			case 1:           
				add(&mn);
				break;
				
			case 2:
				display(&mn);
				break;
				
			case 3:
				del(&mn);
				break;
				
			case 4:
				find(&mn);
				break;
				
			case 5:
				change(&mn);
				break;
				
			case 6:
				cls(&mn); 
				break;
				
			case 0:
				cout<<"�˳��ɹ�����ӭ�´�ʹ�ã�"<<endl;
				return 0;
				break;
			default:
				cout<<"������������ȷѡ����ţ�"<<endl;
				break;

		}
		system("pause");
		system("cls");
		
	}
	
	
	system("pause");
}
