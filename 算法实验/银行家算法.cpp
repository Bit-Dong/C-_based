#include<stdio.h>
#include<string.h>
#define PN 5//������
#define RN 4//��Դ������

typedef struct//����ṹ������pcb
{
    char name[3];//����������p0
    int max[RN];//�����Դֵ
    int allocation[RN];//�ѷ�����Դ��
    int need[RN];//��������Դ��
}pcb;

struct//����Ϊ�ṹ�����ͣ����㸳ֵ
{
    int flag[PN];//���̼���־��1ʱ��ʾ��ͨ��
    int safes[PN];//��Ž��̱�ţ���Ϊ��ȫ�������
}fs0,fs;//fs0�����ʼֵ��fs���ڹ���

struct//����Ϊ�ṹ�����ͣ����㸳ֵ
{
    int available[RN];//ϵͳ������Դ����
}av0,av,avx;//av0�����ʼֵ��av��avx���ڹ���

pcb proc0[PN],proc[PN];//proc0�����ʼֵ��proc���ڹ���
int request[RN];//����������Դ����

void init();//��ʼ������������
void output(pcb*);//�������
void cur_state();//�ж�ϵͳ��ǰ״̬
void req_state();//������������������Ƿ������Ӧ
void back0();//�˻�����ʼֵ
void back1(int);//�˻�������ǰ
int check(int*);//����need������available�����Ƚ�
int banker();//���м��㷨

int main()
{
int num;
printf("�����м��㷨��\n");
printf("��������%d\n",PN);
printf("��Դ����%d\n",RN);
printf("=================\n");
    init();
    output(proc0);//�����ʼ��Դ�������
    printf("��ϵͳ��ǰ״̬������\n");
    cur_state();
    printf("======================================================\n\n");
    printf("ѡ��������(0:��������1:��Դ�������)\n");
    printf("������ţ�");
    scanf("%d",&num);getchar();
    while(1)
    {
        switch(num)
        {
            case 1:printf("\n��������Դ���������\n");req_state();break;
            default:printf("\n======����������======\n");return 0;
        }
        printf("\n");
        printf("======================================================\n");
        printf("\n");
        printf("ѡ��������(0:��������1:��Դ�������)\n");
        printf("������ţ�");
        scanf("%d",&num);getchar();
    }
}

void init()
{//��ʼ��
int i,j;
    for(i=0;i<PN;i++)
    {
        printf("\n�����������");
        gets(proc0[i].name);
        printf("����max��");
        for(j=0;j<RN;j++)
            scanf("%d",&proc0[i].max[j]);
        printf("����allocation��");
        for(j=0;j<RN;j++)
            scanf("%d",&proc0[i].allocation[j]);
        for(j=0;j<RN;j++)//����need
            proc0[i].need[j]=proc0[i].max[j]-proc0[i].allocation[j];
        fs0.flag[i]=0;//���̱�־λ��0
        fs0.safes[i]=-1;//��ȫ������-1
        proc[i]=proc0[i];//����������proc��ֵ
        getchar();//����scanf()�����Ļس���
    }
    printf("\n����available��");
    for(j=0;j<RN;j++)
        scanf("%d",&av0.available[j]);
    fs=fs0;//��������Ԫfs��av��ֵ
    av=av0;
    getchar();//����scanf()�����Ļس���
}

