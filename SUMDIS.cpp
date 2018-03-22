#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i,j,k,d,e;
    cin>>t;
    while(t--)
    {
        e=0;
        cin>>n;
        long long int a[n-1],b[n-2],c[n-3],s[n-1],ss[n-1];
        for(i=0;i<n-1;i++)
            cin>>a[i];
        for(i=0;i<n-2;i++)
            cin>>b[i];
        for(i=0;i<n-3;i++)
            cin>>c[i];
        s[0]=a[0];
        d=s[0];
        ss[0]=s[0];
        for(i=1;i<n-1;i++)
        {
            s[i]=s[i-1]+a[i];
            ss[i]=ss[i-1]+s[i];
            d=d+s[i];
        }
        //for(i=0;i<n-1;i++)
          //  cout<<s[i]<<" "<<ss[i]<<" ";
        //cout<<endl<<d<<endl;
        for(i=2;i<n;i++)
        {
            e=e+d-(n-i)*s[i-2]-ss[i-2];
        }
        cout<<e+d<<endl;
    }
    return 0;
}