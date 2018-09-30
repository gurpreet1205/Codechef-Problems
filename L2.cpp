#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,j,n,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n%2!=0)
			cout<<"NO\n";
		else
		{
			x=n/2;
			for(i=0;i<n/2;i++)
			{
				if(a[i]!=-1&&a[x+i]!=-1&&a[i]!=a[x+i])
					break;
				if(a[i]==-1&&a[x+i]!=-1)
					a[i]=a[x+i];
				else if(a[i]!=-1&&a[x+i]==-1)
					a[x+i]=a[i];
				else if(a[i]==-1&&a[x+i]==-1)
				{
					a[i]=1;
					a[x+i]=1;
				}
			}
			if(i!=n/2)
				cout<<"NO\n";
			else
			{
				cout<<"YES\n";
				for(i=0;i<n;i++)
					cout<<a[i]<<" ";
				cout<<"\n";
			}
		}
	}
	return 0;
}