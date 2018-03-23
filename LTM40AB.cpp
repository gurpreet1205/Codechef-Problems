#include<stdio.h>
int main()
{
    long long int T,a,b,c,d,n,x,y,sum,i,j;
    scanf("%lld",&T);
    while(T--)
    {
        i=1;
        sum=0;
        n=0;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a>d)
            printf("0\n");
        else
        {
        j=c;
        if(c<=a)
        {
           i=a-c+1;
           j=a;
        }
        if(c<=b)
        {
            while(j<=b)
            {
                sum=sum+i;
                if(j<d)
                i++;
                j++;
            }
        n=(b-a+1)*(d-c+1)-sum;
        }
        else
            n=(b-a+1)*(d-c+1);
        printf("%lld\n",n);
    }
    }
    return 0;
}