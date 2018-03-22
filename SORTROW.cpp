#include<bits/stdc++.h>
long long int b[301]={0},r[301]={0};
using namespace std;
int main()
{
    long long int n,i,j,k,x,y,c,z,ro,co,t,q;
    cin>>n;
    long long int a[n][n],p[n][n];
    map<long long int,long long int>mymap;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(j<10)
                mymap.insert(pair<long long int,long long int>(a[i][j],i*10+j));
            else if((j>=10)&&(j<100))
                mymap.insert(pair<long long int,long long int>(a[i][j],(i+1)*10000+j));
            else
                mymap.insert(pair<long long int,long long int>(a[i][j],(i+1)*100000000+j));
        }
    }
    for(i=0;i<n;i++)
    {
        t=0;
        q=0;
        for(j=0;j<n-1;j++)
        {
            if(a[i][j]>a[i][j+1])
                t=1;
            else
                q=1;
            if((t==1)&&(q==1))
                break;
        }
        if(j==(n-1))
        {
            for(j=0;j<n;j++)
            {
                mymap.erase(a[i][j]);
                p[i][j]=a[i][j];
            }
            r[i]=1;
        }
    }
   // cout<<"a";
    map<long long int,long long int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        z=1000000;
        if(((*it).second)<=2999)
        {
        x=((*it).second)/10;
        y=((*it).second)%10;
        }
        else if(((*it).second)<=3000099)
        {
            //cout<<"c";
            x=(((*it).second)/10000)-1;
            y=((*it).second)%100;
        }
        else
        {
           // cout<<"c";
            x=(((*it).second)/100000000)-1;
            y=((*it).second)%1000;
        }
        //cout<<"b";
        for(i=0;i<n;i++)
        {
            //cout<<i<<" ";
            if((b[i]<n)&&(r[i]==0))
            {
            c=(x-i)*(x-i)+(y-b[i])*(y-b[i]);
            if(z>c)
            {
                z=c;
                ro=i;
                co=b[i];
            }
            }
        }
        //cout<<"a ";
        //cout<<ro<<" "<<co<<endl;
        b[ro]++;
        p[ro][co]=(*it).first;
        //cout<<ro<<" "<<co<<endl;
    }
    //j=0;
    //for(i=0;i<n;i++)
      //  sort(&p[i][j],&p[i][j]+n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}