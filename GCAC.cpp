#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,m,i,j,k,t,c,h,sum,co;
cin>>t;
while(t--)
{
h=0;
sum=0;
co=0;
cin>>n>>m;
long long int ms[n],os[m],jo[m],a[m],s[n]={0};
char qual[n][m];
for(i=0;i<n;i++)
cin>>ms[i];
for(i=0;i<m;i++)
{
cin>>os[i]>>jo[i];
a[i]=jo[i];
}
//cout<<jo[0]<<"\n";
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
cin>>qual[i][j];
fflush(stdin);
}
//cout<<jo[0]<<"\n";
for(i=0;i<n;i++)
{
c=-1;
for(j=0;j<m;j++)
{
if((qual[i][j]=='1')&&(ms[i]<=os[j])&&(jo[j]>0))
{
if(s[i]<os[j])
{
s[i]=os[j];
c=j;
}
}
}
//cout<<jo[0]<<"\n";
if(c!=-1)
{
h++;
jo[c]=jo[c]-1;
//cout<<i<<" "<<c<<" "<<jo[c]<<"\n";
}
}
for(i=0;i<n;i++)
sum=sum+s[i];
for(i=0;i<m;i++)
{
if(a[i]==jo[i])
co++;
}
cout<<h<<" "<<sum<<" "<<co<<"\n";
}
return 0;
} 