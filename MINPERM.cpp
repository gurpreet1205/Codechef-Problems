#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			a[i]=i+2;
			else
			a[i]=i;	
		}
		if(n%2!=0)
		{
			a[n-1]=a[n-2];
			a[n-2]=n;
		}
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
} 