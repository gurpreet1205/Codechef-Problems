#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i,j,k,c;
    cin>>t;
    while(t--)
    {
        c=0;
        char s[100001];
        cin>>s;
        i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='1')
            {
                if(c==2)
                    break;
                c=1;
            }
            else
            {
                if(c==1)
                c=2;
            }
            i++;
        }
        if(c!=0&&s[i]=='\0')
            cout<<"YES\n";
        else
            cout<<"NO\n";
 
        //cout<<c<<endl<<i;
    }
    return 0;
}