/*
��������������дһ��ʵ����򣬲��û��ݷ������Ȼ��1~n����ȡr������������ϡ�
*/
#include <iostream>
#include <vector>
using namespace std;
int n,r;
void disp(vector<int> path)
{
    for(int j=0;j<path.size();j++)
        cout<<path[j]<<" ";
    cout<<endl;
}
void dfs(vector<int> path,int i,int num)
{
    if(num==r)
        disp(path);
    for(int j=i;j<=n;j++)
    {
        path.push_back(j);
        dfs(path,j+1,num+1);
        path.pop_back();
    }
}
int main()
{
   cin>>n>>r;
   vector<int> path;
   dfs(path,1,0);
   return 0;
}
