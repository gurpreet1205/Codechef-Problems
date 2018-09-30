#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,j,k,f,m,mm=0,n;
	cin>>n;
	long long int l[n],r[n];
	char g[n];
	for(i=0;i<n;i++)
	{
		cin>>g[i]>>l[i]>>r[i];
	}
	for(i=1;i<=366;i++)
	{
		m=0,f=0;
		for(j=0;j<n;j++)
		{
			if(i>=l[j]&&i<=r[j])
			{
				if(g[j]=='M')
					m++;
				else
					f++;
			}
		}
		if(mm<min(m,f))
			mm=min(m,f);
	}
	cout<<mm<<"\n";
	return 0;
}