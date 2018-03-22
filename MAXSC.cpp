#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j,sum,flag,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>a[i][j];
		}
		for(i=0;i<n;i++)
		{
			sort(&a[i][0],&a[i][0]+n);
		}
		sum=a[n-1][n-1];
		x=sum;
		for(i=n-2;i>=0;i--)
		{
			flag=0;
			for(j=n-1;j>=0;j--)
			{
				if(a[i][j]<x)
				{
					x=a[i][j];
					flag=1;
					break;
				}
			}
			if(flag==1)
				sum=sum+x;
			else
				break;
		}
		if(flag==1||n==1)
			cout<<sum<<"\n";
		else
			cout<<"-1\n";
	}
	return 0;
} 