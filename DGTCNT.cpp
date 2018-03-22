#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,j,k,l,r,p,c,a[10],b[10],d;
    cin>>t;
    while(t--)
    {
        d=0;
        cin>>l>>r;
        for(i=0;i<10;i++)
            cin>>a[i];
        for(i=l;i<=r;i++)
        {
            for(j=0;j<10;j++)
            b[j]=0;
            p=i;
            while(p>0)
            {
                c=p%10;
                p=p/10;
                b[c]++;
            }
            for(j=0;j<10;j++)
            {
                if(a[j]==b[j])
                {
                    d++;
                    break;
                }
            }
        }
        d=r-l+1-d;
        cout<<d<<endl;
    }
    return 0;
}