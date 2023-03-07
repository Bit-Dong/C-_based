/*
��������������n��n�ķ��������ϣ�����n���ʺ�Ҫ��ÿ���ʺ�ͬ�С���ͬ�С���ͬ���ҶԽ��ߡ�
			��ͼ1��ʾ��6�ʺ������һ���⡣Ҫ����ö���ʽ��֦�޽編���4�ʺ������һ���⣬
			��������Ӧ���������д����Ķ��н��ĸ�����
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath> 
using namespace std;
int n=4;
int Count=1;
struct  NodeType
{
    int no;
    int row;
    vector<int> cols;
};
void dispnode(NodeType e)
{
    if(e.row!=-1)
        cout<<"���"<<e.no<<"��Ӧλ���ǣ�"<<e.row<<","<<e.cols[e.row]<<endl;
    else
        cout<<"���"<<e.no<<"��Ӧλ���ǣ�"<<e.row<<","<<"*"<<endl;
}
bool Valid(vector <int> cols,int i,int j)
{
    int k=0;
    while(k<i)
    {
        if((cols[k]==j)||(abs(cols[k]-j)==abs(k-i)))  return false;
        k++;
    }
    return true;
}
void solve()
{
    int i,j;
    NodeType e,el;
    queue<NodeType> qu;
    e.no=Count++;
    e.row=-1;
    qu.push(e);
    cout<<"����:";
    dispnode(e);
    while(!qu.empty())
    {
        e=qu.front();qu.pop();
        cout<<"����";
        dispnode(e);
        if(e.row==n-1)
        {
            cout<<"����һ����:";
            for(int i=0;i<n;      i++)
            {
                cout<<i+1<<","<<e.cols[i]+1<<" ";
            }
            cout<<endl;
            return ;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                i=e.row+1;
                if(Valid(e.cols,i,j))
                {
                    el.no=Count++;
                    el.row=i;
                    el.cols=e.cols;
                    el.cols.push_back(j);
                    qu.push(el);
                    cout<<"�����ӽ��:";
                    dispnode(el);
                }
            }
        }
    }
}
int main()
{
   solve();
   return 0;
}
