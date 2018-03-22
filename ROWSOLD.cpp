#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{
        long long int t,i,j,n,k,x,y,l,c;
        //t=sc.nextInt();
        cin>>t;
        while(t--)
        {
            i=0;
            y=0;
            c=0;
            x=0;
            char s[100001];
            fflush(stdin);
            cin>>s;
            //System.out.println(s);
            //l=s.length();
            //int a[100001];
            //for(i=0;s[i]!='/0';i++)
            while(s[i]!='\0')
                i++;
            l=i;
            for(i=0;i<l;i++)
            {
                if((s[i]=='1')&&(x!=0))
                {
                    a[x-1]=i-y-1;
                    x++;
                    y=i;
                }
                if((s[i]=='1')&&(x==0))
                {
                    y=i;
                    x++;
                }
            }
            //cout<<l<<endl;
            //System.out.println(x);
            a[x-1]=l-y-1;
            //for(i=0;i<x;i++)
                //cout<<a[i]<<" ";
            for(i=0;i<x;i++)
            {
                if(a[i]!=0)
                c=c+(a[i]+1)*(i+1);
            }
            //System.out.println(c);
            cout<<c<<endl;
        }
        return 0;
    }