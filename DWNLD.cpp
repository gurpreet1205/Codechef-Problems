#include<stdio.h>
int main()
{
    long long int n,m,i,j,k,t,c;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        scanf("%lld %lld",&n,&k);
        long long int a[n],b[n];
        for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i],&b[i]);
        for(i=0;i<n;i++)
        {
            if(a[i]<=k)
            {
                k=k-a[i];
                continue;
            }
            if(c==0)
            {
                c=c+(a[i]-k)*b[i];
                k=0;
            }
            else
            c=c+a[i]*b[i];
        }
        printf("%lld\n",c);
    }
    return 0;
}