#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int data,value;
	struct node *next;	
};
long long int a[5000][8192];
int main()
{
	long long int n,q,i,j,k,u,v,l,sum,d,z;
	cin>>n>>q;
	if(n==1)
	{
		cin>>z;
		for(i=0;i<q;i++)
		{
			cin>>d;
			cout<<z<<"\n";
		}
	}
	else
	{
	struct node *arr[n]={NULL};
	long long int aa[n];
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		struct node *p=(struct node *)malloc(sizeof(struct node));
		struct node *q=(struct node *)malloc(sizeof(struct node));
		p->next=arr[u];
		arr[u]=p;
		q->next=arr[v];
		arr[v]=q;
		p->data=v;
		q->data=u;
	}
	for(i=0;i<n;i++)
	{
		cin>>aa[i];
	}
	for(i=0;i<n;i++)
	{
		struct node *p=arr[i];
		while(p!=NULL)
		{
			p->value=aa[p->data];
			p=p->next;
		}
	}
	/*for(i=0;i<n;i++)
	{
		struct node *p=arr[i];
		//cout<<p->data<<":";
		while(p!=NULL)
		{
			cout<<p->data<<" "<<p->value<<" ";
			p=p->next;
		}
		cout<<"\n";
	}*/
	struct node *p=arr[0];
	long long int queue[n];
	long long int visit[n]={0};
	long long int b[n]={0};
	long long int x[n]={0};
	queue[0]=0;
	visit[0]=1;
	i=0;
	l=0;
	b[l]=1;
	x[0]=aa[0];
	k=0;
	l=1;
	sum=1;
	i=1;
	while(1)
	{
		p=arr[queue[k]];
		k++;
		while(p!=NULL)
		{
			if(visit[p->data]==0)
			{
				x[l]=x[l]^(p->value);
				b[l]++;
				visit[p->data]=1;
				queue[i++]=p->data;
			}
			//cout<<p->data<<" "<<p->value<<"\n";
			p=p->next;
		}
		if(k==sum)
		{
			l++;
			sum=sum+b[l-1];
		}
		//cout<<k<<" "<<sum<<"\n";
		if(k==n)
			break;
	}
	l--;
	/*for(i=0;i<l;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<"\n";*/
	for(i=0;i<8192;i++)
	{
		a[0][i]=1;
		if(i<5000)
			a[i][0]=1;
	}
	for(i=1;i<5000;i++)
	{
		for(j=1;j<8192;j++)
		{
			if(a[i-1][j]==a[i][j-1])
				a[i][j]=0;
			else
				a[i][j]=1;
		}
	}
	/*for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}*/
	long long int y[8193]={0};
	y[0]=aa[0];
	for(i=0;i<8192;i++)
	{
		for(j=0;j<l;j++)
		{
			if(a[j][i]==1)
				y[i+1]=y[i+1]^x[j];
		}
	}
	//cout<<l<<"\n";
	for(i=0;i<q;i++)
	{
		cin>>d;
		if(d==0)
			cout<<y[0]<<"\n";
		else
		{
			d=d%8192;
			if(d==0)
				d=8192;
			cout<<y[d]<<"\n"; 
		}
	}
	}
	return 0;
} 