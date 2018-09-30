#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n];
		double s=0.0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		s=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			s=(s+a[i])/2.0;
		}
		cout<<setprecision(8)<<fixed<<s<<"\n";
	}
	return 0;
}