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
	long long int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n],b[n],c[n-1],x=0,y=0,z,m=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=i;
		}
		mergesort(a,n,b);
		for(i=0;i<n-1;i++)
		{
			c[i]=b[i]-b[i+1];
			//cout<<c[i]<<" ";
		}
		//cout<<"\n";
		//int max_so_far = INT_MIN, max_ending_here = 0;
 
    	for (i=0;i<n-1;i++)
    	{
    		y=y+c[i];
        	if (x<y)
            	x=y;
        	if (y<0)
            	y=0;
    	}
    	z=0;
    	for(i=1;i<n;i++)
    	{
    		if(a[i]!=a[i-1])
    		{
    			m=max(m,i-z);
    			z=i;
    		}
    	}
    	m=max(m,i-z);
    	m=max(x+1,m);
    	cout<<m<<"\n";
	}
	return 0;
}