#include<stdio.h>
long long int max(long long int *p,long long int i,long long int j)
{
    long long int k,large=*(p+i);
    for(k=i+1;k<=j;k++)
    {
        if(large<(*(p+k)))
            large=(*(p+k));
    }
    return large;
}
int f(long long int *p,long long int i,long long int j)
{
    if((((*(p+i))&(*(p+j)))==(*(p+i)))||(((*(p+i))&(*(p+j)))==(*(p+j))))
        return 1;
    else
        return 0;
}
int main()
{
   long long int N,i,j,sum=0,a;
    scanf("%lld",&N);
   long long int A[N];
    for(i=0;i<N;i++)
        scanf("%lld",&A[i]);
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(f(A,i,j)==1)
            sum=sum+max(A,i,j);
        }
 
    }
    printf("%lld ",sum);
    return 0;
}
 