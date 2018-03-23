#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,q,i,j,k,p;
cin>>n>>q;
long long int b[n][n],a[n],s[n]={0},c[n];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
cin>>b[i][j];
}
for(i=0;i<n;i++)
{
if(b[0][i]!=0)
break;
}
if(i==n)
{
for(j=0;j<n;j++)
cout<<"0 ";
cout<<"\n";
}
else
{
for(j=0;j<i;j++)
cout<<"0 ";
s[i]=1;
for(j=i+1;j<n;j++)
{
if(b[0][i]+b[0][j]==b[i][j])
s[j]=0;
else
s[j]=1;
}
for(j=i;j<n;j++)
{
if(s[j]==1)
cout<<b[0][j]*(-1)<<" ";
else
cout<<b[0][j]<<" ";
}
cout<<"\n";
}
for(i=0;i<q;i++)
{
cin>>p;
for(j=0;j<n;j++)
cin>>c[j];
for(j=0;j<n;j++)
{
b[j][p-1]=c[j];
b[p-1][j]=c[j];
}
for(j=0;j<n;j++)
{
if(b[0][j]!=0)
break;
}
if(j==n)
{
for(j=0;j<n;j++)
cout<<"0 ";
cout<<"\n";
}
else
{
for(k=0;k<j;k++)
cout<<"0 ";
s[j]=1;
for(k=j+1;k<n;k++)
{
if(b[0][k]+b[0][j]==b[j][k])
s[k]=0;
else
s[k]=1;
}
for(k=j;k<n;k++)
{
if(s[k]==1)
cout<<b[0][k]*(-1)<<" ";
else
cout<<b[0][k]<<" ";
}
cout<<"\n";
}
}
return 0;
} 