void output(pcb* p)
{//�����Դ��������������鷳���Բ�����
    int i,j;
    printf("\n");
    printf("===============================================================================\n");
    printf(" ��־λ | ������ |  ���ֵ \t|  �ѷ��� \t|  ����ֵ \t|  ������ \n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<PN;i++)
    {
        printf("   %-5d",fs.flag[i]);
        printf("|");
        printf("   %-5s",p[i].name);
        printf("| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].max[j]);
        printf("\t| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].allocation[j]);
        printf("\t| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].need[j]);
        printf("\t| ");
        if(i==0)
            for(j=0;j<RN;j++)
                printf("%-3d",av.available[j]);
        printf("\n");
    }
    printf("===============================================================================\n\n");
}

int banker()
{//���м��㷨
    int i,j,t=0,k,f;
    k=0;//���������ҵ����������Ľ�����
    f=1;//��־λ��ÿ�ֲ��ұ�־��f=0ʱ����δ�ҵ����ʽ��̣����ҽ���
    while(f==1&&k<PN)
    {
        f=0;//���ֲ��ұ�־��0
        for(i=0;i<PN;i++)
            if(!fs.flag[i]&&check(proc[i].need))
            {//�ҵ����������Ľ���
                f=1;//���ֲ��ұ�־��1
                fs.flag[i]=1;//���̱�־��1
                for(j=0;j<RN;j++)//�޸�available�е�ֵ
                    av.available[j]+=proc[i].allocation[j];
                fs.safes[t]=i;//�������i����safes�����У���Ϊ��ȫ�������
                t++;k++;
            }
    }
    if(k<PN)return 0;//��k<PNʱ˵�������ڰ�ȫ���У�����0
    else return 1;
}

int check(int* p)//pΪ��ǰ���̵�need����
{//��ǰ����need������available�����Ƚ�
    int i;
    for(i=0;i<RN;i++)
        if(p[i]>av.available[i])return 0;//����ⲻͨ���򷵻�0
    return 1;//���ͨ��
}

void cur_state()
{//���ϵͳ��ǰ״̬
    int i;
    if(banker())
    {
        printf("�����������ǰϵͳ���ڰ�ȫ״̬�����ڰ�ȫ���� ");
        for(i=0;i<PN;i++)//�����ȫ����
            printf("p%d",fs.safes[i]);
        printf("\n");
    }
    else
        printf("�����������ǰϵͳ���ڲ���ȫ״̬�����������");
    //output(proc);//����������״̬���鿴flag��available״����
    fs=fs0;av=av0;//�˻�����ʼ״̬
    printf("\n\n");
}

void req_state()
{//�Խ����������Դ�����жϷ���Ŀ�����
    int i,j,n;
    printf("�����������Ľ������n��p");
    scanf("%d",&n);
    printf("����������Դ����request��");
    for(i=0;i<RN;i++)
        scanf("%d",&request[i]);
    for(i=0;i<RN;i++)//�ж�����ĺϷ���
        if(request[i]>proc[n].need[i]||request[i]>av.available[i])
        {
            printf("������������󲻺Ϸ���ϵͳ������Ӧ��");
            for(j=0;j<RN;j++)
                request[j]=0;//���request
            return;
        }

    for(i=0;i<RN;i++)
    {//���Է��䣬�޸�allocation,need��available��ֵ
        av.available[i]-=request[i];
        proc[n].need[i]-=request[i];
        proc[n].allocation[i]+=request[i];

    }
    avx=av;//avx��������available��ֵ
    //output(proc);//�����������Դ�ֲ�״��
    if(banker())//�������м��㷨��Ѱ�Ұ�ȫ����
    {
        printf("�����������ǰϵͳ���ڰ�ȫ״̬�����ڰ�ȫ���� ");
        for(i=0;i<PN;i++)//�����ȫ����
            printf("p%d ",fs.safes[i]);
        printf("\n");
        av=avx;//����������ȷ����Դ����
        fs=fs0;//��ձ�ʶλflag�Ͱ�ȫ����safes
    }
    else
    {
        printf("��������������ڰ�ȫ���У�ϵͳ������Ӧ������������\n");
        //output(proc);//��������������������鿴flag��available״����
        back1(n);//ȡ�����䣬�˻�������ǰ
        printf("��ȡ�����䣬�˻�������ǰ\n");
    }
    printf("\n\n");
    printf("���롰y�����˻ص���ʼ״̬����ѡ��(y/n)\n");
    printf("�����룺");
    getchar();//����ǰ��������������Ļس���
    if(getchar()=='y')
    {
        back0();
        printf("���˻�����ʼ״̬\n");
    }
}

void back0()
{//�ָ�����ʼֵ
    int i;
    fs=fs0;
    av=av0;
    for(i=0;i<PN;i++)
        proc[i]=proc0[i];
}

void back1(int m)//mΪ�����Դ����Ľ������
{//�������䣬�˻�������ǰ
    int i;
    fs=fs0;
    for(i=0;i<RN;i++)
    {
        av.available[i]=avx.available[i]-request[i];
        proc[m].need[i]+=request[i];
        proc[m].allocation[i]-=request[i];
    }
}

