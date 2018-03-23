#include<stdio.h>
long long int in[50001],n,mid;
void swap(long long int *a,long long int *b)
{
    long long int temp;
    temp=*a;
    *a=*b;
    *b=temp;
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
long long int bsearch(long long int *a,long long int first,long long int last,long long int num)
{
    if(first>last)
    {
        //printf("The element is not found");
        return 0;
    }
        mid=(first+last)/2;
    if(a[mid]==num)
        return 1;
    else if(a[mid]>num)
        bsearch(a,first,mid-1,num);
    else
        bsearch(a,mid+1,last,num);
}
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
        if(a[i]<a[j])
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
int main()
{
    long long int t,i,j,k,ro,co,temp,q;
    scanf("%lld",&t);
    while(t--)
    {
        long long int a[50001]={0};
        k=0;
        q=0;
        scanf("%lld",&n);
        long long int p[n],ans[n];
        for(i=0;i<n;i++)
            scanf("%lld",&p[i]);
        for(i=1;i<=n;i++)
            in[i-1]=i;
        msort(p,n,in);
        //printf("%lld",gp(1,n));
        //printf("%lld %lld %lld %lld %lld %lld\n",gp(1,n),gp(2,n),gp(3,n),gp(4,n),gp(5,n),gp(6,n));
        long long int r[2*n-2],c[2*n-2];
        //for(i=0;i<n;i++)
            //printf("%lld %lld\n",p[i],in[i]);
        for(i=1;i<n;i++)
        {
            scanf("%lld %lld",&ro,&co);
            r[k]=ro;
            c[k]=co;
            k++;
            r[k]=co;
            c[k]=ro;
            k++;
            a[ro]++;
            a[co]++;
        }
        if(n==1)
            printf("0\n");
        else
        {
        //for(i=0;i<2*n-2;i++)
            //printf("%lld %lld\n",r[i],c[i]);
        msort(r,2*n-2,c);
                //for(i=0;i<2*n-2;i++)
            //printf("%lld %lld\n",r[i],c[i]);
        //printf("a");
        //for(i=0;i<2*n-2;i++)
          //  printf("%lld %lld\n",r[i],c[i]);
          k=0;
          for(i=0;i<n;i++)
          {
              long long int arr[a[n-i]+1];
              for(j=0;j<a[n-i];j++)
              {
                  arr[j]=c[k];
                  //if(i==2)
                    //printf("%lld\n",arr[j]);
                  k++;
              }
              arr[j]=n-i;
              mergesort(arr,a[n-i]+1);
              for(j=0;j<n;j++)
              {
                  //if(i==2)
                  //printf("a%lld\n",bsearch(arr,0,a[n-i],in[j]));
                  if(bsearch(arr,0,a[n-i],in[j])==0)
                  {
                    ans[n-i-1]=in[j];
                    break;
                  }
              }
              if(j==n)
                ans[n-i-1]=0;
          }
        for(i=0;i<n;i++)
            printf("%lld ",ans[i]);
        printf("\n");
        //for(i=0;i<n;i++)
          //  printf("%lld\n",in[i]);
        }
    }
    return 0;
}