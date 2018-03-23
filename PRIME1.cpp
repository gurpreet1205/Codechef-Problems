#include<bits/stdc++.h>
using namespace std;
long long int a[50000];
int main()
{
	long long int t,n,i,j,k,m,x,y,z;
	cin>>t;
	long long int prime[50000];
	x=sqrt(50000);
	k=0;
	for(i=0;i<50000;i++)
		a[i]=1;
	for(i=2;i<x;i++)
	{
		if(a[i]==1)
		{
		for(j=i*i;j<50000;j=j+i)
		{
			a[j]=0;
		}
		}
	}
	for(i=2;i<50000;i++)
	{
		if(a[i]==1)
			prime[k++]=i;
	}
	while(t--)
	{
		cin>>m>>n;
		long long int b[n-m+1];
		for(i=0;i<=n-m;i++)
			b[i]=1;
		if(m==1)
			b[0]=0;
		z=sqrt(n);
		for(i=0;i<k;i++)
		{
			if(prime[i]>z)
				break;
			x=(m-1)/prime[i]+1;
			y=prime[i];
			if(x<y)
				x=y;
			for(j=y*x;j<=n;j=j+y)
			{
				b[j-m]=0;
			}
		}
		for(i=0;i<=n-m;i++)
		{
			if(b[i]==1)
				cout<<m+i<<"\n";
		}
		cout<<"\n";
	}
	return 0;
} 