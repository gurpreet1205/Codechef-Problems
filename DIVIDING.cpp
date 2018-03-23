#include<stdio.h>
int main()
{
    int N,i,sum=0;
    scanf("%d",&N);
    int C[N];
    for(i=0;i<N;i++)
        scanf("%d",&C[i]);
    for(i=0;i<N;i++)
        sum=sum+C[i];
    if(sum==(N*(N+1))/2)
        printf("YES");
    else
        printf("NO");
    return 0;
}