#include<bits/stdc++.h>
using namespace std;
long long int c[5001][5001];
int strmrg(char *a,char *b,int n,int m)
{
	if(c[n][m]!=0)
		return c[n][m];
	long long int i,j,x;
	if(n==0&&m==0)
		return 0;
	if(n==0)
	{
		x=1;
		for(i=0;i<m-1;i++)
		{
			if(b[i]!=b[i+1])
				x++;
		}
		return x;
	}
	if(m==0)
	{
		x=1;
		for(i=0;i<n-1;i++)
		{
			if(a[i]!=a[i+1])
				x++;
		}
		return x;
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
			break;
	}
	for(j=0;j<m-1;j++)
	{
		if(b[j]!=b[j+1])
			break;
	}
	if(a[0]==b[0])
		c[n][m]=1+strmrg(a+i+1,b+j+1,n-i-1,m-j-1);
	else
		c[n][m]=1+min(strmrg(a+i+1,b,n-i-1,m),strmrg(a,b+j+1,n,m-j-1));
	return c[n][m];
}
int main()
{
	long long int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		char a[n],b[m];
		fflush(stdin);
		cin>>a;
		fflush(stdin);
		cin>>b;
		for(i=0;i<n+1;i++)
		{
			for(j=0;j<m+1;j++)
				c[i][j]=0;
		}
		cout<<strmrg(a,b,n,m)<<"\n";
	}
	return 0;
} 