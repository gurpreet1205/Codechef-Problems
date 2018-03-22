#include<stdio.h>
 int main()
 {
     int T,i,N,j,a,k,count=0;
     scanf("%d",&T);
     int arr[T];
     for(i=0;i<T;i++)
     {
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++)
            scanf("%d",&A[j]);
            count=0;
        for(j=0;j<N;j++)
        {
            a=j;
            for(k=0;k<N;k++)
            {
                a=a+A[a]+1;
                if(a>=N)
                    a=a%N;
                if(a==j)
                 break;
            }
            if(k!=N)
                count++;
        }
        arr[i]=count;
 }
 for(i=0;i<T;i++)
    printf("%d\n",arr[i]);
 return 0;
 }