#include<bits/stdc++.h>
using namespace std;
//long long int a[31];
//double b[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k,i,j,p,q,r,l;
    cin>>n>>k;
    long long int a[n];
    double b[n];
    list<long long int>e;
    list<double>d;
    list<long long int>::iterator itr,itr1;
    list<double>::iterator it,it1;
    double c,s;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        //a[i]=i+1;
    }
    c=log(k);
    sort(a,a+n);
    for(i=0;i<n;i++)
        b[i]=log(a[i]);
    if(a[0]>k)
        cout<<0;
    else
    {
    //d[0]=b[0];
    //e[0]=a[0];
    d.push_back(b[0]);
    e.push_back(a[0]);
    j=0;
    for(i=1;i<n;i++)
    {
        l=e.size();
        /*if(i==3)
        {
            cout<<l<<endl;
            for(itr=e.begin();itr!=e.end();itr++)
                cout<<*(itr)<<" ";
            cout<<endl;
        }*/
        it=d.begin();
        itr=e.begin();
        r=j+1;
        if(b[i]<=c&&(a[i]<=k))
        {
            //d[r]=b[i];
            //e[r]=a[i];
            d.push_back(b[i]);
            e.push_back(a[i]);
            r++;
        for(q=0;q<l;q++)
        {
            //cout<<*(itr)<<" "<<a[i]<<endl;
            s=b[i]+(*(it));
            //cout<<a[i]<<" "<<*(itr)<<endl;
            if(s<=c&&a[i]*(*(itr))<=k)
            {
                //d[r]=s;
                //e[r]=a[i]*e[q];
                d.push_back(s);
                e.push_back(a[i]*(*(itr)));
                r++;
            }
            else
            {
                //cout<<"a";
                it1=it;
                itr1=itr;
                it1--;
                itr1--;
               // cout<<*(itr)<<" "<<*(itr1)<<endl;
                d.erase(it);
                e.erase(itr);
                //for(itr=e.begin();itr!=e.end();itr++)
                  //  cout<<*(itr)<<" ";
                //cout<<*(itr1)<<endl;
                it=it1;
                itr=itr1;
                //cout<<*(itr)<<" ";
            }
            it++;
            itr++;
        }
        }
        else
            break;
        j=r-1;
    }
   // for(itr=e.begin();itr!=e.end();itr++)
     //   cout<<*(itr);
    cout<<j+1;
    }
    return 0;
} 