#include<bits/stdc++.h>
using namespace std;
long long int a[10000000]={0};
long long int rec(long long int n)
{
	if(n==0||n==1)
		return n;
	//cout<<n<<"\n";
	long long int x,y,z;
	if(n<10000000&&a[n]!=0)
		return a[n];
	x=rec(n/2);
	y=rec(n/3);
	z=rec(n/4);
	if(n<10000000)
	{
	a[n]=max(n,(x+y+z));
	return a[n];
	}
	else
		return max(n,(x+y+z));
		
}
int main()
{
	long long int n;
	while(scanf("%lld",&n)==1)
	{
	cout<<rec(n)<<"\n";
	}
	return 0;
} 