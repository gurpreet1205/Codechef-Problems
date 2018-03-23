#include<stdio.h>
int main()
{
    long long int t,n,i,j,c,d,e,cost;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        d=0;
        e=0;
        scanf("%lld",&n);
        long long int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]==0)
                c++;
            if(d==0)
            {
                if(a[i]==0)
                    d++;
                else
                    e++;
            }
        }
        cost=c*1000+(n-e)*100;
        printf("%lld\n",cost);
    }
    return 0;
}