#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,x,y,z,p,q,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
			cout<<2<<"\n";
		else
		{
			x=floor(log(n)/log(2));
			y=n-pow(2,x);
			if(y==0)
				cout<<1<<"\n";
			else
			{
				z=floor(log(y)/log(2));
				p=pow(2,z);
				q=y-p;
				r=pow(2,z+1)-y;
				if(z+1==x)
					r++;
				cout<<min(q,r)<<"\n";
			}
		}
	}
	return 0;
}