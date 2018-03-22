#include<stdio.h>
#include<math.h>
long long int a[100000];
long long int c[1000000]={0};
long long int lpd(long long int n)
{
    if(c[n]!=0)
        return c[n];
    if(n==1)
    {
        c[n]=1;
        return 1;
    }
    if(n%2==0)
    {
        c[n]=2;
        return 2;
    }
    long long int i,p=n;
    double q;
    q=pow(n,(1.0/2.0));
    if(q-(int)q==0)
    {
       c[n]=lpd((int)q);
       return c[n];
    }
        for(i=3;i<=p;i=i+2)
        {
            if(n%i==0)
            {
                c[n]=i;
                return i;
            }
            q=pow(n,(1.0/i));
            if(q-(int)q==0)
            {
                c[n]=lpd((int)q);
                return c[n];
            }
            p=n/i;
        }
        c[n]=n;
        return n;
}
void update(long long int L,long long int R)
{
    long long int i;
    for(i=L;i<=R;i++)
        a[i]=a[i]/lpd(a[i]);
}
long long int get(long long int L,long long int R)
{
    long long int result=1,t,i;
    for(i=L;i<=R;i++)
    {
        t=lpd(a[i]);
        if(t>result)
            result=t;
    }
    return result;
}
int main()
{
    long long int T,type,N,M,i,j,L,R,k;
    scanf("%lld",&T);
    while(T--)
    {
        j=0;
        scanf("%lld %lld",&N,&M);
        long long int b[M];
        for(i=0;i<M;i++)
            b[i]=0;
        for(i=0;i<N;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<M;i++)
        {
            scanf("%lld %lld %lld",&type,&L,&R);
            if(type==0)
                update(L-1,R-1);
            if(type==1)
            {
                b[j]=get(L-1,R-1);
                j++;
            }
        }
        for(i=0;i<M;i++)
        {
            if(b[i]==0)
                break;
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}