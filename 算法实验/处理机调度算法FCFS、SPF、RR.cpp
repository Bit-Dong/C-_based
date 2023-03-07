#include<stdio.h>
#include<stdlib.h>
#define N 5     //������Ŀ
#define START 0 //������ʼʱ��

typedef struct{
    char pro_name;//������
    int arr_time;//����ʱ��
    int ser_time;//����ʱ��
    int com_time;//���ʱ��
    float tur_time;//��תʱ��
    float wei_time;//��Ȩ��תʱ��
    int flag;//���б�ǣ�0��ʾδ���У�1��ʾ������
    }pcb;//�������pcb����

    float mean_time;//ƽ����תʱ��
    float meanw_time;//ƽ����Ȩ��תʱ��
    int last_time;//ǰһ�����̽���ʱ��

    pcb* init();//��ʼ���������ʼ����
    void clear(pcb*);//���ǰһ��ʵ�������
    void output(pcb*);//������
    void FCFS(pcb*);
    void SPF(pcb*);
    void RR(pcb*);

int main()
{
    pcb* proc;
    int num;
    proc=init();
    printf("\n");
    printf("===============================================================\n");
    printf("numֵ��Ӧ������ţ�\n\n");
    printf("   num=0  ��������\n");
    printf("   num=1  FCFS�㷨\n");
    printf("   num=2  SPF�㷨\n");
    printf("   num=3  RR�㷨\n");
    printf("===============================================================\n");
    printf("\n");
    printf("ѡ��������(num)��");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
            case 0:printf("\n===����������===\n");return 0;
            case 1:printf("\n��FCFS�㷨��\n");FCFS(proc);break;
            case 2:printf("\n��SPF�㷨��\n");SPF(proc);break;
            case 3:printf("\n��RR�㷨��\n");RR(proc);
        }
        printf("\n");
        printf("===============================================================\n");
        printf("\n");
        printf("ѡ��������(num)��");
        scanf("%d",&num);
    }
}

pcb* init()
{
    pcb* p;
    int i;
    p=(pcb*)malloc(N*sizeof(pcb));
    printf("���̳�ʼ���ݣ�����,����ʱ��,����ʱ�䣩��\n");
    for(i=0;i<N;i++)
    {
        scanf("%c%d%d",&p[i].pro_name,&p[i].arr_time,&p[i].ser_time);
        getchar();
        p[i].flag=0;
        mean_time=0.0;
        meanw_time=0.0;
    }
    return p;
}

