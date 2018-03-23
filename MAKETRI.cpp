#include<stdio.h>
void msort(long long int *a,long long int n,long long *c)
{
    long long int b[n],d[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    msort(a,x,c);
    msort(a+x,n-x,c+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            d[k]=c[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
    }
}
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
    long long int n,l,r,i,j,max,c=0,z;
    scanf("%lld %lld %lld",&n,&l,&r);
    long long int a[n],b[n-1];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    mergesort(a,n);
    max=a[n-1]+a[n-2];
    if(l>=max)
        printf("0\n");
    else
    {
        long long int ll[n-1],ul[n-1],x[n-1],y[n-1];
        for(i=0;i<n-1;i++)
        {
            ll[i]=a[i+1]-a[i]+1;
            ul[i]=a[i+1]+a[i]-1;
        }
        //msort(ll,n-1,ul);
        //for(i=0;i<n-1;i++)
          //  printf("%lld %lld\n",ll[i],ul[i]);
        j=0;
        for(i=0;i<n-1;i++)
        {
            if((ll[i]<l)&&(ul[i]>=l)&&(ul[i]<=r))
            {
                x[j]=l;
                y[j]=ul[i];
                j++;
            }
            else if((ll[i]>=l)&&(ul[i]<=r))
            {
                x[j]=ll[i];
                y[j]=ul[i];
                j++;
                //printf("%lld\n",i);
            }
            else if((ll[i]>=l)&&(ll[i]<=r)&&(ul[i]>r))
            {
                x[j]=ll[i];
                y[j]=r;
                j++;
            }
            else if((ll[i]<l)&&(ul[i]>r))
            {
                x[j]=l;
                y[j]=r;
                j++;
            }
            else;
        }
        //printf("%lld\n",j);
        msort(x,j,y);
        //for(i=0;i<j;i++)
          //  printf("%lld %lld\n",x[i],y[i]);
        c=y[0]-x[0]+1;
        //printf("%lld %lld\n",y[0],x[0]);
        max=y[0];
        for(i=0;i<j-1;i++)
        {
            //printf("%lld ",c);
            if(x[i+1]>max)
            {
                c=c+y[i+1]-x[i+1]+1;
                max=y[i+1];
            }
            else if((x[i+1]<=max)&&(y[i+1]>max))
            {
                c=c+y[i+1]-x[i+1]+1-(max-x[i+1]+1);
                max=y[i+1];
            }
            else;
           // else if((x[j+1]<=y[j])&&(y[j+1]<=y[j]));
        }
        printf("%lld",c);
    }
    return 0;
}