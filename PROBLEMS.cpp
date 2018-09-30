#include<bits/stdc++.h>
using namespace std;
void mergesort(long long int *a,long long int n,long long int *c)
{
    long long int b[n],d[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c);
    mergesort(a+x,n-x,c+x);
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
int main()
{
	long long int p,s,i,j,k,n;
	cin>>p>>s;
	long long int c[p],d[p];
	for(i=0;i<p;i++)
	{
		n=0;
		long long int a[s],b[s];
		for(j=0;j<s;j++)
			cin>>a[j];
		for(j=0;j<s;j++)
			cin>>b[j];
		mergesort(a,s,b);
		for(j=0;j<s-1;j++)
		{
			if(b[j]>b[j+1])
				n++;
		}
		c[i]=n;
		d[i]=i+1;
	}
	mergesort(c,p,d);
	for(i=0;i<p;i++)
		cout<<d[i]<<"\n";
	return 0;
}