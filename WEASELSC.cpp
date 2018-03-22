#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,k,i,m,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int a[n],b[n]={0},c[n]={0};
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
					break;
				else
				b[i]++;
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=i-1;j>=0;j--)
			{
				if(a[i]>a[j])
					break;
				else
				c[i]++;
			}
		}
		/*for(i=0;i<n;i++)
		{
			cout<<b[i]<<" "<<c[i]<<"\n";
		}*/
		m=(b[0]+c[0]+1)*a[0];
		for(i=1;i<n;i++)
		{
			j=(b[i]+c[i]+1)*a[i];
			if(j>m)
				m=j;
		}
		cout<<m<<"\n";
	}
	return 0;
} 