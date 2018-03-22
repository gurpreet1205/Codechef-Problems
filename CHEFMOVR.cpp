#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t,n,i,j,k,d,sum,x,y;
cin>>t;
while(t--)
{
cin>>n>>d;
sum=0;
y=0;
long long int a[n];
for(i=0;i<n;i++)
{
cin>>a[i];
sum=sum+a[i];
}
if(sum%n!=0)
cout<<"-1\n";
else
{
x=sum/n;
long long int s[d]={0};
for(i=0;i<d;i++)
{
k=0;
for(j=i;j<n;j=j+d)
{
s[i]=s[i]+a[j];
k++;
}
if(s[i]!=k*x)
break;
else
{
for(j=i;j<n-d;j=j+d)
{
if(a[j]>x)
{
y=y+a[j]-x;
a[j+d]=a[j+d]+a[j]-x;
}
else
{
y=y+x-a[j];
a[j+d]=a[j+d]+a[j]-x;
}
}
}
}
if(i==d)
cout<<y<<"\n";
else
cout<<"-1\n";
}
}
return 0;
} 