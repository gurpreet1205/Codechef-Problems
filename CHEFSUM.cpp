#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j;
	cin>>t;
	while(t--)
	{
		long long int m=INT_MAX;
		cin>>n;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<m)
			{
				m=a[i];
				j=i;
			}
		}
		cout<<j+1<<"\n";
	}
	return 0;
} 