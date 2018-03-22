#include<stdio.h>
int main()
{
    long long int t,n,i,j,k,c;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        scanf("%lld",&n);
        long long int a[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lld",&a[i][j]);
                if(a[i][j]==1)
                    c++;
            }
        }
        c=c-n;
        k=0;
        i=1;
        while(c>0)
        {
            c=c-2*(n-i);
            i++;
            k++;
        }
        printf("%lld\n",k);
    }
    return 0;
}
 