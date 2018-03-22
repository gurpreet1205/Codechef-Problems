#include<stdio.h>
void mergesort(long long int *a,long long int n)
{
    long long int b[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x);
    mergesort(a+x,n-x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
        a[i]=b[i];
}
int main()
{
    long long int t,n,i,j,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long int a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        mergesort(a,n);
        if((a[1]-a[0])!=1)
            printf("%lld\n",a[0]);
        else if(a[n-1]-a[n-2]!=1)
            printf("%lld\n",a[n-1]);
        else
        {
            for(i=0;i<n-1;i++)
            {
                if(a[i]==a[i+1])
                    break;
            }
            printf("%lld\n",a[i]);
        }
    }
    return 0;
}
 