#include<bits/stdc++.h>
using namespace std;
long long int modifiedBinarySearch(long long int *a,long long int n,long long int x)
{
	long long int low=0,high=n-1,mid;
	if(a[0]>=x)
		return 0;
	if(a[n-1]<=x)
		return n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>=x)
		{
			if(a[mid-1]<x)
				return mid;
			else
				high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
}

int main()
{
	long long int t,n,m,i,j=0,p,x;
	cin>>t;
	while(t--)
	{
		j=0;
	cin>>n>>m;
	long long int l[n],r[n],a[2*n+1];
	for(i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		a[j++]=l[i];
		a[j++]=r[i];
	}
	sort(a,a+j);
	for(i=0;i<m;i++)
	{
		cin>>p;
		x=modifiedBinarySearch(a,2*n,p);
		if(x==2*n)
			cout<<"-1\n";
		else if(x%2==0)
		{
			if(a[x]==p)
				cout<<"0\n";
			else
				cout<<a[x]-p<<"\n";
		}
		else
		{
			if(a[x]!=p)
				cout<<"0\n";
			else
				cout<<a[x+1]-p<<"\n";
		}
	}
}
	return 0;
}