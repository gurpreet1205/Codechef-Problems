#include<bits/stdc++.h>
using namespace std;
long long int b[100001]={0},ans[100001]={0};
struct node{
	long long int l,r,val,temp,inx;
	struct node *left,*right;
}*start=NULL;
struct node * makeTree(long long int le,long long int ri)
{
	struct node *p=(struct node *)(malloc(sizeof(struct node)));
	p->l=le;
	p->r=ri;
	p->val=0;
	p->temp=0;
	p->inx=0;
	if(le==ri)
	{
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	p->left=makeTree(le,(ri+le)/2);
	p->right=makeTree((ri+le)/2+1,ri);
	return p;
}
/*void checkTree(struct node *p)
{
	if(p==NULL)
		return;
	cout<<p->l<<" "<<p->r<<" "<<p->val<<" "<<p->temp<<"\n";
	checkTree(p->left);
	checkTree(p->right);
}*/
void mergesort(long long int *a,long long int n,long long int *c)
{
    long long int b[n],d[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c);
    mergesort(a+x,n-x,c+x);
    long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            d[k]=c[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
    }
}
void initializeTree(struct node *p)
{
	if(p==NULL)
		return;
	p->val=0;
	p->temp=0;
	p->inx=0;
	//cout<<p->l<<" "<<p->r<<" "<<p->val<<" "<<p->temp<<"\n";
	initializeTree(p->left);
	initializeTree(p->right);
}
struct node * searchTree(long long int x)
{
	long long int m=0,y,z=0;
	struct node *p=start,*q=NULL;
	while(p!=NULL)
	{
		if(p->val>=m)
		{
			if((p->val==m&&p->temp<z)||(p->val>m))
			{
				q=p;
				z=p->temp;
			}
			m=p->val;
		}
		y=(p->l+p->r)/2;
		if(x>y)
			p=p->right;
		else
			p=p->left;
	}
	if(q==NULL)
	{
		q=(struct node *)(malloc(sizeof(struct node)));
		q->val=0;
		q->temp=0;
	}
	return q;
}
void fillTree(long long int le,long long int ri,struct node *p,long long int value,long long int x,long long int y)
{
	if(p->l>=le&&p->r<=ri)
	{
		if(value>=p->val)
		{
			p->val=value;
			p->temp=x;
			p->inx=y;
		}
		return;
	}
	if(p->r<le)
		return;
	else if(p->l>ri)
		return;
	else
	{
		fillTree(le,ri,p->left,value,x,y);
		fillTree(le,ri,p->right,value,x,y);
	}
}
void traverseTree(long long int index,long long int x,long long int y,long long int k,long long int n)
{
	long long int z=0,in;
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->temp==x&&p->val<y)
		{
			//z=z+y-p->val;
			p->val=y;
			in=p->inx;
			fillTree(max(in-k,(long long int)(1)),min(in+k,n),start,y,x,in);
		}
		if(index>(p->l+p->r)/2)
			p=p->right;
		else
			p=p->left;
	}
	//return z;
}
long long int calculateSum(long long int *a,long long int *in,long long int k,long long int n)
{
	if(k>=n+1)
		return 10000000000;
	if(ans[k]!=0)
		return ans[k];
	initializeTree(start);
	long long int l,r,i,j,x,s=0,y;
	struct node *p;
	for(i=0;i<n;i++)
		b[i]=0;
	b[0]=1;
	l=max(in[0]-k,(long long int)(1));
	r=min(in[0]+k,n);
	fillTree(l,r,start,1,a[0],in[0]);
	for(i=1;i<n;i++)
	{
		//checkTree(start);
		//cin>>aaa;
		p=searchTree(in[i]);
		x=p->val;
		if(x==0)
			b[i]=1;
		else
		{
			if(a[i]>p->temp)
				b[i]=x+1;
			else
				b[i]=x;
		}
		j=i;
		while(j>=1&&a[j]==a[j-1]&&(in[j]-in[j-1])<=k&&in[j-1]-in[j]<=k&&b[j]!=b[j-1])
		{
			traverseTree(in[i],a[i],b[i],k,n);
			s+=b[j]-b[j-1];
			b[j-1]=b[j];
			j--;
			//cout<<"a"<<s<<"a\n";
		}
		l=max(in[i]-k,(long long int)(1));
		r=min(in[i]+k,n);
		fillTree(l,r,start,b[i],a[i],in[i]);
	}
	/*for(i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1]&&(in[i+1]-in[i])<=k)
		{
			y=max(b[i],b[i+1]);
			b[i]=
		}
	}*/
	for(i=0;i<n;i++)
		s+=b[i];
	//cout<<k<<"\n";
	//for(i=0;i<n;i++)
		//cout<<b[i]<<" ";
	//cout<<"\n"<<s<<"\n";
	ans[k]=s;
	return s;
}
long long int binarySearch(long long int *a,long long int *in,long long int n,long long int s)
{
	long long int l,r,mid,x,y,z,aaa;
	l=0,r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		x=calculateSum(a,in,mid,n);
		//cout<<x<<" "<<y<<" "<<mid<<"\n";
		if(x<=s)
		{
			y=calculateSum(a,in,mid+1,n);
			if(y>s)
				return mid;
			else
				l=mid+1;
		}
		else
			r=mid-1;
	}
	return -1;
}


int main()
{
	long long int t,n,s,i,j,k,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		long long int a[n],in[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			in[i]=i+1;
		}
		mergesort(a,n,in);
		for(i=0;i<=n;i++)
			ans[i]=0;
		ans[0]=n;
		ans[n]=1;
		for(i=1,j=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				ans[n]+=j;
			else
			{
				j++;
				ans[n]+=j;
			}
		}
		ans[n-1]=ans[n];
		start=makeTree(1,n);
		//check(start);
		//initializeTree(start);
		//fillTree(5,9,start,1,10);
		//struct node *p=searchTree(9);
		//cout<<p->l<<" "<<p->r<<" "<<p->val<<" "<<p->temp;
		//checkTree(start);
		x=binarySearch(a,in,n,s);
		cout<<x+1<<"\n";
	}
	return 0;
}