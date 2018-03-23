#include<stdio.h>
int gcd(int a,int b)
{
    if(b%a==0)
        return a;
    else
        return(gcd(b%a,a));
}
int main()
{
    int i,j,T,N,c;
    scanf("%d",&T);
    int a[T];
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        int arr[N];
        for(j=0;j<N;j++)
            scanf("%d",&arr[j]);
          c=arr[0];
        for(j=1;j<N;j++)
        {
            c=gcd(c,arr[j]);
        }
        a[i]=c;
    }
    for(i=0;i<T;i++)
    printf("%d\n",a[i]);
    return 0;
}