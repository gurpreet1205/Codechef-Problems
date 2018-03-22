#include<stdio.h>
int main()
{
    long long int t,h,k,i,j,n,c;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        scanf("%lld %lld",&h,&k);
        n=(long long int)pow(2,h);
        long long int a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(a[0]<a[1])
            c++;
        if((a[0]<a[2])||(a[0]<a[3]))
            c++;
        j=3;
        for(i=4;i<n;i++)
        {
            if(i>=(long long int)pow(2,j))
                j++;
            if(a[i]>a[0])
            {
                c++;
                i=(long long int)pow(2,j);
                j++;
            }
        }
        printf("%lld\n",c);
    }
    return 0;
}