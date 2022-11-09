#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
#include<stdlib.h>     //rand����� 
#define CEHUA  0
#define MEISHU 1
#define YANFA  2

using namespace std;

class Worker
{
	public:
		string Name;
		int Salary;
};

//1������Ա�� 
void creatWorker(vector<Worker>&v)
{
	string nameSeed="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		Worker worker;
		worker.Name="Ա��";
		worker.Name+=nameSeed[i];
		
		worker.Salary=rand() %10000+10000;   //10000~19999
		v.push_back(worker);
	}
}

//2��Ա������
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
	{
		//����������ű��
		int deptId=rand()%3;    // 0��1��2
		//��Ա�����뵽������
		//key���ű�ţ�value����Ա��
		m.insert(make_pair(deptId,*it)); 
	}
}

//������ʾԱ�� 
void showWorkerByGourp(multimap<int,Worker>&m)
	{
		cout<<"�߻����ţ�"<<endl;
		multimap<int,Worker>::iterator pos=m.find(CEHUA);
		int count=m.count(CEHUA);    //ͳ�ƾ������� 
		int index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"������"<<pos->second.Name<<"   ���ʣ�"<<pos->second.Salary<<endl;
		}
		
		cout<<"--------------------------"<<endl<<endl;
		cout<<"�������ţ�"<<endl;
		pos=m.find(MEISHU);
		count=m.count(MEISHU);    //ͳ�ƾ������� 
		index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"������"<<pos->second.Name<<"   ���ʣ�"<<pos->second.Salary<<endl;
		}
		
		cout<<"--------------------------"<<endl<<endl;
		cout<<"�з����ţ�"<<endl;
		pos=m.find(YANFA);
		count=m.count(YANFA);    //ͳ�ƾ������� 
		index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"������"<<pos->second.Name<<"   ���ʣ�"<<pos->second.Salary<<endl;
		}
	} 

int main()
{
	srand((unsigned int)time(NULL));
	
	//1������Ա�� 
	vector<Worker>vWorker;
	creatWorker(vWorker);
//	for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++)
//	{
//		cout<<"������"<<it->Name<<"   ���ʣ�"<<it->Salary<<endl;
//	}
	
	//2��Ա������
	multimap<int,Worker>mWorker;
	setGroup(vWorker,mWorker);
	 
	//3��������ʾԱ�� 
	showWorkerByGourp(mWorker); 
	
	system("pause");
	return 0;
	
}
