#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,x,y,i;
	cin>>n>>k;
	x=(n+1)/2;
	for(i=x;i<=n;i++)
	{
		if(i%k==0)
			break;
	}
	if(i==n+1)
		cout<<-1<<"\n";
	else
		cout<<i<<"\n";
	return 0;
}