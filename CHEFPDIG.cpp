#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j;
	cin>>t;
	while(t--)
	{
		char c[1000005];
		long long int a[10]={0};
		fflush(stdin);
			cin>>c;
		i=0;
		while(c[i]!='\0')
		{
			a[c[i]-'0']++;
			i++;
		}
		for(i=6;i<9;i++)
		{
			if(i==6)
			j=5;
			else
			j=0;
			for(;j<10;j++)
			{
				if(i==j&&a[i]>1)
				cout<<(char)(i*10+j);
				else if(i!=j&&a[i]>0&&a[j]>0)
				cout<<(char)(i*10+j);
			}
		}
		if(a[9]>0&&a[0]>0)
		cout<<"Z";
		cout<<"\n";
	}
	return 0;
} 