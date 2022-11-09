#include"WorkerManager.h"

WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //���ļ�
	
//  1���ļ���������� 
	if(!ifs.is_open()) 
	{
//		cout<<"�ļ�������"<<endl;
		this->EmpNum=0;         //��ʼ����¼���� 
		this->EmpArray=NULL;    //��ʼ������ָ��
		this->FileIsEmpty=true;  //��ʼ���ļ��Ƿ�λ�� 
		ifs.close();            //�ر��ļ� 
		return;
	}
	
// 2���ļ����ڣ�������Ϊ��
	char ch;
	ifs>>ch;
	if(ifs.eof()) 
	{
//		cout<<"�ļ�Ϊ��!"<<endl;
		this->EmpNum=0;         //��ʼ����¼���� 
		this->EmpArray=NULL;    //��ʼ������ָ��
		this->FileIsEmpty=true;  //��ʼ���ļ��Ƿ�λ�� 
		ifs.close();            //�ر��ļ� 
		return;
	}   
	
// 3���ļ����ڣ����Ҽ�¼����
	int num=this->get_EmpNum();
//	cout<<"ְ������Ϊ��"<<num<<endl;
	this->EmpNum=num; 
	
	
	this->EmpArray=new Worker*[this->EmpNum]; //���ٿռ�
	this->init_Emp();      //���ļ��е����� �浽������ ��
	
	//���� 
//	for(int i=0;i<this->EmpNum;i++)
//	{
//		cout<<"ְ����ţ�"<<this->EmpArray[i]->Id<<"\t������"<<this->EmpArray[i]->Name<<"\t���ű�ţ�"<<this->EmpArray[i]->DeptId<<endl;
//	} 

}

WorkerManager::~WorkerManager()
{
	if(this->EmpArray!=NULL)
	{
		for(int i=0;i<this->EmpNum;i++)
		{
			if(this->EmpArray[i]!=NULL)
			{
				delete this->EmpArray[i];
			}
		}
		delete[] this->EmpArray;
		this->EmpArray=NULL;
	}	
}

//�˵� 
void WorkerManager:: Show_Menu()
{
	cout<<"**************************************************"<<endl;
	cout<<"************ ��ӭʹ��ְ������ϵͳ��***************"<<endl;
	cout<<"**************  0. �˳��������   ****************"<<endl;
	cout<<"**************  1. ����ְ����Ϣ   ****************"<<endl;
	cout<<"**************  2. ��ʾְ����Ϣ   ****************"<<endl;
	cout<<"**************  3. ɾ����ְְ��   ****************"<<endl;
	cout<<"**************  4. �޸�ְ����Ϣ   ****************"<<endl;
	cout<<"**************  5. ����ְ����Ϣ   ****************"<<endl;
	cout<<"**************  6. ���ձ������   ****************"<<endl;
	cout<<"**************  7. ��������ĵ�   ****************"<<endl;
	cout<<"**************************************************"<<endl;
	cout<<endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout<<"��ӭ�´�ʹ�ã�"<<endl;
	system("pause");
	exit(0);
} 

