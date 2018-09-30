#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int a[n],b[n],m=0,s;
		for(i=0;i<n;i++)
			cin>>a[i];
		b[0]=a[0];
		for(i=1;i<n;i++)
		{
			b[i]=b[i-1]+a[i];
		}
		for(i=0,j=i+k-1;i<n&&j<n;i++,j++)
		{
			if(i==0)
				s=b[j];
			else
			{
				s=b[j]-b[i-1];
			}
			m=max(m,s);
		}
		if(k<=n)
			cout<<m<<"\n";
		else
			cout<<b[n-1]<<"\n";
	}
	return 0;
}