#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,u,v,n,r;
    cin>>t;
    while(t--)
    {
        cin>>u>>v;
        n=u+v;
        r=(n*(n+1))/2+u+1;
        cout<<r<<endl;
    }
    return 0;
}