#include<bits/stdc++.h>
using namespace std;
char s[4];
long long int bsearch(long long int first,long long int last,long long int k)
{
    long long int mid;
    //mid=(first+last)/2;
    if((first==last)||(first==last-1))
    {
        return first;
    }
    mid=(first+last)/2;
    cout<<"? "<<mid<<" "<<k<<"\n";
    fflush(stdout);
    cin>>s;
    if(s[0]=='N')
        bsearch(first,mid,k);
    else
        bsearch(mid,last,k);
}
long long int bisearch(long long int first,long long int last)
{
    long long int mid;
    if((first==last-1)||(first==last))
    {
        return first;
    }
    mid=(first+last)/2;
    cout<<"? 0 "<<mid<<"\n";
    fflush(stdout);
    cin>>s;
    if(s[0]=='N')
        bisearch(first,mid);
    else
        bisearch(mid,last);
}
int main()
{
    long long int i=1,j,k,n,t,l,ar,x,y,z;
        x=bsearch(0,1001,0);
        //cout<<x;
        y=bsearch(x,1001,2*x);
        z=bisearch(2*x,1001);
        ar=4*x*x+y*(z-2*x);
        cout<<"! "<<ar;
        return 0;
}