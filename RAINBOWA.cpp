#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i,j,k,e;
    cin>>t;
    while(t--)
    {
        e=0;
        cin>>n;
 
 
        long long int a[n],b[8]={0};
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if((a[i]>7)||(a[i]<1))
               e=1;
        }
        if(e==1)
            cout<<"no\n";
        else
        {
            for(i=0;i<(n-1)/2;i++)
            {
                b[a[i]]=1;
                if(a[i]>a[i+1])
                {
                    e=1;
                    break;
                }
            }
            b[a[i]]=1;
            if(e==1)
                cout<<"no\n";
            else
            {
                for(i=1;i<8;i++)
                {
                    if(b[i]==0)
                        break;
                }
                if(i<8)
                    cout<<"no\n";
                else
                {
                    for(i=0;i<n/2;i++)
                    {
                        if(a[i]!=a[n-i-1])
                        {
                            e=1;
                            break;
                        }
                    }
                    if(e==1)
                        cout<<"no\n";
                    else
                        cout<<"yes\n";
                }
            }
        }
    }
    return 0;
} 