#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,j,k,m,c,cs,co,co1,d;
    char ch,chh;
    cin>>t;
    while(t--)
    {
        co=0;
        m=0;
        cs=0;
        co1=0;
        char s[150001],ss[150001];
        cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            ss[i]=s[i];
            c=s[i]-'0';
            if(c>m)
            {
                m=c;
                ch=s[i];
            }
            if(s[i]==s[i+1])
                co++;
            if(s[i]=='0'||s[i]=='1')
                co1++;
        }
 
        //cout<<m<<" "<<c<<" "<<i<<endl;
        //cout<<co1<<endl;
        if(co==i-1)
            cout<<0<<endl;
        else if(co1==i)
        {
            long long int a[150001];
            for(j=0;j<150001;j++)
                a[j]=0;
            for(j=0;j<i;j++)
            {
                d=0;
                while((s[j]=='0')&&(j<i))
                {
                    j++;
                    d++;
                }
                a[d]++;
            }
            d=0;
            if(s[0]=='0')
            {
                for(j=0;s[j]!='1';j++)
                d++;
                a[d]--;
                cs=d;
            }
            d=0;
            if(s[i-1]=='0')
            {
                for(j=i-1;s[j]!='1';j--)
                    d++;
                s[d]--;
                if(cs<d)
                    cs=d;
            }
            for(j=1;j<150001;j++)
            {
                if(a[j]>0)
                {
                if(cs<(j+1)/2)
                cs=(j+1)/2;
                }
                //cout<<a[j]<<" ";
            }
            cout<<cs<<endl;
        }
        else
        {
        while(true)
        {
        for(j=0;j<i;j++)
        {
            chh='0';
                for(k=j+1;k<=j+ch-s[j]&&k<i;k++)
                {
                    //cout<<s[j]<<" "<<ss[k];
                    if(s[k]-s[j]>=k-j)
                    {
                    if(chh<s[k])
                    {
                    ss[j]=s[k];
                    chh=s[k];
                    }
                    //cout<<ss[k]<<" ";
                    }
                }
                for(k=j-1;k>=j-(ch-s[j])&&k>=0;k--)
                {
                    if(s[k]-s[j]>=j-k)
                    {
                    if(chh<s[k])
                    {
                    ss[j]=s[k];
                    chh=s[k];
                    }
                    }
                }
        }
        cs++;
        //for(j=0;j<i;j++)
        //{
          //  if(ss[j]!=ch)
          //      ss[j]=s[j];
        //}
 
        for(j=0;j<i;j++)
        {
        	if(ss[j]!=ch)
        	break;
		}
		if(j==i)
		break;
		else
        {
            for(j=0;j<i;j++)
            {
                //cout<<ss[j]<<" ";
                s[j]=ss[j];
            }
            //cout<<endl;
        }
        //if(cs==8)
          //  break;
   	 	}
   	 	cout<<cs<<endl;
    }
    }
    return 0;
}
 