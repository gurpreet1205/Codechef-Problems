#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int a[n],b[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(i=0;i<k;i++)
		{
			if(a[i]>=b[n-k+i])
				break;
		}
		if(i==k)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}