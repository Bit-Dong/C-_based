#include<iostream>
#include<string>
using namespace std;

class Animal
{
	public:
		int A;
};

//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
//��ʱ�����ĸ���Animal��Ϊ�����
class Sheep : virtual public Animal{}; 
class Tuo : virtual public Animal{}; 
class SheepTuo : public Sheep,public Tuo{};

void test01()
{
	SheepTuo st;
	st.Sheep::A=100;
	st.Tuo::A=200;
	
	cout<<"st.Sheep::A = "<<st.Sheep::A<<endl;
	cout<<"st.Tuo::A = "<<st.Tuo::A<<endl;
	cout<<"st.A =  "<<st.A<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
