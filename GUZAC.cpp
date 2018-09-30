#include<bits/stdc++.h>
using namespace std;
long long int binarySearch(long long int *a,long long int n,long long int x)
{
	long long int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		{
			return 1;
		}
		if(a[mid]<x)
		{
			low=mid+1;
		}
		else
			high=mid-1;
	}
	return 0;
}
int main()
{
	long long int t,n,i,j,k,x,y,z,p,q,r,ans,s;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>k>>x;
		long long int a[k];
		for(i=0;i<k;i++)
			cin>>a[i];
		sort(a,a+k);
		for(i=0;i<k;i++)
			ans+=a[i];
		y=a[k-1]-a[0];
		if(y<x)
		{
			z=a[0]+x;
		}
		else
			z=a[k-1];
		p=(z*(z+1))/2;
		q=z-n;
		r=(q*(q+1))/2;
		s=p-r;
		long long int b[k],c=0,d;
		for(i=0,j=q+1;i<k;i++,j++)
		{
			s=s-j+a[i];
			if(a[i]>j)
			{
				b[c++]=a[i];
			}
		}
		d=j-1;
		for(i=0;i<c;i++)
		{
			if(b[i]>=j)
			{
				while(binarySearch(a,k,d)==1)
				{
					d--;
				}
				s=s-b[i]+d;
				d--;
			}

		}
		cout<<s<<"\n";
	}
	return 0;
}