void output(pcb* p)
{
    int i;
    printf("������  ����ʱ��  ����ʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
    for(i=0;i<N;i++)
        printf("  %-8c%-10d%-10d%-10d%-10.0f%-10.1f\n",p[i].pro_name,p[i].arr_time,p[i].ser_time,p[i].com_time,p[i].tur_time,p[i].wei_time);
    printf("\n");
    printf("ƽ����תʱ�䣺%10.1f\n",mean_time);
    printf("ƽ����Ȩ��תʱ�䣺%6.1f",meanw_time);
}
void clear(pcb* p)
{
    int i;
    for(i=0;i<N;i++)
    {
        p[i].com_time=0;
        p[i].tur_time=0.0;
        p[i].wei_time=0.0;
        p[i].flag=0;
        mean_time=0.0;
        meanw_time=0.0;
    }
}

void FCFS(pcb* p)
{
    int i;
    clear(p);
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)
    {
        if(last_time>p[i].arr_time)p[i].com_time=last_time+p[i].ser_time;
        else p[i].com_time=p[i].arr_time+p[i].ser_time;
        p[i].tur_time=p[i].com_time-p[i].arr_time;
        p[i].wei_time=p[i].tur_time/p[i].ser_time;
        p[i].flag=1;
        mean_time=mean_time+p[i].tur_time;
        meanw_time=meanw_time+p[i].wei_time;
        last_time=p[i].com_time;
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}
void SPF(pcb* p)
{
    int i,j,k,shortp;//k��ʾ�̽��������±꣬shortp��ʾ�̽��̷���ʱ�� 
    clear(p);
    k=0;//ѡ�еĽ��̱��
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)
    {
        shortp=p[k].ser_time;
        for(j=0;j<N;j++)//����δ���е��ѵ��������������̽��̣����Ϊk
            if(p[j].flag==0&&p[j].arr_time<=last_time&&p[j].ser_time<shortp)
            {
                k=j;
                shortp=p[k].ser_time;
            }
        if(p[k].arr_time<last_time)p[k].com_time=last_time+p[k].ser_time;
        else p[k].com_time=p[i].arr_time+p[k].ser_time;
        p[k].tur_time=p[k].com_time-p[k].arr_time;
        p[k].wei_time=p[k].tur_time/p[k].ser_time;
        p[k].flag=1;
        mean_time=mean_time+p[k].tur_time;
        meanw_time=meanw_time+p[k].wei_time;
        last_time=p[k].com_time;
        for(j=0;j<N;j++)//��ʣ�����δ���еĽ����в��ҵ�һ�������Ϊk
            if(p[j].flag==0)break;
        k=j;
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}
void RR(pcb* p)
{
    int i,j,k=0;//k��ʾ����ɽ�������j��¼�������
    int quantum;//ʱ��Ƭ��С
    int rrtime[N];//��¼����ʣ��ʱ�䣬rrtime[i]=0ʱ����p[i]����
    int flagrr;
    clear(p);
    printf("ʱ��Ƭ��Сquantum��");
    scanf("%d",&quantum);
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)//���̷���ʱ����Ϊrrtime��ֵ
        rrtime[i]=p[i].ser_time;
    flagrr=1;
    j=0;
    while(k<N)
    {
        i=0;
        if(flagrr==0)
        {
            i=j;
            last_time=p[i].arr_time;
        }
        flagrr=0;
        while(i<N&&p[i].arr_time<=last_time)
        {//���ѵ�����Ϊ������ϵĽ�����rrtime��ӦԪ�ؼ�ȥһ��ʱ��Ƭ
            if(p[i].flag==0)
            {
                flagrr=1;
                rrtime[i]=rrtime[i]-quantum;
                last_time=last_time+quantum;
                if(rrtime[i]<=0)
                {
                    last_time=last_time+rrtime[i];
                    p[i].com_time=last_time;
                    p[i].tur_time=p[i].com_time-p[i].arr_time;
                    p[i].wei_time=p[i].tur_time/p[i].ser_time;
                    p[i].flag=1;
                    mean_time=mean_time+p[i].tur_time;
                    meanw_time=meanw_time+p[i].wei_time;
                    k++;
                    if(k>=N)break;
                }
            }
            i++;
            if(i>j)j=i;
        }
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}



//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 5     //������Ŀ
//#define START 0 //������ʼʱ��
//
//typedef struct{
//    char pro_name;//������
//    int arr_time;//����ʱ��
//    int ser_time;//����ʱ��
//    int com_time;//���ʱ��
//    float tur_time;//��תʱ��
//    float wei_time;//��Ȩ��תʱ��
//    int flag;//���б�ǣ�0��ʾδ���У�1��ʾ������
//    }pcb;//�������pcb����
//
//    float mean_time;//ƽ����תʱ��
//    float meanw_time;//ƽ����Ȩ��תʱ��
//    int last_time;//ǰһ�����̽���ʱ��
//
//    pcb* init();//��ʼ���������ʼ����
//    void output(pcb*);//������
//    void FCFS(pcb*);
//
//int main()
//{
//    pcb* proc;
//proc=init();
//FCFS(proc);
// }
//
//pcb* init()
//{
//    pcb* p;
//    int i;
//    p=(pcb*)malloc(N*sizeof(pcb));
//    printf("���̳�ʼ���ݣ����� ����ʱ�� ����ʱ�䣩��\n");
//    for(i=0;i<N;i++)
//    {
//        scanf("%c%d%d",&p[i].pro_name,&p[i].arr_time,&p[i].ser_time);
//        getchar();
//        p[i].flag=0;
//        mean_time=0.0;
//        meanw_time=0.0;
//    }
//    return p;
//}
//
//void output(pcb* p)
//{
//    int i;
//    printf("������  ����ʱ��  ����ʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
//    for(i=0;i<N;i++)
//        printf("  %-8c%-10d%-10d%-10d%-10.0f%-10.1f\n",p[i].pro_name,p[i].arr_time,p[i].ser_time,p[i].com_time,p[i].tur_time,p[i].wei_time);
//    printf("\n");
//    printf("ƽ����תʱ�䣺%10.1f\n",mean_time);
//    printf("ƽ����Ȩ��תʱ�䣺%6.1f",meanw_time);
//}
//
//void FCFS(pcb* p)
//{
//    int i;
//    last_time=START;
//    mean_time=0.0;
//    for(i=0;i<N;i++)
//    {
//        if(last_time>p[i].arr_time)p[i].com_time=last_time+p[i].ser_time;
//        else p[i].com_time=p[i].arr_time+p[i].ser_time;
//        p[i].tur_time=p[i].com_time-p[i].arr_time;
//        p[i].wei_time=p[i].tur_time/p[i].ser_time;
//        p[i].flag=1;
//        mean_time=mean_time+p[i].tur_time;
//        meanw_time=meanw_time+p[i].wei_time;
//        last_time=p[i].com_time;
//    }
//    mean_time=mean_time/N;
//    meanw_time=meanw_time/N;
//    output(p);
//}
