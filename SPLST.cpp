#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,j,k,n,a,b,c,x,y;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>x>>y;
		i=min(x,y);
		j=min(min(a,b),c);
		if(a+b+c!=x+y)
			cout<<"NO\n";
		else
		{
			if(i>=j)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}