#include<stdio.h>
int main()
{
    int T,i,j,N,d[6],a,g[25],h,k=0,win=1,l,sum,p;
    scanf("%d",&T);
    while(T--)
    {
        k=0;
        scanf("%d",&N);
        int c[N];
        for(i=0;i<N;i++)
        {
            h=0;
            d[0]=d[1]=d[2]=d[3]=d[4]=d[5]=0;
            for(j=0;j<25;j++)
                g[j]=0;
            sum=0;
            scanf("%d",&c[i]);
            a=c[i];
            int type[N][a];
            for(j=0;j<a;j++)
                scanf("%d",&type[i][j]);
            for(j=0;j<a;j++)
               d[type[i][j]-1]++;
            for(j=0;j<6;j++)
            {
                for(p=0;p<25;p++)
                {
                    if(d[j]>p)
                        g[p]++;
                }
 
            }
            for(j=0;j<25;j++)
            {
            if(g[j]==4)
                h=h+1;
            if(g[j]==5)
                h=h+2;
            if(g[j]==6)
                h=h+4;
            }
            sum=sum+h+c[i];
            if(sum>k)
            {
                win=i+1;
                k=sum;
            }
            else if(sum==k)
                l=k;
            else
            {}
    }
    if(k==l)
        printf("tie\n");
    else if(win==1)
        printf("chef\n");
    else
        printf("%d\n",win);
}
return 0;
}