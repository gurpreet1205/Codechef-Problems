#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int a[n],x=0,y=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		x=a[0];
		for(i=1;i<n;i++)
		{
			if(i%2==0)
			{
				if(x>0)
					x=x+a[i];
				else
					x=x-a[i];
			}
			else
			{
				if(x>0)
				{
					x=x-a[i];
				}
				else
					x=x+a[i];
			}
		}
		if(x>=k||(-1)*x>=k)
			cout<<1<<"\n";
		else
		{
			x=(-1)*a[0];
		for(i=1;i<n;i++)
		{
			if(i%2==0)
			{
				if(x>0)
					x=x+a[i];
				else
					x=x-a[i];
			}
			else
			{
				if(x>0)
				{
					x=x-a[i];
				}
				else
					x=x+a[i];
			}
		}
		if(x>=k||(-1)*x>=k)
			cout<<1<<"\n";
		else
			cout<<2<<"\n";
		}
	}
	return 0;
}