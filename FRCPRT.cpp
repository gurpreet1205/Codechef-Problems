#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,m,i,j,k,l,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		string s,str;
		char c1='y',c2='x',c3='z';
		long long int a[n]={0},b[n]={0},c[m]={0},d[m]={0};
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
			{
				if(s[j]=='1')
				{
					a[i]++;
					c[j]++;
					d[j]++;
				}
			}
		}
		cin>>str;
		l=str.length();
		long long int flag=0;
		x=0;
		for(i=0;i<l;i++)
		{
			if(str[i]=='L'||str[i]=='R')
			{
				c1=str[i];
				flag=1;
			}
			if(str[i]=='U'||str[i]=='D')
				c2=str[i];
			if(flag==1)
			{
				if(c2!='x'&&x==0)
				{
					for(j=0;j<n;j++)
					{
						a[j]=0;
						for(k=0;k<m;k++)
						{
							if(c[k]!=0)
							{
								a[j]++;
								c[k]--;
							}
						}
					}
					if(c2=='U')
					{
						for(j=0;j<n;j++)
							b[j]=a[j];
						sort(b,b+n);
						for(j=0;j<n;j++)
							a[j]=b[n-j-1];	
					}
					else
					{
						sort(a,a+n);
					}
				}
				x=1;
			if(str[i]=='U'||str[i]=='D')
			{
				/*for(j=0;j<n;j++)
					b[j]=a[j];
				sort(b,b+n);
				for(j=0;j<n;j++)
					a[j]=b[n-j-1];*/
				c3=str[i];
			}
			/*if(str[i]=='D')
			{
				sort(a,a+n);
			}*/
		}
		}
		if(c3!='z')
		{
			if(c3=='U')
			{
				for(j=0;j<n;j++)
					b[j]=a[j];
				sort(b,b+n);
				for(j=0;j<n;j++)
					a[j]=b[n-j-1];
			}
			if(c3=='D')
			{
				sort(a,a+n);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(c1=='L')
				{
					if(a[i]>j)
						cout<<1;
					else
						cout<<0;
				}
				else if(c1=='R')
				{
					if(j>=m-a[i])
						cout<<1;
					else
						cout<<0;
				}
				else
				{
					if(c2=='U')
					{
					if(d[j]!=0)
					{
						cout<<1;
						d[j]--;
					}
					else
						cout<<0;
					}
					else
					{
						if(d[j]>=n-i)
						{
							cout<<1;
						}
						else
							cout<<0;
					}
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}