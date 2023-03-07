/*
��������������дһ��ʵ����򣬶���һ����n(n>1)��Ԫ�ص�queue<int>��������qu��
 			���ӴӶ�ͷ����β�ĵ�k(1<=k<=n)��Ԫ�أ���������Ԫ�ز��䡣
*/

#include<iostream>
#include<queue>
using namespace std;
char solve(queue<char> &qu,int k)
{
    queue<char> temp;
    char e;
    for(int i=0;i<k-1;i++)
    {
        temp.push(qu.front());
        qu.pop();
    }
    e=qu.front();
    qu.pop();
    while(!qu.empty())
    {
        temp.push(qu.front());
        qu.pop();
    }
    qu=temp;
    return e;
}
int main()
{
    queue<char> qu;
    qu.push('a');
    qu.push('b');
    qu.push('c');
    qu.push('d');
    int k=3;
    char e=solve(qu,k);
    cout<<"����Ԫ����"<<e<<endl;
    cout<<"����˳����:";
    while(!qu.empty())
    {
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
    return 0;
}
