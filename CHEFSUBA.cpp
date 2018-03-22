#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,p,i,j,m,c,q,r,qq;
    multiset<long long int>myset;
    multiset<long long int>::iterator it;
    cin>>n>>k>>p;
    long long int a[n],b[n],ans[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
            b[i]=a[i];
        else
            b[i]=b[i-1]+a[i];
    }
    myset.insert(b[k-1]);
    for(i=0;i<n-k;i++)
    {
        c=b[k+i]-b[i];
        myset.insert(c);
    }
    it=myset.end();
    it--;
    ans[0]=*it;
    //for(it=myset.begin();it!=myset.end();it++)
      //  cout<<*it<<" ";
    //cout<<endl;
    char s[p];
    cin>>s;
    if(k>=n)
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='?')
                cout<<b[n-1]<<endl;
        }
    }
    else
    {
    j=0;
    q=1;
    qq=-1;
    r=0;
    for(i=0;s[i]!='\0';i++)
    {
        it=myset.end();
        it--;
        if((s[i]=='?')&&(j<n))
            cout<<*it<<endl;
        else if((s[i]=='!')&&(j<n-1))
        {
            j++;
            if(j<=n-k)
            c=b[n-j]-b[n-k-j];
            else
            {
                r++;
                c=b[n-j]+b[n-1]-b[n-r];
            }
            it=myset.find(c);
            myset.erase(it);
            if(j<k)
            c=b[k-j-1]+b[n-1]-b[n-j-1] ;
            else
            {
                c=b[n-q]-b[n-k-q];
                q++;
            }
            myset.insert(c);
            it=myset.end();
            it--;
            ans[j]=*it;
            //for(it=myset.begin();it!=myset.end();it++)
            //cout<<*it<<" ";
            //cout<<endl;
        }
        else
        {
            if(s[i]=='?')
            {
                cout<<ans[qq]<<endl;
            }
            else
            {
                if(qq==-1)
                j++;
                qq++;
                if(qq==j)
                qq=0;
            }
        }
    }
    }
    return 0;
}