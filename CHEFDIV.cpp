#include<bits/stdc++.h>
using namespace std;
long long int a[1000001]={0};
long long int tree(long long int n)
{
    long long int i,j,k,m=0,c=0;
    if(a[n]!=0)
        return a[n];
    if(n==1)
        return 1;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            if(m<tree(i))
                m=tree(i);
            c++;
        }
    }
    a[n]=c+m+1;
    return a[n];
}
int main()
{
    long long int a,b,i,j,k,s=0;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        k=tree(i)-1;
        s=s+k;
    }
    cout<<s;
    return 0;
}