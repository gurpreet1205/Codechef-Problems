#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,q,i,j,k,ch,in,l,r,c,x;
cin>>n>>q;
long long int a[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<q;i++)
{
cin>>ch;
if(ch==1)
{
cin>>in>>k;
c=0;
for(j=in;j<n;j++)
{
if((a[in-1]<a[j])&&(j-in+1<=100))
{
in=j+1;
c++;
}
if(c==k)
break;
}
cout<<in<<"\n";
}
else
{
cin>>l>>r>>x;
for(j=l-1;j<r;j++)
a[j]=a[j]+x;
}
}
return 0;
} 