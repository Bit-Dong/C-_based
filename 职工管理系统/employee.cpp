#include "employee.h"

Employee::Employee(int id,string name,int did)
{
	this->Id=id;
	this->Name=name;
	this->DeptId=did;
}

void Employee::showInfo()
{
	cout<<"ְ����ţ�"<<this->Id<<"\tְ��������"<<this->Name<<"\t��λ��"<<this->getDeptName()<<"\t��λְ����ɾ�����������"<<endl; 
}

string Employee::getDeptName()
{
	return string("Ա��");
}
