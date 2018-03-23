#include<stdio.h>
int main()
{
    long long int t,n,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long int a[n],b[n];
        b[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            b[i]=a[i];
        }
        for(i=0;i<n;i++)
            printf("%lld",b[i]);
        printf("\n");
    }
}