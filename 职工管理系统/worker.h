#ifndef __WORKER_H_
#define __WORKER_H_

#include<iostream>
#include<string>

using namespace std;
class Worker
{
	public:
		virtual void showInfo()=0;        //��ʾ������Ϣ 
		virtual string getDeptName()=0;   //��ȡ��λ���� 
		
		int Id;        //ְ����� 
		string Name;   //ְ������ 
		int DeptId;    //ְ�����ڲ������Ʊ�� 
};

#endif
 
