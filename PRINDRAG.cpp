#include<bits/stdc++.h>
using namespace std;
long long int a[100001],s=0,n;
void rec(long long int l,long long int r,long long int j,long long int le,long long int ri)
{
	long long int x,y;
	if(le<=0)
	{
		for(x=j,y=r;x>=0&&y<n;x--,y++)
		{
			ri=ri-a[x];
			if(ri<=0)
				break;
		}
		s=max(s,l+2+n-y);
		return;
	}
	if(ri<=0)
	{
		for(x=j,y=l;x>=0&&y>=0;x--,y--)
		{
			le=le-a[x];
			if(le<=0)
				break;
		}
		s=max(s,n-r+1+y+1);
		return;
	}
	if(l<0||r>=n)
		return;
	rec(l-1,r,j-1,le-a[j],ri);
	rec(l,r+1,j-1,le,ri-a[j]);
}
int main()
{
	long long int t,p,i,j,le,ri,sum,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		le=p-a[n-1];
		ri=le;
		if(le==0)
		{
			for(i=0;i<n;i++)
				cout<<n<<" ";
			cout<<"\n";
		}
		else
		{
			sum=0;
			for(i=n-1;i>=0;i--)
			{
				sum=sum+a[i];
				if(sum>=p)
					break;
			}
			x=i+1;
			cout<<x<<" ";
			for(i=1;i<n-1;i++)
			{
				s=0;
				rec(i-1,i+1,n-2,le,ri);
				cout<<s<<" ";
			}
			if(n>1)
				cout<<x;
			cout<<"\n";
		}
	}
	return 0;
}