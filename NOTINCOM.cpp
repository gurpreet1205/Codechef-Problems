#include<stdio.h>
int main()
{
long long int n,m,i,j,k,t,N;
scanf("%lld",&t);
while(t--)
{
    k=0;
    scanf("%lld %lld",&n,&m);
    long long int a[1000001]={0};
    for(i=0;i<n;i++)
    {
        scanf("%lld",&N);
        a[N]++;
    }
    for(j=0;j<m;j++)
    {
        scanf("%lld",&N);
        a[N]++;
    }
    for(i=0;i<1000001;i++)
    {
        if(a[i]==2)
            k++;
    }
    printf("%lld\n",k);
}
return 0;
}