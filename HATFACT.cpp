#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,p,j,x,z,c,t;
	cin>>t;
	while(t--)
	{
	p=1;
	long long int a[200];
	cin>>n;
	a[199]=1;
	for(i=2;i<=n;i++)
	{
		c=0;
		for(j=199;j>200-p;j--)
		{
			x=a[j]*i;
			a[j]=(x+c)%10;
			c=(x+c)/10;
		}
		x=a[j]*i+c;
		while(x>0)
		{
			a[j]=x%10;
			x=x/10;
			j--;
		}
		p=199-j;
	}
	for(i=200-p;i<200;i++)
		cout<<a[i];
	cout<<"\n";
	}
	return 0;
} 