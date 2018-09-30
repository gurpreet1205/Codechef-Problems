#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,k,i,x,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int a[n][k],b[n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
				cin>>a[i][j];
		}

		for(i=0;i<k;i++)
		{
			for(j=0;j<n;j++)
				b[j]=a[j][i];
			sort(b,b+n);
			x=(n-1)/2;
			cout<<b[x]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}