#include<stdio.h>
#include<stdlib.h>
#define PN 12//ҳ������г���
#define FN 3//��������̵��ڴ����

int *pageSeq;//ҳ���������
int *frames;//�ڴ������
int fault,exchange;//ȱҳ�������û�����
float ratio;//ȱҳ��

void init();//��ʼ��ҳ���������
void clear();//��ʼ���ڴ��
void print();//��������
void print1(int);//���ÿһ�����
void OPT(int*,int,int*,int);//OPT�㷨
void FIFO(int*,int,int*,int);//FIFO�㷨
void LRU(int*,int,int*,int);//LRU�㷨
int search(int,int*,int,int);//����ҳ��������ĳ���е�λ�ã��ҵ������±꣬���򷵻�-1

int main()
{
int num;
printf("��ҳ���û��㷨��\n");
printf("���г��ȣ�%d\n",PN);
printf("�ڴ������%d\n",FN);
printf("======================\n\n");
    init();//��ʼ��ҳ���������
    printf("����˵����\n");
    printf("    num=0  �������\n");
    printf("    num=1  OPT�㷨\n");
    printf("    num=2  FIFO�㷨\n");
    printf("    num=3  LRU�㷨\n");
    printf("==============================\n");
    printf("\n");
    printf("����������num��");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
            case 0:printf("\n=====���������=====\n");return 0;
            case 1:printf("\n��OPT�㷨��\n");OPT(pageSeq,PN,frames,FN);break;
            case 2:printf("\n��FIFO�㷨��\n");FIFO(pageSeq,PN,frames,FN);break;
            case 3:printf("\n��LRU�㷨��\n");LRU(pageSeq,PN,frames,FN);break;
            default:printf("\n=====��������=====\n");goto L1;
        }
        print();
L1:     printf("\n");
        printf("����������num��");
        scanf("%d",&num);
    }
}

void init()//�����������
{
    int i;
    pageSeq=(int*)(malloc(PN*sizeof(int)));
    frames=(int*)(malloc(FN*sizeof(int)));
    printf("��pageSeq����ҳ��������У�");
    for(i=0;i<PN;i++)
        scanf("%d",&pageSeq[i]);
    printf("\n");
    printf("ҳ��������У�\n\n");//���ҳ���������
    for(i=0;i<PN;i++)
        printf("%3d",pageSeq[i]);
    printf("\n\n");
    printf("===============================================================\n");
}

void clear()//���³�ʼ���ڴ��frames����Ϊ��0��ҳ�棬������-1
{
    int i;
    fault=0;//ȱҳ����
    exchange=0;//�û�����
    for(i=0;i<FN;i++)//�ڴ����-1
        frames[i]=-1;
}

void print1(int flag)//flagΪȱҳ��־�����ÿһ�����
{
    int t;
    for(t=0;t<FN;t++)//ÿ����һ��ҳ�棬�����һ���ڴ�飨ҳ�棩
        printf("%3d",frames[t]);
    if(flag) printf("  fault");//��ȱҳλ�ñ�ǡ�fault��
    printf("\n");
}

void print()//��������
{
    exchange=fault-FN;
    ratio=(float)fault/PN*100;
    printf("------------------------------\n");
    printf("ȱҳ������%d\n",fault);
    printf("�û�������%d\n",exchange);
    printf("ȱ ҳ �ʣ�%4.1f%%\n",ratio);
    printf("==============================\n");
}

int search(int p,int* ar,int start,int end)//����˵����(ҳ�ţ�ҳ��������л����ڴ�����飬��㣬�յ�)
{//���ҳ��p�Ƿ��������ar��(���start���յ�end)�������򷵻�����ar�е�λ��(�±�)�����򷵻�-1
    int i,f;
    if(start>end)f=-1;//f��Ϊ�����־��f=1ʱ��ѭ������������f=-1ʱ��ѭ�������ݼ�
    else f=1;
    i=start;//��stratλ�ÿ�ʼ����
    while(i!=end+f)//i����endʱ����ѭ��
    {//��OPT�㷨�У�start<end��ѭ������������f=1������LRU�㷨�����෴��f=-1
        if(p==ar[i])return i;//�״�������p�������±�
        i=i+f;
    }
    return -1;//δ������ҳ��p����p��δ�����ٱ�����
}

