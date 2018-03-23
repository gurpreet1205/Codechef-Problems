#include<stdio.h>
int main()
{
    int T,n,m,i=0;
    scanf("%d",&T);
    int arr[T];
    while(i<T)
    {
    scanf("%d %d",&n,&m);
    if((n*m)%2==0)
    arr[i]=1;
        else
        arr[i]=0;
        i++;
    }
    for(i=0;i<T;i++)
    {
        if(arr[i]==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
} 