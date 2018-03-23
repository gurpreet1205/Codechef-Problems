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
        if(a[i]<a[j])
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
    {
        a[i]=b[i];
    }
}
int main()
{
    long long int n,m,l,r,k,i,j,c,p,x;
    scanf("%lld %lld",&n,&m);
    long long int a[n],b[n],d[n],e[n];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    b[n-1]=1;
    e[n-1]=1;
    d[0]=1;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]==a[i+1])
        {
            b[i]=b[i+1]+1;
            e[i]=b[i];
        }
        else
        {
            b[i]=1;
            e[i]=b[i];
        }
    }
    mergesort(e,n);
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            d[i]=d[i-1]+1;
        else
            d[i]=1;
    }
    for(i=0;i<m;i++)
    {
        c=1;
        scanf("%lld %lld %lld",&l,&r,&k);
        if(l==r)
            printf("%lld\n",a[l-1]);
        else if(e[0]<k)
            printf("-1\n");
        else
        {
            p=0;
            x=0;
        for(j=l-1;j<=r-k;j=j+b[j])
        {
            //if(e[x]<k)
            //{
              //  printf("-1\n");
                //break;
            //}
            if(a[j]==a[j+k-1])
            {
                if(b[j]>=k)
                {
                    printf("%lld\n",a[j]);
                    break;
                }
            }
            if(a[r-k-p]==a[r-1-p])
            {
                if(b[r-k-p]>=k)
                {
                    printf("%lld\n",a[r-k-p]);
                    break;
                }
            }
            if((r-k-p)<=j)
            {
                printf("-1\n");
                break;
            }
            p=p+d[r-1-p];
        }
        if(j>=r-k+1)
            printf("-1\n");
        }
    }
    return 0;
}