void OPT(int* arp,int p,int* arf,int f)
{//����˵����(ҳ������������飬���鳤�ȣ��ڴ�����飬���鳤��)
    int i=0,j,flag;
    int kf=0;//kfΪ�����ڴ�ҳ��������kf>=fʱ���ڴ��������ʱȱҳ�����û�����kf��ֵ��������
    int kp;//������㣬��ҳ����������е�ǰҳ����һλ��
    int posi,pmaxi,pmaxj;//δ����ò�ʹ��ҳ����arp��arf�е�λ��
    clear();//�ڴ����������
    printf("ҳ����ʹ��̣�\n");
    printf("------------------------------\n");
    for(i=0;i<p;i++)//ɨ��ҳ������
    {
        flag=0;//ȱҳ��־����ֵ��0����ȱҳ
        if(search(arp[i],arf,0,f-1)==-1)//ҳ�����ڴ�
        {
            flag=1;//ȱҳ��flag��1
            fault++;//ȱҳ+1
            if(kf<f)//�п����ڴ�飬���û�
            {
                arf[kf]=arp[i];//ҳ��ֱ�ӵ����ڴ��arf[kf]��
                kf++;//���ڴ�����ҳ���kf��������
            }
            else//û�п����ڴ�飬�������û�
            {
               kp=i+1; //����ҳ���������arp�������������㣬ѡ����̭ҳ��
               pmaxi=-1;//����̭ҳ���ڷ�������arp�е�λ�ã���ֵ��-1
               for(j=0;j<f;j++)
               {//���ڴ�arf�е�ÿ��ҳ�����β������ڷ�������arp�У�δ������һ�γ��ֵ�λ�ã��������posi��
                   posi=search(arf[j],arp,kp,p-1);
                   if(posi==-1)//search()����-1��˵����ҳ����δ�������ڣ��������ٱ����ʵ�
                   {
                       arf[j]=arp[i];//�û�����ֹѭ��
                       break;
                   }
                   if(posi>pmaxi)
                   {//search()����ֵ����-1�����¼���δʹ��ҳ���ڷ�������arp�е�λ��
                       pmaxi=posi;//��¼���λ��
                       pmaxj=j;//��¼���δʹ��ҳ�����ڴ�arf�е�λ��
                   }
               }
               if(j>=f)arf[pmaxj]=arp[i];//���ڴ������arf������ҳ����δ�����ᱻ���ʵ�ʱ���û�
            }
        }
        print1(flag);//���һ���ڴ�ҳ�����
    }
}

void FIFO(int* arp,int p,int* arf,int f)
{//����˵����(ҳ������������飬���鳤�ȣ��ڴ�����飬���鳤��)
    int i,j=0,flag;
    clear();//�ڴ����������
    printf("ҳ����ʹ��̣�\n");
    printf("------------------------------\n");
    for(i=0;i<p;i++)
    {
        flag=0;//ȱҳ��־��ͬOPT
        if(search(arp[i],arf,0,f-1)==-1)//�����ǰҳ��arp[i]�����ڴ�
        {
            fault++;//ȱҳ+1
            flag=1;
            arf[j]=arp[i];//ҳ������ڴ�
            j=(j+1)%f;//j+1��ѭ��
        }
        print1(flag);//���һ���ڴ�ҳ�����
    }
}

void LRU(int* arp,int p,int* arf,int f)
{//����˵����(ҳ������������飬���鳤�ȣ��ڴ�����飬���鳤��)
    int i,j;
    int kf=0;//kf>=fʱ���ڴ��������ʱȱҳ�����û�
    int flag;//ȱҳ��־
    int pmini,pminj;//���δ����ҳ����arp[]�й�ȥ��λ�ú���arf[]�е�λ��
    int posi;
    clear();//�����ڴ�����ݵ�
    for(i=0;i<p;i++)
    {
        flag=0;
        if(search(arp[i],arf,0,f-1)==-1)//ҳ�治���ڴ�
        {
            flag=1;
            fault++;//ȱҳ
            if(kf<f)//�п��п飬���û�
            {
                arf[kf]=arp[i];
                kf++;
            }
            else//�޿��п飬�����û�
            {//��arp[]����ǰ������Ѱ�����δ�����ʵ�ҳ��λ��
                pmini=p;//pminiֵ��ֵ�����ֵ���ߵ�ǰֵi��
                for(j=0;j<f;j++)
                {
                    posi=search(arf[j],arp,i-1,0);//������OPT��ͬ���������ҳ�治���ڵ����
                    if(posi<pmini)
                    {
                        pmini=posi;
                        pminj=j;
                    }
                }
                arf[pminj]=arp[i];//�û�
            }
        }
        print1(flag);//���һ���ڴ�ҳ�����
    }
}




