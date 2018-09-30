#include<bits/stdc++.h>
using namespace std;
long long int fun(long long int a,long long int b)
{
	long long int i,j,k,sa=0,sb=0,x;
	for(i=2;i<=a;i++)
	{
		x=0;
		while(a%i==0)
		{
			a=a/i;
			if(x==0)
			{
				sa=sa+i;
				x=1;
			}
		}
	}
	for(i=2;i<=b;i++)
	{
		x=0;
		while(b%i==0)
		{
			b=b/i;
			if(x==0)
			{
				sb=sb+i;
				x=1;
			}
		}
	}
	if(sb%sa==0)
		return 1;
	else
		return 0;
}
int main()
{
	long long int t,n,i,j,k,c;
	cin>>t;
	while(t--)
	{
		c=0;
		cin>>n;
		long long int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(a[j]%a[i]==0)
					{
						if(fun(a[i],a[j])==1)
							c++;
					}
				}
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}