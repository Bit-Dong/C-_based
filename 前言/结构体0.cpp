#include<iostream>
#include<string>

using namespace std;

struct student
{
	string name;
	int age;
	string sex; 
};

int display(struct student hero[],int len)
{
	
	for(int i=0;i<len;i++)
	{
			cout<<hero[i].name<<"  "<<hero[i].age<<"   "<<hero[i].sex<<endl;
	}
}

int  maopao(struct student hero[],int len)
{
		int i,j;
		for(i=0;i<len-1;i++)
		{
			for(j=0;j<len-i-1;j++)
			{
				if(hero[j].age>hero[j+1].age)
				{
					struct student tmp=hero[j];
					hero[j]=hero[j+1];
					hero[j+1]=tmp;
				}
			}
		}
}

int main()
{
	int len;
    struct student hero[5]=
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},	
	};
	len=sizeof(hero)/sizeof(hero[0]);
	
	cout<<"����ǰ��"<<endl;
		for(int i=0;i<len;i++)
	{
			cout<<hero[i].name<<"  "<<hero[i].age<<"   "<<hero[i].sex<<endl;
	}
	
	cout<<"�����"<<endl;
	maopao(hero,len);
    display(hero,len);
	system("pause");
}
