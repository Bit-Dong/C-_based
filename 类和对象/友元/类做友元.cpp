#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend class GoodGay;   //���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������

	public:
		Building();
	    string sittingroom;
	private:
		string bedroom;
};

class GoodGay
{
	public:
		GoodGay();
		void vivst();
	private:
		Building *build;
};

Building::Building()
{
	sittingroom="����";
	bedroom="����"; 
}

void GoodGay::vivst()
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
	gg.vivst(); 
}

int main()
{
	
	test01();
	system("pause");
	return 0;
}
