#include<iostream>
#include<string>
using namespace std;

class Building; 
class GoodGay
{
	public:
		GoodGay();
		void visit();
	private:
		Building *build;
};

class Building
{
	friend void GoodGay::visit();    //���߱�����goodGay���е�visit��Ա������Building�����ѣ����Է���˽������
	public:
		Building();
	    string sittingroom;
	private:
		string bedroom;
};



Building::Building()
{
	sittingroom="����";
	bedroom="����"; 
}

void GoodGay::visit()
{
	cout<<"�û������ڷ��ʣ�"<<build->sittingroom <<endl;
	cout<<"�û������ڷ��ʣ�"<<build->bedroom<<endl;	
}

GoodGay::GoodGay()
{
	build=new Building;
}

void test01()
{
	GoodGay gg;
	gg.visit(); 
}

int main()
{
	
	test01();
	system("pause");
	return 0;
}
