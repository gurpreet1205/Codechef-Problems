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
        long long int t,n,i,j,m,c,temp;
        cin>>t;
        while(t--)
        {
            cin>>n;
            long long int a[2*n];
            for(i=0;i<2*n;i++)
                cin>>a[i];
            mergesort(a,2*n);
            c=(n+1)/2;
            m=a[2*n-c];
            j=1;
            for(i=2;i<=c;i++)
            {
                temp=a[2*n-i];
                a[2*n-i]=a[j];
                a[j]=temp;
                j=j+2;
            }
            cout<<m<<endl;
            for(i=0;i<2*n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        return 0;
    }
 