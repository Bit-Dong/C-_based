#ifndef __BOSS_H_
#define __BOSS_H_

#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//�ϰ��� 
class Boss :public Worker
{
	public:
		
		//���캯��
		Boss(int id,string name,int did);
		
		//��ʾ������Ϣ
		virtual void showInfo();
		
		//��ȡְ����λ����
		virtual string getDeptName();
		
};

#endif
 