//
//#include<stdio.h>
//#include<stdlib.h>
//#define PN 20//ҳ������г���
//#define FN 3//��������̵��ڴ����
//
//int *pageSeq;//ҳ���������
//int *frames;//�ڴ������
//int fault,exchange;//ȱҳ�������û�����
//float ratio;//ȱҳ��
//
//void init();//��ʼ��ҳ���������
//void clear();//��ʼ���ڴ��
//void print();//��������
//void print1(int);//���ÿһ�����
//void LRU(int*,int,int*,int);//LRU�㷨
//int search(int,int*,int,int);//����ҳ��������ĳ���е�λ�ã��ҵ������±꣬���򷵻�-1
//
//int main()
//{
//int num;
//printf("��ҳ���û�LRU�㷨��\n");
//printf("���г��ȣ�%d\n",PN);
//printf("�ڴ������%d\n",FN);
//printf("======================\n\n");
//    init();//��ʼ��ҳ���������
//
//     LRU(pageSeq,PN,frames,FN);
//     print(); 
//}
//
//void init()//�����������
//{
//    int i;
//    pageSeq=(int*)(malloc(PN*sizeof(int)));
//    frames=(int*)(malloc(FN*sizeof(int)));
//    printf("��pageSeq����ҳ��������У�");
//    for(i=0;i<PN;i++)
//        scanf("%d",&pageSeq[i]);
//    printf("\n");
//    printf("ҳ��������У�\n\n");//���ҳ���������
//    for(i=0;i<PN;i++)
//        printf("%3d",pageSeq[i]);
//    printf("\n\n");
//    printf("===============================================================\n");
//}
//
//void clear()//���³�ʼ���ڴ��frames����Ϊ��0��ҳ�棬������-1
//{
//    int i;
//    fault=0;//ȱҳ����
//    exchange=0;//�û�����
//    for(i=0;i<FN;i++)//�ڴ����-1
//        frames[i]=-1;
//}
//
//void print1(int flag)//flagΪȱҳ��־�����ÿһ�����
//{
//    int t;
//    for(t=0;t<FN;t++)//ÿ����һ��ҳ�棬�����һ���ڴ�飨ҳ�棩
//        printf("%3d",frames[t]);
//    if(flag) printf("  fault");//��ȱҳλ�ñ�ǡ�fault��
//    printf("\n");
//}
//
//void print()//��������
//{
//    exchange=fault-FN;
//    ratio=(float)fault/PN*100;
//    printf("------------------------------\n");
//    printf("ȱҳ������%d\n",fault);
//    printf("�û�������%d\n",exchange);
//    printf("ȱ ҳ �ʣ�%4.1f%%\n",ratio);
//    printf("==============================\n");
//}
//
//int search(int p,int* ar,int start,int end)//����˵����(ҳ�ţ�ҳ��������л����ڴ�����飬��㣬�յ�)
//{//���ҳ��p�Ƿ��������ar��(���start���յ�end)�������򷵻�����ar�е�λ��(�±�)�����򷵻�-1
//    int i,f;
//    if(start>end)f=-1;//f��Ϊ�����־��f=1ʱ��ѭ������������f=-1ʱ��ѭ�������ݼ�
//    else f=1;
//    i=start;//��stratλ�ÿ�ʼ����
//    while(i!=end+f)//i����endʱ����ѭ��
//    {//��OPT�㷨�У�start<end��ѭ������������f=1������LRU�㷨�����෴��f=-1
//        if(p==ar[i])return i;//�״�������p�������±�
//        i=i+f;
//    }
//    return -1;//δ������ҳ��p����p��δ�����ٱ�����
//}
//
//
//void LRU(int* arp,int p,int* arf,int f)
//{//����˵����(ҳ������������飬���鳤�ȣ��ڴ�����飬���鳤��)
//    int i,j;
//    int kf=0;//kf>=fʱ���ڴ��������ʱȱҳ�����û�
//    int flag;//ȱҳ��־
//    int pmini,pminj;//���δ����ҳ����arp[]�й�ȥ��λ�ú���arf[]�е�λ��
//    int posi;
//    clear();//�����ڴ�����ݵ�
//    for(i=0;i<p;i++)
//    {
//        flag=0;
//        if(search(arp[i],arf,0,f-1)==-1)//ҳ�治���ڴ�
//        {
//            flag=1;
//            fault++;//ȱҳ
//            if(kf<f)//�п��п飬���û�
//            {
//                arf[kf]=arp[i];
//                kf++;
//            }
//            else//�޿��п飬�����û�
//            {//��arp[]����ǰ������Ѱ�����δ�����ʵ�ҳ��λ��
//                pmini=p;//pminiֵ��ֵ�����ֵ���ߵ�ǰֵi��
//                for(j=0;j<f;j++)
//                {
//                    posi=search(arf[j],arp,i-1,0);//������OPT��ͬ���������ҳ�治���ڵ����
//                    if(posi<pmini)
//                    {
//                        pmini=posi;
//                        pminj=j;
//                    }
//                }
//                arf[pminj]=arp[i];//�û�
//            }
//        }
//        print1(flag);//���һ���ڴ�ҳ�����
//    }
//}
