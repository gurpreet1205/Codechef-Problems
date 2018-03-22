#include<stdio.h>
int main()
{
    long long int t,i,j,k,n,sum1,sum2;
    scanf("%lld",&t);
    while(t--)
    {
        sum1=0;
        sum2=0;
        scanf("%lld",&n);
        long long int a[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(i%2==0)
               sum1=sum1+a[i];
            else
                sum2=sum2+a[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
            if(i%2==0)
               sum2=sum2+b[i];
            else
                sum1=sum1+b[i];
        }
        if(sum1<sum2)
            printf("%lld\n",sum1);
        else
            printf("%lld\n",sum2);
    }
    return 0;
}