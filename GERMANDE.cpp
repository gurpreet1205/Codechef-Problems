#include<stdio.h>
int main()
{
    long long int t,o1,o2,i,j,k,n,a,b,c;
    scanf("%lld",&t);
    while(t--)
    {
        a=0;
        scanf("%lld %lld",&o1,&o2);
        n=o1*o2;
        long long int d[n],sum[n];
        for(i=0;i<n;i++)
            scanf("%lld",&d[i]);
        sum[0]=d[0];
        for(i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+d[i];
        }
        for(i=0;i<o2;i++)
        {
            if(i==0)
                a=0;
            else
                a=sum[i-1];
            c=0;
            b=0;
            for(j=o2-1+i;j<n+i;j=j+o2)
            {
                if(j>=n)
                {
                    b=sum[j-n];
                    j=n-1;
                }
                if((sum[j]-a+b)>(o2/2))
                    c++;
                a=sum[j];
            }
 
            if(c>(o1/2))
            {
                printf("1\n");
                break;
            }
        }
        if(c<=o1/2)
            printf("0\n");
    }
}