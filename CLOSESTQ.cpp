#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,p,q,i,j,k,c,d,m,cc,e,g,s2,s4,dist,dis,xx1,xx2,yy1,yy2,X,t=0;
    char ch;
    cin>>q;
    j=0;
    multiset<long long int>myset;
    multiset<long long int>::iterator it;
    vector<long long int>x;
    vector<long long int>y;
    dis=99999999;
    for(i=0;i<q;i++)
    {
        vector<long long int>::iterator itr;
        vector<long long int>::iterator itr1;
        //char s[100000];
        cin>>ch>>s2>>s4;
        //fflush(stdin);
        //scanf("%[^\n]s",s);
        //s2=s[2]-'0';
        /*for(j=3;s[j]!=' ';j++)
            s2=s2*10+s[j]-'0';
        j++;
        s4=s[j]-'0';
        for(j=j+1;s[j]!='\0';j++)
            s4=s4*10+s[j]-'0';*/
        if(ch=='+')
        {
            x.push_back(s2);
            y.push_back(s4);
        }
        else
        {
            itr=x.begin();
            itr1=y.begin();
            for(j=0;j<x.size();j++,itr++,itr1++)
            {
                if(x[j]==s2&&y[j]==s4)
                {
                    x.erase(itr);
                    y.erase(itr1);
                }
            }
        }
        //for(j=0;j<x.size();j++)
          //  cout<<x[j]<<" "<<y[j]<<" ";
        //cout<<endl;
        X=x.size();
        if((X<2)&&(t==0))
            cout<<0<<endl;
        else if((X<2)&&(t==1))
        {
            cout<<0<<endl;
            myset.clear();
        }
        else
        {
        if(ch=='+')
        {
            t=1;
            for(j=0;j<X-1;j++)
            {
                dist=((x[j]-s2)*(x[j]-s2)+(y[j]-s4)*(y[j]-s4));
                /*if(dis>dist)
                {
                    dis=dist;
                    xx1=x[j];
                    yy1=y[j];
                    xx2=x[X-1];
                    yy2=y[X-1];
                }*/
                myset.insert(dist);
            }
        }
            else
            {
                for(j=0;j<X;j++)
                {
                    dist=((x[j]-s2)*(x[j]-s2)+(y[j]-s4)*(y[j]-s4));
                    myset.erase(myset.find(dist));
                }
            }
            //for(it=myset.begin();it!=myset.end();it++)
              //  cout<<*(it)<<" ";
            //cout<<endl;
        //else if(ch=='-'&&(s2!=xx1||s4!=yy1)&&(s2!=xx2||s4!=yy2))
        //{
            //cout<<s2<<" "<<s4<<" "<<xx1<<" "<<yy1<<" "<<xx2<<" "<<yy2<<" ";
        //}
        //else
        //{
        //dis=99999999;
        /*for(j=0;j<X-1;j++)
        {
            for(k=j+1;k<X;k++)
            {
                dist=((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]));
                if(dis>dist)
                {
                    dis=dist;
                    xx1=x[j];
                    yy1=y[j];
                    xx2=x[X-1];
                    yy2=y[X-1];
                }
            }
        }*/
        //}
        cout<<*(myset.begin())<<endl;
        }
    }
    return 0;
}
 