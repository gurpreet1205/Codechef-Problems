#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j,k,x,y,z,c,sum_a,sum_b,ans,ans1,ans2,m,amul,bmul;
	cin>>t;
	while(t--)
	{
		c=4;
		sum_a=0;
		sum_b=0;
		cin>>m>>n;
		long long int a[m],b[m];
		for(i=0;i<m;i++)
			cin>>a[i];
		for(i=0;i<m;i++)
			cin>>b[i];
		if(n>2)
		{
			x=1;
			y=1;
			z=1;
			while(c<n)
			{
				z=(x+y)%1000000007;
				x=y%1000000007;
				y=z%1000000007;
				c++;
			}
			amul=z;
			c=4;
			x=1;
			y=2;
			z=n-2;
			while(c<n)
			{
				z=(x+y)%1000000007;
				x=y%1000000007;
				y=z%1000000007;
				c++;
			}
			bmul=z;
		}
		else if(n==1)
		{
			amul=1;
			bmul=0;
		}
		else
		{
			bmul=1;
			amul=0;
		}
		for(i=0;i<m;i++)
			sum_a=sum_a+a[i];
		for(i=0;i<m;i++)
			sum_b=sum_b+b[i];
		x=sum_a%1000000007;
		y=m%1000000007;
		z=amul%1000000007;
		ans1=(x*y)%1000000007;
		ans1=(ans1*z)%1000000007;
		x=sum_b%1000000007;
		y=m%1000000007;
		z=bmul%1000000007;
		ans2=(x*y)%1000000007;
		ans2=(ans2*z)%1000000007;
		ans=(ans1+ans2)%1000000007;
		cout<<ans<<"\n";
	}
	return 0;
}