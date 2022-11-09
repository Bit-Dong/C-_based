#include<iostream>
#include<string>
#include<algorithm> 
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

//������ѡ��ABCDE  10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣�ȡƽ���� 

//ѡ���� 
class Person
{
	public:
		Person(string name,int score)
		{
			this->Name=name;
			this->Score=score;
		}
		
		string Name;   //���� 
		int Score;    //ƽ���� 
};

// 1����������ѡ��
void creatPerson(vector<Person> &v)
{
	string nameSeed="ABCDE";
	for(int i=0;i<5;i++)
	{
		string name="ѡ��";
		name+=nameSeed[i];
		int score=0;
		Person p(name,score);
		v.push_back(p);    //��������Person�����ŵ������� 
	}
}

//2��������ѡ�ִ��
void setScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		//����ί�ķ��� �ŵ�deque������
		deque<int>d;
		for(int i=0;i<10;i++)
		{
			int score=rand()%41+60;    //60-100
			d.push_back(score);
		}
		
		//����
		sort(d.begin(),d.end()); 
		
		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();
		
		//ȡƽ����
		int sum=0;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			sum+=*dit;      //�ۼ�ÿ����ί�ķ��� 
		} 
		int avg=sum/d.size();
		
		//��ƽ���� ��ֵ��ѡ������
		it->Score=avg; 
	}
}

// 3����ʾ���÷�
void showScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<"������"<<it->Name<<"   ƽ���֣�"<<it->Score<<endl;
	}
}



int main()
{
	//���������
	srand((unsigned int)time(NULL));
	
	// 1����������ѡ�� 
	vector<Person> v;   //���ѡ������
	creatPerson(v); 
	

	// 2��������ѡ�ִ��
	setScore(v);
	
	
	// 3����ʾ���÷� 
	showScore(v);
	
	system("pause");
	return 0;
}
