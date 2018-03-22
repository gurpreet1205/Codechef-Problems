#include<bits/stdc++.h>
using namespace std;
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
        a[i]=b[i];
}
int main()
{
    long long int t,n,i,pos,c,j,neg,res;
    cin>>t;
    while(t--)
    {
        pos=0;
        c=0;
        j=0;
        neg=0;
        cin>>n;
        long long int b[n]={0};
        long long int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>=0)
            {
                pos=pos+a[i];
                c++;
            }
            else
            {
              b[j]=a[i];
              j++;
            }
        }
        mergesort(b,j);
        for(i=0;i<j;i++)
        {
            if((pos+b[i])*(c+1)>(pos*c-b[i]))
            {
                pos=pos+b[i];
                c++;
            }
            else
               neg=neg+b[i];
        }
        res=pos*c+neg;
        cout<<res<<endl;
    }
    return 0;
}