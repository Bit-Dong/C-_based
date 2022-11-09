#ifndef __WORKMANAGER_H_
#define __WORKMANAGER_H_

#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;
class WorkerManager
{
	public:
		WorkerManager();
		~WorkerManager();
		
		void Show_Menu();     //չʾ�˵� 
		void ExitSystem();    //�˳�ϵͳ 
		void Add_Emp();       //���ְ�� 
		void save();         //�����ļ� 
		void init_Emp();     //��ʼ��Ա�� 
		void Show_Emp();     //��ʾְ��
		void Del_Emp();      //ɾ��ְ��
		int IsExist(int id);  //����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1 
		void Mod_Emp();      //�޸�ְ�� 
		void Find_Emp();     //����ְ�� 
		void Sort_Emp();     //����ְ�� 
		void Clean_File();   //����ļ� 
		
		int EmpNum;          //��¼ְ������ 
		Worker **EmpArray;   //ְ������ָ�� 
		bool FileIsEmpty;    //�ж��ļ��Ƿ�Ϊ�� ��־
		int get_EmpNum();    //ͳ���ļ������� 
		
};

#endif
 