//���ְ��
void WorkerManager::Add_Emp()
{
	cout<<"���������ְ��������"<<endl;
	
	int addNum=0;     //�����û�����������
	cin>>addNum;
	
	if(addNum>0)
	{
		//���
		int newSize=this->EmpNum+addNum;    //�¿ռ�����=ԭ����¼���� + ��������
		Worker **newSpace=new Worker *[newSize];   //�����¿ռ�
		if(this->EmpArray!=NULL)
		{
			for(int i=0;i<this->EmpNum;i++)
			{
				newSpace[i]=this->EmpArray[i];
			}
 		}
			//�������������
			for(int i=0;i<addNum;i++)
			{
				int id;        //ְ�����
				string name;   //ְ������
				int dSelect;   //����ѡ��
				cout<<"������� "<<i+1<<" ����ְ����ţ�"<<endl; 
				cin>>id;
				cout<<"������� "<<i+1<<" ����ְ��������"<<endl; 
				cin>>name;
				cout<<"��ѡ���ְ����λ��"<<endl; 
				cout<<"1����ְͨ��"<<endl;
				cout<<"2������"<<endl;
				cout<<"3���ϰ�"<<endl;
				cin>>dSelect; 
			
			
			Worker *worker=NULL;
			switch(dSelect)
			{
				case 1:
					worker=new Employee(id,name,1);
					break;
				case 2:
					worker=new Manager(id,name,2);
					break;
				case 3:
					worker=new Boss(id,name,3);
					break;
				default:
					break;
			}
			 //������ְ��ְ�𣬱��浽������
			 newSpace[this->EmpNum+i]=worker; 
		 }
		delete[] this->EmpArray;     //�ͷ�ԭ�пռ� 
		this->EmpArray=newSpace;     //�����¿ռ�ָ�� 
		this->EmpNum=newSize;        //�����µ�ְ������
		cout<<"�ɹ����"<<addNum<<"����ְ����"<<endl;    //��ʾ��ӳɹ� 
		
		this->save();    //�������ݵ��ļ��� 
	}
	else
	{
		cout<<"������������"<<endl; 
	}
	
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);    //������ķ�ʽ���ļ� ---д�ļ�
	
	//��ÿ��������д�뵽�ļ���
	for(int i=0;i<this->EmpNum;i++)
	{
		ofs<<this->EmpArray[i]->Id<<"  "<<this->EmpArray[i]->Name<<"  "<<this->EmpArray[i]->DeptId<<endl;
	} 
	
	ofs.close();   //�ر��ļ� 
} 

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //���ļ� ��
	int id;
	string name;
	int did;
	int num=0;     //ͳ���������� 
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;    
	} 
	return num; 
} 

//��ʼ��Ա�� 
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //���ļ� ��
	int id;
	string name;
	int did;
	int index=0;
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker *worker=NULL;
		if(did==1)  //��ְͨ�� 
		{
			worker=new Employee(id,name,did);
		}
		else if(did==2)  //���� 
		{
			worker=new Manager(id,name,did);
		}
		else     //�ϰ� 
		{
			worker=new Boss(id,name,did);
		}
		this->EmpArray[index]=worker;
		index++; 
	} 
	ifs.close();   //�ر��ļ� 
} 

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		for(int i=0;i<EmpNum;i++)
		{
			this->EmpArray[i]->showInfo();    //���ö�̬���ýӿ� 
		}
	}
	system("pause");
	system("cls");
} 

//ɾ��ְ��
void WorkerManager:: Del_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
	} 
	else
	{
		cout<<"��������Ҫɾ��ְ����ţ�"<<endl;
		int id=0;
		cin>>id;
		
		int index=this->IsExist(id);
		if(index!=-1)  //˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{
			//����ǰ��
			for(int i=index;i<this->get_EmpNum()-1;i++)
			{
				this->EmpArray[i]=this->EmpArray[i+1];
			}
			this->EmpNum--;   //���������м�¼��Ա����
			this->save();     //����ͬ�����µ��ļ���
			cout<<"ɾ���ɹ���"<<endl; 
		}
		else
		{
			cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
		} 
	}
	system("pause");
	system("cls");
}  

//����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1  
int WorkerManager:: IsExist(int id)
{
	int index=-1;
	for(int i=0;i<this->EmpNum;i++)
	{
		if(this->EmpArray[i]->Id==id)
		{
			index=i;
			break;
		}
	} 
	return index;
}

