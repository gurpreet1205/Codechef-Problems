#include<stdio.h>
long long int b[1000001];
int main()
{
    long long int t,i,c,n,k,flag=0,max=0;
    scanf("%lld",&t);
    while(t--)
    {
        flag=0;
        c=0;
        k=0;
        for(i=0;i<1000001;i++)
            b[i]=0;
        scanf("%lld",&n);
        long long int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if((i>0)&&(a[i]!=a[i-1]))
                flag=1;
            b[a[i]]++;
            //if(b[a[i]]==1)
              //  c++;
        }
       /* max=0;
        for(i=1;i<1000001;i++)
        {
            if(b[i]>max)
                max=b[i];
        }
        k=(n-max)*2;
        if(k<n)
        printf("%lld\n",k);
        else
            */
            if(flag==0)
                printf("0\n");
            else
            printf("%lld\n",n);
    }
 
    return 0;
}