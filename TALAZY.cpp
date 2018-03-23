#include<stdio.h>
int main()
{
   long long int T,N,B,M,sum,tm;
    scanf("%lld",&T);
    while(T--)
    {
        sum=0;
        scanf("%lld %lld %lld",&N,&B,&M);
        while(N!=0)
        {
            if((N%2)==0)
            {
                tm=M*(N/2);
                N=N/2;
            }
            else
            {
                tm=M*((N+1)/2);
                N=N-((N+1)/2);
            }
            sum=sum+tm+B;
            M=M*2;
        }
        sum=sum-B;
        printf("%lld\n",sum);
    }
    return 0;
}