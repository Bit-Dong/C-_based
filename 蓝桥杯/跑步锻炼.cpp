/*
��Ŀ����:
С��ÿ�춼�������塣��������£�С��ÿ����1ǧ�ס����ĳ������һ�����³���1�գ���Ϊ�˼����Լ���С��Ҫ��2ǧ�ס�
���ͬʱ����һ���³���С��Ҳ����2ǧ�ס�С���ܲ��Ѿ�����˺ܳ�ʱ�䣬��2000��1��1��������������2020��10��1�����ģ�������
�������ʱ��С���ܹ��ܲ�����ǧ�ף�

��Ŀ����:
��������ܵ����������·�����Ȼ�����һ���ж��ٸ���һ������һ��Ϊ�·ݵ�����
���������+��һ����+�³����� - ��һ���³��غ�����
*/

#include<iostream>
using namespace std;

int panduan(int a){
	if((a%4==0&&a%100!=0)||a%400==0)  return 1;
	else return 0;
}

int main(){
	int sum=0;
	int monthes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int mon=6;  //���ڼ� 
	for(int year=2000;year<=2020;year++){
		if(panduan(year)) monthes[2]=29;
		else monthes[2]=28;
		for(int month=1;month<=12;month++){
			for(int day=1;day<=monthes[month];day++){
				if(mon==8) mon=1;
				
				if(mon==1&&day==1){
					sum+=2;
				}
				else if(mon==1||day==1){
					sum+=2;
				}
				else sum+=1;
				
				if(year==2020&&month==10&&day==1) {
					cout<<sum;
					return 0;
				}
				mon++;				
			}
			
		}
		
	}
}
