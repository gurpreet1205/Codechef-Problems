#include<bits/stdc++.h>
using namespace std;
long long int a[1000000],in=0;
struct query
{
	long long int l,r,z;
	struct query *left;
	struct query *right;
};
void create_seg(struct query *p,long long int first,long long int last)
{
	p->l=first;
	p->r=last;
	p->z=0;
	if(first==last)
	{
		p->left=NULL;
		p->right=NULL;
		return;
	}
	struct query *q=(struct query *)malloc(sizeof(struct query));
	struct query *s=(struct query *)malloc(sizeof(struct query));
	long long int mid;
	mid=(last+first)/2;
	p->left=q;
	p->right=s;
	create_seg(p->left,first,mid);
	create_seg(p->right,mid+1,last);
}
long long int find(struct query *p,long long int k)
{
	if(p==NULL)
	return 0;
	long long int mid=(p->r+p->l)/2;
	if(k<=mid)
		return (p->z+find(p->left,k))%1000000007;
	else
		return (p->z+find(p->right,k))%1000000007;
}
void segtree(struct query *p,long long int ll,long long int rr,long long int y)
{
	//cout<<p->l<<" "<<p->r<<"\n";
	if(rr<p->l||ll>p->r)
		return;
	if(ll<=p->l&&rr>=p->r)
	{
		p->z=(p->z+y)%1000000007;
		return;
	}
	segtree(p->left,ll,rr,y);
	segtree(p->right,ll,rr,y);
}
int main()
{
	struct query *p=(struct query *)malloc(sizeof(struct query));
	struct query *q=(struct query *)malloc(sizeof(struct query));
	long long int t,n,m,i,j,k,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long int x[m],l[m],r[m],a[m];
		for(i=0;i<m;i++)
		{
			cin>>x[i]>>l[i]>>r[i];
		}
		//struct query a[2*m-1]={0};
		create_seg(p,1,m);
		for(i=m;i>0;i--)
		{
				segtree(p,i,i,1);
				//cout<<"b\n";
			if(x[i-1]==2)
			{
				y=find(p,i)%1000000007;
				segtree(p,l[i-1],r[i-1],y);
			}
			//cout<<"a";
		}
		//cout<<"\n";
		for(i=1;i<=m;i++)
		{
			a[i-1]=find(p,i)%1000000007;
			//cout<<a[i-1]<<" ";
		}
		//cout<<"\n";
		create_seg(q,1,n);
		for(i=0;i<m;i++)
		{
			if(x[i]==1)
			{
				segtree(q,l[i],r[i],a[i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			cout<<find(q,i)%1000000007<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 