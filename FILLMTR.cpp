#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int data;
	struct node *next;	
};
void mergesort(long long int *a,long long int n,long long int *c,long long int *val)
{
    long long int b[n],d[n],e[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,val);
    mergesort(a+x,n-x,c+x,val+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=val[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=val[i];
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
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        val[i]=e[i];
    }
}
int main()
{
	long long int t,n,q,i,j,k,temp,e,m,M;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		long long int r[q],c[q],val[q];
		for(i=0;i<q;i++)
		{
			cin>>r[i]>>c[i]>>val[i];
			if(r[i]>c[i])
			{
				temp=r[i];
				r[i]=c[i];
				c[i]=temp;
			}
		}
		struct node *arr[n+1]={NULL};
		mergesort(r,q,c,val);
		/*for(i=0;i<q;i++)
		{
			cout<<r[i]<<" ";
		}
		cout<<"\n";*/
		for(i=1;i<n+1;i++)
		{
			struct node *p=(struct node *)malloc(sizeof(struct node));
			arr[i]=p;
			p->data=i;
			p->next=NULL;
		}
		struct node *qq;
		for(i=0;i<q;i++)
		{
			struct node *p=(struct node *)malloc(sizeof(struct node));
			if(i==0||r[i]!=r[i-1])
			{
				arr[r[i]]->next=p;
				qq=p;
			}
			else
			{
				qq->next=p;
				qq=p;
			}
				p->data=c[i];
				p->next=NULL;
		}
		/*struct node *p;
		for(i=0;i<q;i++)
		{
				p=arr[r[i]];
				cout<<r[i]<<":";
				while(p!=NULL)
				{
					cout<<p->data<<" ";
					p=p->next;
					i++;
				}
				cout<<"\n";
		}*/
		long long int a[n+1],b[n+1];
		for(i=0;i<n+1;i++)
		{
			a[i]=-1;
			b[i]=-1;
		}
		//cout<<"b";
		a[r[0]]=0;
		b[r[0]]=r[0];
		//cout<<"c";
		for(i=0;i<q;i++)
		{
			//cout<<r[i]<<" "<<c[i]<<"\n";
			if(r[i]==c[i])
			{
				if(val[i]!=0)
					break;	
			}
			else if(a[r[i]]==-1||a[c[i]]==-1)
			{
			//	cout<<"a";
				if(a[r[i]]==-1&&a[c[i]]==-1)
				{
					a[r[i]]=0;
					a[c[i]]=val[i];
					b[r[i]]=r[i];
					b[c[i]]=r[i];
				}
				else if(a[r[i]]==-1)
				{
					if(a[c[i]]==0)
						a[r[i]]=val[i];
					else
						a[r[i]]=a[c[i]]-val[i];
					b[r[i]]=b[c[i]];
				}
				else
				{
					if(a[r[i]]==0)
						a[c[i]]=val[i];
					else
						a[c[i]]=a[r[i]]-val[i];
					b[c[i]]=b[r[i]];
				}
			}
			else
			{
				if((val[i]==0&&a[r[i]]!=a[c[i]])||(val[i]==1&&a[r[i]]==a[c[i]]))
				{
					if(b[r[i]]==b[c[i]])
						break;
					else
					{
						m=b[r[i]]>b[c[i]]?b[c[i]]:b[r[i]];
						M=b[r[i]]<b[c[i]]?b[c[i]]:b[r[i]];
						/*while(p!=NULL)
						{
							if(p->data==M)
								e=1;
							if(a[p->data]==0)
								a[p->data]=1;
							else
								a[p->data]=0;
							b[p->data]=m;
							p=p->next;
						}
						if(e==0)
						{
							if(a[M]==0)
								a[M]=1;
							else
								a[M]=0;
							b[M]=m;
						}*/
						long long int stck[n],visit[n+1]={0};
						stck[0]=M;
						visit[M]=1;
						k=0;
						while(1)
						{
							if(k==-1)
							break;
							struct node *p=arr[stck[k]];
							if(b[p->data]!=m)
							{
							if(a[p->data]==0)
								a[p->data]=1;
							else
								a[p->data]=0;
							b[p->data]=m;
							k--;
							while(p!=NULL)
							{
								if(visit[p->data]==0)
								{
									stck[++k]=p->data;
									visit[p->data]=1;
								}
								p=p->next;
							}
							}
							else
							{
								visit[p->data]=1;
								k--;
							}
						}
					}
				}
				else
				{
					if(b[r[i]]!=b[c[i]])
					{
						m=b[r[i]]>b[c[i]]?b[c[i]]:b[r[i]];
						M=b[r[i]]<b[c[i]]?b[c[i]]:b[r[i]];
						//cout<<"M:"<<M<<"\n";
						struct node *p=arr[M];
						long long int stck[n],visit[n+1]={0};
						stck[0]=M;
						visit[M]=1;
						k=0;
						while(1)
						{
							if(k==-1)
							break;
							//cout<<k<<"\n";
							struct node *p=arr[stck[k]];
							//cout<<"a/n";
							if(b[p->data]!=m)
							{
							b[p->data]=m;
							k--;
							while(p!=NULL)
							{	
								if(visit[p->data]==0)
								{
									stck[++k]=p->data;
									visit[p->data]=1;
									//cout<<stck[k]<<" ";
								}
								p=p->next;
							}
							//cout<<"\n";
							}
							else
							{
								visit[p->data]=1;
								k--;
							}
						}
					}
				}
			}
			/*for(j=0;j<n+1;j++)
				cout<<a[j]<<" ";
			cout<<"\n";
			for(j=0;j<n+1;j++)
				cout<<b[j]<<" ";
			cout<<"\n";*/
		}
		if(i==q)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
} 