/*
��������������дһ��ʵ�����ʵ�����ɾ�����⡣��������nλ��������d��
			ȥ����������,k<=n�����ֺ�ʣ�µ����ְ�ԭ�����������һ���µ���������
			���ڸ�����nλ������d��������k���ҳ�ʣ��������ɵ�������С��ɾ��������
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string N;
    int k,i;
    cin >> N >> k;
    while (k--)
    {
        int len=N.length();
        for (i=0;i<len-1;i++)
            if (N[i]>N[i+1])
            {
                N.erase(N.begin()+i);
                break;
            }
        if (i==len-1)
            N.erase(N.end()-1);	 //ɾ���������
    }
    while(N[0]=='0'&&N.length()>1)
        N.erase(N.begin());
    cout << N << endl;
	return 0;
}