//�޸�ְ��
void WorkerManager:: Mod_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		cout<<"�������޸�ְ���ı�ţ�"<<endl;
		int id;
		cin>>id;
		int ret=this->IsExist(id);
		if(ret!=-1)     //���ҵ���ŵ�ְ�� 
		{
			delete this->EmpArray[ret];
			int newId=0;
			string newName=" ";
			int dSelect=0;
			cout<<"�鵽 "<<id<<" ��ְ������������ְ����ţ�"<<endl;
			cin>>newId;
			cout<<"��������������"<<endl;
			cin>>newName;
			cout<<"�������λ��"<<endl;
			cout<<"1����ְͨ��"<<endl;
			cout<<"2������"<<endl;
			cout<<"3���ϰ�"<<endl;
			cin>>dSelect;
			
			Worker *worker=NULL;
			switch(dSelect)
			{
				case 1:
					worker=new Employee(newId,newName,dSelect);
					break;
				case 2:
					worker=new Manager(newId,newName,dSelect);
					break;
				case 3:
					worker=new Boss(newId,newName,dSelect);
					break;
				default:
					break;
			}
			this->EmpArray[ret]=worker;    //�������� ��������
			cout<<"�޸ĳɹ���"<<endl;
			this->save();     //���浽�ļ��� 
		}
		else  
		{
			cout<<"�޸�ʧ�ܣ����޴��ˣ�"<<endl;
		} 
	}
	system("pause");
	system("cls");
} 

//����ְ��
void WorkerManager::Find_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		cout<<"��������ҵķ�ʽ��"<<endl;
		cout<<"1����ְ����Ų���"<<endl;
		cout<<"2������������"<<endl;
		int select=0;
		cin>>select;
		if(select==1)
		{
			int id;
			cout<<"���������ְ���ı�ţ�"<<endl;
			cin>>id;
			int ret=IsExist(id);
			if(ret!=-1)
			{
				cout<<"���ҳɹ�����ְ����Ϣ���£�"<<endl;
				this->EmpArray[ret]->showInfo();
			}
			else
			{
				cout<<"����ʧ�ܣ����޴��ˣ�"<<endl;
			}
		}
		else if(select==2)   //����������
		{
			string name;
			cout<<"������Ҫ���ҵ�������"<<endl;
			cin>>name;
			bool flag=false;   //���ҵ��ı�־
			for(int i=0;i<EmpNum;i++)
			{
				if(EmpArray[i]->Name==name)
				{
					cout<<"���ҳɹ���ְ����ţ�"<<EmpArray[i]->Id<<"�ŵ���Ϣ���£�"<<endl;
					flag=true;
					this->EmpArray[i]->showInfo();
				}
			}
			if(flag==false)
			{
				cout<<"����ʧ�ܣ����޴���"<<endl;
			} 
		}
		else
		{
			cout<<"����ѡ������"<<endl;
		}		
	}
	system("pause");
	system("cls");
}

//����ְ�� 
void WorkerManager::Sort_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout<<"����������ķ�ʽ��"<<endl;
		cout<<"1����ְ����Ž�������"<<endl;
		cout<<"2����ְ����Ž��н���"<<endl;
		int select=0;
		cin>>select;
		for(int i=0;i<EmpNum;i++)
		{
			int minOrMax=i;
			for(int j=i+1;j<EmpNum;j++)
			{
				if(select==1)   //����
				{
					if(EmpArray[minOrMax]->Id > EmpArray[j]->Id)
					{
						minOrMax=j;
					}
				}
				else        //���� 
				{
					if(EmpArray[minOrMax]->Id < EmpArray[j]->Id)
					{
						minOrMax=j;
					}
				} 
			}
			if(i!=minOrMax)
			{
				Worker *temp=EmpArray[i];
				EmpArray[i]=EmpArray[minOrMax];
				EmpArray[minOrMax]=temp;
			}
		}
		cout<<"����ɹ��������Ľ��Ϊ��"<<endl;
		this->save();
		this->Show_Emp(); 
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout<<"ȷ����գ�"<<endl;
	cout<<"1��ȷ��"<<endl;
	cout<<"2������"<<endl;
	
	int select=0;
	cin>>select;
	if(select==1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		if(this->EmpArray!=NULL)
		{
			for(int i=0;i<this->EmpNum;i++)
			{
				if(this->EmpArray[i]!=NULL)
				{
					delete this->EmpArray[i];
				}
			}
			this->EmpNum=0;
			delete[] this->EmpArray;
			this->EmpArray=NULL;
			this->FileIsEmpty=true;
		}
		cout<<"��ճɹ���"<<endl;
	}
	system("pause");
	system("cls");
}
