#include<bits/stdc++.h>
using namespace std;
long long int l[40000]={0},r[40000]={0};
void mergesort(long long int *a,long long int n,long long int *c,long long int *val,long long int *aa,long long int *cc)
{
    long long int b[n],d[n],e[n],g[n],h[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,val,aa,cc);
    mergesort(a+x,n-x,c+x,val+x,aa+x,cc+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]<a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=val[j];
            g[k]=aa[j];
            h[k]=cc[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=val[i];
            g[k]=aa[i];
            h[k]=cc[i];
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
            e[k]=val[j];
            g[k]=aa[j];
            h[k]=cc[j];
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
            e[k]=val[i];
            g[k]=aa[i];
            h[k]=cc[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        val[i]=e[i];
        aa[i]=g[i];
        cc[i]=h[i];
    }
}
long long int max(long long int a,long long int b)
{
	if(a>b)
	 return a;
	else
	 return b;
}
long long int max_sub(long long int *a,long long int n,long long int x)
{
	/*for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";*/
	long long int i=0,j=0,k,s=0;
	for(k=0;k<n;k++)
	{
		i=max(i+a[k],0);
		j=max(i,j);
		if(j==i)
			r[x]=k;
	}
	for(k=r[x];k>=0;k--)
	{
		s=s+a[k];
		if(s==j)
			break;
	}
	l[x]=k;
	return j;
}
int main()
{
	long long int t,n,i,j,k,z,c,q,p,rr,cc,hh,h;
	cin>>t;
	while(t--)
	{
		long long int dd[200];
		c=0;
		cc=0;
		q=0;
		cin>>n;
		char b[n][n];
		long long int a[n][n],d[n*n],z[n*n],o[n];
		for(i=0;i<n;i++)
		{
			d[i]=i;
			fflush(stdin);
			for(j=0;j<n;j++)
				cin>>b[i][j];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(b[i][j]=='0')
					a[i][j]=-1;
				else
				{
					a[i][j]=1;
					c++;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			cc=0;
			for(j=0;j<n;j++)
			{
				if(a[j][i]==1)
					cc++;
			}
			o[i]=cc;
		}
		long long int m[n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				z[j]=a[j][i];
			m[i]=max_sub(z,n,i);
		}
		mergesort(m,n,l,r,d,o);
		i=0;
		rr=0;
		while(c>3)
		{
			c=c-m[i];
			p=r[i]-l[i]+1;
			hh=(p-m[i])/2;
			h=p-hh;
			rr=rr+hh+o[i]-h;
			if(rr>3)
				break;
			i++;
			q++;
		}
		if(rr>3)
		{
		p=0;
		for(j=i;j<n;j++)
			dd[j]=d[j];
		for(j=i;j<n;j++)
		{
			rr=dd[j];
			p=0;
			for(k=0;k<n;k++)
			{
				if(a[k][rr]==1)
					p++;
				if(a[k][rr]==-1||k==n-1)
				{
					if(p!=0)
					{
						d[q]=rr;
						l[q]=k-p+(k==n-1);
						r[q]=k-1+(k==n-1);
						q++;
					}
					p=0;
				}
			}
		}
		}
		cout<<q<<"\n";
		/*for(i=0;i<n;i++)
		{
			cout<<d[i]+1<<" "<<l[i]+1<<" "<<r[i]+1<<"\n";
		}
		cout<<"\n";*/
		for(j=q-1;j>=0;j--)
		{
			cout<<"0 1 0 1 0 1 "<<d[j]+1<<" "<<l[j]+1<<" "<<r[j]+1<<"\n";
		}
	}
	return 0;
} 