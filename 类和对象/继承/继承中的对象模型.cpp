#include<iostream>
#include<string>
using namespace std;

 
class  Base
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;     //˽�г�Աֻ�Ǳ������� �����ǻ��ǻ�̳���ȥ  
};

//�����̳�
class son : public Base
{
	public:
		int D;
};

void test01()
{
	cout<<"sizeof son ="<<sizeof(son)<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
