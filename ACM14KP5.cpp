//ACMICPC
#include<stdio.h>
//ACMICPC
int main()
{
    long long int t,i,j,k,n,sum,sum1,x=1;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld",&n);
        long long int a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    sum1=a[i]+a[j]+a[k];
                    if(sum1>sum)
                        sum=sum1;
                }
            }
        }
        printf("Case %lld: ",x);
        printf("%lld\n",sum);
        x++;
    }
    return 0;
}
