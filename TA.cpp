#include<bits/stdc++.h>
using namespace std;
long long int a[201]={0},b[201]={0};
int main()
{
	long long int p,q,x,y,i,j,flag=0;
	cin>>x>>p;
	cin>>y>>q;
	while(1)
	{
		if(q==p)
		{
			flag=1;
			break;
		}
		if(q<p)
		{
			if(a[p-q]==1)
				break;
			a[p-q]=1;
			q=q+y;
		}
		if(p<q)
		{
			if(b[q-p]==1)
				break;
			b[q-p]=1;
			p=p+x;
		}
	}
	if(flag==1)
		cout<<p<<"\n";
	else
		cout<<"-1\n";
}