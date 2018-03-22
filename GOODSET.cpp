#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<n*2;i=i+2)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}