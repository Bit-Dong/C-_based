#ifndef __MANAGER_H_
#define __MANAGER_H_

#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//������ 
class Manager :public Worker
{
	public:
		
		//���캯��
		Manager(int id,string name,int did);
		
		//��ʾ������Ϣ
		virtual void showInfo();
		
		//��ȡְ����λ����
		virtual string getDeptName();
		
};

#endif
 
