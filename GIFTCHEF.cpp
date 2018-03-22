#include<stdio.h>
long long int a[300001],b,c[300001],d,i;
long long int arr[300001]={0};
long long int abc(long long int n)
{
    if(n==0)
        return 0;
    else if(n==1)
    {
        a[1]=1;
        return 1;
    }
    else
        c[n-1]=abc(n-1);//final answer
    d=c[n-1]+c[n-1]+1;
    b=arr[n];//counting overlapping
    if(b==0)
    {
        a[n]=d-c[n-1];
        if(d>1000000007)
            d=d%1000000007;
        return d;
    }
    else
    {
            d=d-(c[n-1]-c[n-b-1]);
            if(d<0)
                d=1000000007+d;
        a[n]=d-c[n-1];
        if(d>1000000007)
             d=d%1000000007;
        return d;
    }
}
struct abcde
{
    long long int lower;
    long long int upper;
};
struct abcde x[300001];
int main()
{
    long long int t,i,j,k,n,y,lf,ls,first,last,mid,p,q,e;
    char s[300001],f[300001];
    scanf("%lld",&t);
    while(t--)
    {
        e=0;
        n=0;
        fflush(stdin);
        scanf("%s",s);
        fflush(stdin);
        scanf("%s",f);
        lf=strlen(f);
        ls=strlen(s);
        for(j=0;j<=ls-lf;j++)
        {
            k=0;
            for(i=j;i<lf+j;i++)
            {
                 if(f[k]!=s[i])
                 {
                     break;
                     j=i;
                 }
                k++;
            }
        if(i==(lf+j))
        {
            n++;
            x[n].lower=j;
            x[n].upper=j+lf-1;
            first=1;
            last=n-1;
            while(first<=last)
            {
            mid=(first+last)/2;
            if((x[n].lower<=x[mid].upper)&&(x[n].lower>x[mid-1].upper))
            {
                e=1;
                arr[n]=n-mid;
                break;
            }
            else if(x[n].lower<x[mid].upper)
                last=mid-1;
            else
                first=mid+1;
               // printf("%lld %lld %lld %lld\n",x[n].lower,x[i-1].upper,arr[n],n);
            }
        }
        }
        //printf("%lld ",n
        if(e==0)
        {
            k=1;
            q=1;
        p=pow(10,9);
        j=pow(2,50);
        for(i=0;i<20;i++)
        {
            q=(q*(j%(p+7)))%(p+7);
        }
        while(n>1000)
        {
            n=n-1000;
            k=(k*q)%(p+7);
        }
        while(n>51)
        {
            n=n-50;
            k=(k*(j%(p+7)))%(p+7);
        }
            i=pow(2,n);
            k=k*(i%(p+7));
            k=(k%(p+7))-1;
            printf("%lld\n",k);
        }
        else
        {
           y=abc(n);
           printf("%lld\n",y);
        }
        for(i=1;i<=n;i++)
        {
            //printf("%lld ",arr[i]);
            arr[i]=0;
        }
    }
    return 0;
}