#include<bits/stdc++.h>
using namespace std;
//set<long long int>myset;
//long long int sum=0;
long long int rec(long long int *a,long long int n)
{
long long int i,x,e[n+1],b[n+1],j,y,sum=0;
for(i=0;i<n;i++)
{
e[i]=a[i];
b[i]=a[i];
//cout<<e[i];
}
e[n]=0;
b[n]=0;
//cout<<"\n";
if(n==1)
{
return 1;
}
if(e[0]<e[1])
x=e[0];
else
x=e[1];
sum=rec(b+1,n-1);
for(i=0;i<x;i++)
{
//cout<<x<<"\n";
//for(j=0;j<n+1;j++)
//cout<<b[j]<<" ";
//cout<<"\n";
e[1]=e[1]-1;
b[1]=b[1]-1;
e[2]=e[2]+1;
b[2]=b[2]+1;
if(n>2)
sum=sum+rec(b+1,n-1);
else
sum=sum+rec(b+1,n);
}
//for(j=0;j<n+1;j++)
//cout<<c[j]<<" ";
//cout<<"\n"<<sum<<"\n";
if(sum>1000000007)
sum=sum%1000000007;
return sum;
}
int main()
{
long long int t,i,n,sum;
cin>>t;
while(t--)
{
cin>>n;
long long int a[n];
for(i=0;i<n;i++)
cin>>a[i];
sum=rec(a,n)%1000000007;
cout<<sum<<"\n";
 
}
return 0;
} 