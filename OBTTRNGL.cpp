#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t,i,j,a,b,c,count,d1,d2;
double e,an,k;
cin>>t;
while(t--)
{
count=0;
cin>>k>>a>>b;
d1=max(a-b,b-a);
d2=k-d1;
//an=(180*(k-2))/k;
//an=an/(k-2);
//c=90/an;
c=k/2;
c++;
if(d1>=c)
count=d2-1;
if(d2>=c)
count=count+d1-1;
cout<<count<<"\n";
}
return 0;
} 