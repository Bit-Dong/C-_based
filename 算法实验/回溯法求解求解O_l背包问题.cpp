#include <iostream>
using namespace std;
#define MAXN 20

//�����ʾ
int n=4;			//4����Ʒ
int W=6;			//��������Ϊ6
int w[]={0,5,3,2,1};		//���4����Ʒ����,�����±�0Ԫ��
int v[]={0,4,4,3,1};		//���4����Ʒ��ֵ,�����±�0Ԫ��
//�������ʾ
int x[MAXN];			//������ս�
int maxv; 			//������Ž���ܼ�ֵ

void dfs(int i,int tw,int tv,int rw,int op[])
{  if (i>n)				//�ҵ�һ��Ҷ�ӽ��
   {  if (tw==W && tv>maxv)		//�ҵ�һ�����������ĸ��Ž�,����
      {  maxv=tv;
         for (int j=1;j<=n;j++)
            x[j]=op[j];
      }
   }
   else					//��δ����������Ʒ
   {
       if ( tw+w[i]<=W )		//���ӽ���֦
      {  op[i]=1;			//ѡȡ��i����Ʒ
         dfs(i+1,tw+w[i],tv+v[i],rw-w[i],op);
      }

      if (  tw+rw-w[i]>=W )  //�Һ��ӽ���֦
      {  op[i]=0;			 //��ѡȡ��i����Ʒ,����
          dfs(i+1,tw,tv,rw-w[i],op);
      }

   }
}

int main()
{
    int op[MAXN];
    dfs(1,0,0,11,op);
    cout<<"����ֵ�ǣ�"<<maxv<<endl;
    for(int j=1;j<=n;j++)
        cout<<x[j]<<" ";

}
