#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t,i,j,k,c,d,e;
cin>>t;
while(t--)
{
c=0;
d=0;
e=0;
char s1[501],s2[501];
long long int a[26]={0},b[26]={0};
cin>>s1;
fflush(stdin);
cin>>s2;
i=0;
while(s1[i]!='\0')
{
a[s1[i]-97]++;
b[s2[i]-97]++;
i++;
}
for(i=0;i<26;i++)
{
if(((a[i]==0)&&(b[i]!=0))||((a[i]!=0)&&(b[i]==0)))
c=1;
if(a[i]>1&&b[i]==0)
{
e=1;
break;
}
if(a[i]==0&&b[i]!=0)
d=1;
}
if(e==1||(d==0&&c==1))
cout<<"A\n";
else
cout<<"B\n";
}
return 0;
} 