#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,m,l1,l2,r1,r2,i,j,c,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long int a[n+1];
        for(i=1;i<n+1;i++)
            cin>>a[i];
        for(i=1;i<m+1;i++)
        {
            c=0;
            cin>>l1>>r1>>l2>>r2;
            s=r1-l1+1;
            long long q[s+1];
            for(j=1;j<s+1;j++)
                q[j]=j;
            do
            {
                for(j=1;j<s+1;j++)
                {
                    if(a[q[j]+l1-1]>a[j+l2-1])
                        break;
                }
                if(j==s+1)
                    c++;
            }while(next_permutation(q+1,q+s+1));
            cout<<(c%1000000007)<<"\n";
        }
    }
    return 0;
}