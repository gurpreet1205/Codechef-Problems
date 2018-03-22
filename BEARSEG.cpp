#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,p,i,j,k,c,d,m,cc,e,g;
    cin>>t;
    while(t--)
    {
        cc=0;
        cin>>n>>p;
        long long int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        b[0]=a[0];
        g=b[0]%p;
        m=g;
        for(i=1;i<n;i++)
        {
            b[i]=a[i]+b[i-1];
            e=b[i]%p;
            if(e>m)
            {
                m=e;
                cc=0;
            }
            if(e==m)
                cc++;
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                c=b[j]-b[i];
                d=c%p;
                if(d>m)
                {
                    m=d;
                    cc=0;
                }
                if(d==m)
                    cc++;
            }
        }
        if(b[0]%p==m)
            cc++;
        cout<<m<<" "<<cc<<endl;
    }
    return 0;
}