#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct list//使用typedef，在main中定义list变量时，list前面不再需要加struct
{
    char date[15];
    char info[8];
    float data1,data2;
}list;
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    list *open=(list*)malloc(sizeof(list)*N);
    list *close=(list*)malloc(sizeof(list)*N);
    list a;
    int j=0,k=0;
    for(int i=0;i<N;i++)
    {

        scanf("%s %s %f %f",a.date,a.info,&a.data1,&a.data2);
        if(strcmp(a.info,"close")==0)
        {
            int t;
            for(t=j;t>0&&strcmp(a.date,close[t-1].date)<0;t--)
            {
                close[t]=close[t-1];
            }
            close[t]=a;
            j++;
        }

        else
        {
            int t;
            for(t=k;t>0&&strcmp(a.date,open[t-1].date)<0;t--)
            {

                open[t]=open[t-1];
            }
            open[t]=a;
            k++;
        }
    }
    /*for(i=0;i<k;i++)
    {
     printf("%s %s %f %f\n",open[i].date,open[i].info,open[i].data1,open[i].data2);
    }*/
    int i;
    for(i=M-1;i<k;i++)
    {    float b=0,c=0;
        for(int cnt=i,tag=0;tag<M;cnt--,tag++)
        {
            b+=open[cnt].data1;
            c+=open[cnt].data2;
        }
        printf("%s %s %0.f %0.f\n",open[i].date,open[i].info,b/M,c/M);
    }

    for(i=M-1;i<j;i++)
    {    float b=0,c=0;
        for(int cnt=i,tag=0;tag<M;cnt--,tag++)
        {
            b+=close[cnt].data1;
            c+=close[cnt].data2;
        }
        printf("%s %s %0.f %0.f\n",close[i].date,close[i].info,b/M,c/M);
    }
}
