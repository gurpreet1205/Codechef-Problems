#include<bits/stdc++.h>
using namespace std;
long long int power(long long int a,long long int b,long long int p)
{
	long long int x,y,z,q,r;
	if(b==0)
		return 1;
	if(a>1000000000)
	{
		x=floor(a/1000000000);
		z=a-100000000*x;
		y=(((1000000000000000000%p)*x*x)%p+(((2*1000000000*x)%p)*z)%p+(z*z)%p)%p;
	}
	else
		y=(a*a)%p;
	if(b%2==0)
		return (power(y,b/2,p))%p;
	else
	{
		q=power(y,(b-1)/2,p);
		if(q>1000000)
		{
			x=floor(q/1000000);
			z=q-1000000*x;
			r=((a%p)*((1000000*x)%p))%p+
		}
		return (a*power(y,(b-1)/2,p))%p;
	}
}
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	long long int t,a,b,n,i,j,x,y,z,p;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		p=a-b;
		if(p==0)
		{
			x=power(a,n,1000000007);
			y=power(b,n,1000000007);
			z=(x+y)%1000000007;
			cout<<z<<"\n";
		}
		else
		{
			x=power(a,n,p);
			y=power(b,n,p);
			z=(x+y)%p;
			cout<<gcd(p,z)%1000000007<<"\n";
		}
	}
	return 0;
} 