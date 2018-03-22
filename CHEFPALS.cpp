#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j,x,y,z,s=0,l=0,q,r;
	cin>>n;
	long long int a[n],b[n],c[n],d[n],e[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
	{
		c[i]=a[i]-b[i];
		d[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<b[i];j++)
			cout<<"b";
		for(j=0;j<c[i];j++)
			cout<<"w";
		cout<<"\n";
	}
	for(i=0;i<n;i=i+2)
		cout<<i+1<<" ";
	for(i=1;i<n;i=i+2)
		cout<<i+1<<" ";
	return 0;
} 