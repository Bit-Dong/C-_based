#include<iostream>
#include<string>

using namespace std;

class Building
{
	friend void goodGay(Building &build);   //���߱�����goodGayȫ�ֺ�����Building��ĺ����ѣ����Է������е�˽������
	
	public:
		Building()     //���캯�� 
		{
			sittingroom="����";
			bedroom="����";
		}
	public:
		string sittingroom;
	private:
		string bedroom;
}; 
void goodGay(Building &build)
{
	cout<<"�������ڷ��ʣ�"<<build.sittingroom<<endl;
	cout<<"�������ڷ��ʣ�"<<build.bedroom<<endl;
}

void text01()
{
	Building b;
	goodGay(b);
}

int main()
{
	text01();
		
	system("pause");
	return 0;
}
