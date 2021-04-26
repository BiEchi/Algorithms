#include<iostream>
#define N 10   //限定机器数和作业数不超过N个，这里N取10

using namespace std;

struct MachineNode
{
    int ID;     //机器号
    int avail; //机器可用时间
};
struct JobNode
{
    int ID;     //作业号
    int time; //处理时间
};
 
//建立大根堆
void SiftD(JobNode r[],int k,int m)
{
    int i,j;
    i=k;
    j=2*i;
    while(j<=m)
    {
        if(j<m&&r[j].time<r[j+1].time)j++;
        if(r[i].time>r[j].time)break;
        else
        {
            int temp1,temp2;
            temp1=r[i].time;
            r[i].time=r[j].time;
            r[j].time=temp1;
            temp2=r[i].ID;
            r[i].ID=r[j].ID;
            r[j].ID=temp2;
        }
    }
}
 
 void HeapSortD(JobNode r[],int n)
 {
     for(int i=n/2;i>=1;i--)
         SiftD(r,i,n);
 }
 
//建立小根堆
void SiftX(MachineNode r[],int k,int m)
 {
     int i,j;
     i=k;
     j=2*i;
     while(j<=m)
     {
         if(j<m&&r[j].avail>r[j+1].avail)j++;
         if(r[i].avail<r[j].avail)break;
         else
         {
             int temp1,temp2;
             temp1=r[i].avail;
             r[i].avail=r[j].avail;
             r[j].avail=temp1;
             temp2=r[i].ID;
             r[i].ID=r[j].ID;
             r[j].ID=temp2;
         }
     }
}
 
void HeapSortX(MachineNode r[],int n)
 {
     for(int i=n/2;i>=1;i--)
         SiftX(r,i,n);
 }
 
//完成任务分配
void assign(MachineNode M[],JobNode J[],int m,int j)
 {
    if(m>=j)   //如果机器数m大于或等于作业数j
    {
        printf("工作数和机器数相同,一台机器完成一个作业\n");
        HeapSortD(J,j);   //以各作业所需时间建立大根堆，堆顶元素即为最大耗时的作业
        printf("最大工作时间为:%d\n",J[1].time);  //最大工作时间即为最大耗时的作业的所需时间
    }
    else  //如果机器数m小于作业数j
    {
        for(int i=1;i<=m;i++) //先为每台机器分配一个作业，先把所需时间最大的m个作业分配给m台机器。
        {
            HeapSortD(J,j);  //建立大根堆求堆顶元素确定其中耗时最大的作业
            M[i].avail=J[1].time;  //机器i的处理时间即为作业的所需时间
            printf("机器%d,完成作业%d,时间从0到%d\n",M[i].ID,J[1].ID,M[i].avail);
            for(int k=1;k<j;k++)  //减去已分配的作业
                J[k]=J[k+1];
            j=j-1;
        }
        for(int q=j;j>=1;q--) //把剩余的j-m个作业分配下去（j=j-m）
        {
            HeapSortX(M,m);  //将m机器个机器按可用时建立小根堆
            HeapSortD(J,j);  //将j个作业按处理时间建立大根堆
            printf("机器%d,完成作业%d,时间从%d到%d\n",M[1].ID,J[1].ID,M[1].avail,M[1].avail+J[1].time);  //将大根堆的堆顶作业分配给小根堆的堆顶机器
            M[1].avail+=J[1].time; //将小根堆的堆顶机器加上大根堆的堆顶作业的处理时间，重新插入小根堆（循环执行HeapSortX(M,m)时完成）
            for(int k=1;k<j;k++)  //减去已分配的作业
                J[k]=J[k+1];
            j=j-1;
        }
        printf("最短调度时间为：%d\n",M[1].avail);  //小根堆的堆顶元素就是最短调用时间
    }
 }

int main()
{
    int j=0;    //作业个数
    int m=0; //机器个数
    int i;
    MachineNode M[N];     //机器的结构体数组
    JobNode J[N];         //作业的结构体数组
    printf("作业个数：");
    scanf("%d",&j);
    for(i=1;i<=j;i++)
    {   printf("请输入%d个作业需要的处理时间(空格隔开)\n",j);
        J[i].ID=i;                                      //为每个作业确定序号
        scanf("%d",&J[i].time);
    }
    printf("机器的个数");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        M[i].ID=i;      //为每台机器确定序号
    assign(M,J,m,j);    //调用完成分配任务的函数
    return 0;
}
