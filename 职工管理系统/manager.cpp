#include "manager.h"

Manager::Manager(int id,string name,int did)
{
	this->Id=id;
	this->Name=name;
	this->DeptId=did;
	
}

void Manager::showInfo()
{
	cout<<"ְ����ţ�"<<this->Id<<"\tְ��������"<<this->Name<<"\t��λ��"<<this->getDeptName()<<"\t��λְ������ϰ彻�������񣬲��·������Ա��"<<endl;
}

string Manager::getDeptName()
{
	return string("����"); 
}
