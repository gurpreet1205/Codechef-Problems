#include<bits/stdc++.h>
using namespace std;
/*void msort(long long int *a,long long int n,string *s1,string *s2,char *c)
{
    long long int b[n];
    string str1[n],str2[n];
    char e[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    msort(a,x,s1,s2,c);
    msort(a+x,n-x,s1+x,s2+x,c+x);
    long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            str1[k]=s1[j];
            str2[k]=s2[j];
            e[k]=c[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            str1[k]=s1[i];
            str2[k]=s2[i];
            e[k]=c[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            str1[k]=s1[j];
            str2[k]=s2[j];
            e[k]=c[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            str1[k]=s1[i];
            str2[k]=s2[i];
            e[k]=c[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        s1[i]=str1[i];
        s2[i]=str2[i];
        c[i]=e[i];
    }
}*/
void mergesort(string *a,long long int n,char *c,long long int *arr)
{
    string b[n];
    char d[n];
    long long int e[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,arr);
    mergesort(a+x,n-x,c+x,arr+x);
    long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        //if(a[i]>a[j])
        if(a[i].compare(a[j])>0)
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=arr[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=arr[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=arr[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        arr[i]=e[i];
    }
}
int main()
{
    long long int n,i,j,k,d=0,e=0,co=0,l,flag;
    cin>>n;
    char c[n];
    string s[n],s1[n],s2[n],s3[n],s4[n];
    long long int ar[n];
    std::string::iterator it,it1;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        cin>>c[i];
        cin>>s[i];
        if(c[i]=='+')
            co++;
        s1[i]=="";
        s2[i]=="";
        ar[i]=i;
    }
    //for(i=0;i<n;i++)
    //{
      //  cout<<c[i]<<" "<<s[i]<<" "<<ar[i]<<endl;
   // }
   if(co==n)
    cout<<0;
   else
   {
    mergesort(s,n,c,ar);
    //for(i=0;i<n;i++)
      //  cout<<c[i]<<" "<<s[i]<<" "<<ar[i]<<endl;
    for(i=0;i<n;i++)
    {
        if(c[i]=='+')
        {
            d=1;
            s1[i]=s[i];
        }
        else if(c[i]=='-'&&d==0)
            s1[i]="";
        else if(c[i]=='-'&&d==1)
        {
            for(it=s[i].begin(),it1=s1[i-1].begin();it1!=s1[i-1].end();it++,it1++)
            {
                    if((*(it))==(*(it1)))
                        s1[i]=s1[i]+(*(it));
                    else
                    {
                        s1[i]=s1[i]+(*(it));
                        break;
                    }
            }
            if(it1==s1[i-1].end()&&(c[i-1]=='+'))
                s1[i]=s1[i]+(*(it));
        }
        else;
    }
    if(d==0)
    {
        for(i=0;i<n;i++)
        {
            it=s[i].begin();
            s3[i]=*(it);
        }
        j=0;
        s4[j]=s3[n-1];
        for(i=n-1;i>0;i--)
        {
            flag=0;
            for(it=s4[j].begin(),it1=s3[i-1].begin();it1!=s3[i-1].end();it++,it1++)
            {
                if(*(it)!=(*(it1)))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                j++;
                s4[j]=s3[i-1];
            }
        }
        cout<<j+1<<endl;
        for(i=j;i>=0;i--)
            cout<<s4[i]<<endl;
    }
    else
    {
    d=0;
    for(i=n-1;i>=0;i--)
    {
        if(c[i]=='+')
        {
            d=1;
            s2[i]=s[i];
        }
        else if(c[i]=='-'&&d==0)
            s2[i]="";
        else if(c[i]=='-'&&d==1)
        {
            for(it=s[i].begin(),it1=s2[i+1].begin();it!=s[i].end()&&it1!=s2[i+1].end();it++,it1++)
            {
                    if((*(it))==(*(it1)))
                        s2[i]=s2[i]+(*(it));
                    else
                    {
                        //cout<<*(it)<<" "<<*(it1)<<endl;
                        s2[i]=s2[i]+(*(it));
                        break;
                    }
            }
            if(it1==s2[i+1].end())
            {
                //cout<<s2[i]<<" a "<<s2[i+1];
            }
            else if(it==s[i].end()&&(it1!=s2[i+1].end()))
            {
                e=1;
                break;
            }
            else;
        }
        else;
    }
    //for(i=0;i<n;i++)
      //  cout<<s1[i]<<endl;
    //for(i=0;i<n;i++)
      //  cout<<s2[i]<<endl;
    if(e==1)
        cout<<-1;
    else
    {
        //msort(ar,n,s1,s2,c);
        k=0;
        //for(i=0;i<n;i++)
        //cout<<c[i]<<" "<<s1[i]<<" "<<s2[i]<<" "<<ar[i]<<endl;
        for(i=0;i<n;i++)
        {
            if(c[i]=='-')
            {
                if(s1[i].length()>s2[i].length())
                {
                    s3[k]=s1[i];
                    k++;
                }
                else
                {
                    s3[k]=s2[i];
                    k++;
                }
            }
        }
        //mesort(s3,k);
        j=0;
        s4[j]=s3[k-1];
        for(i=k-1;i>0;i--)
        {
            flag=0;
            for(it=s4[j].begin(),it1=s3[i-1].begin();it1!=s3[i-1].end();it++,it1++)
            {
                if(*(it)!=(*(it1)))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                j++;
                s4[j]=s3[i-1];
            }
        }
        cout<<j+1<<endl;
        for(i=j;i>=0;i--)
            cout<<s4[i]<<endl;
    }
    }
   }
    return 0;
}