#include<bits/stdc++.h>
using namespace std;
void swap(long long int *a,long long int *b)
{
    long long int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void qsort(long long int *a,long long int n)
{
    if((n==0)||(n==1))
        return;
    long long int i=0,j=0;
    while(j<n-1)
    {
    if(a[j]<a[n-1])
    {
        swap(&a[i],&a[j]);
        i++;
    }
    j++;
    }
    swap(&a[i],&a[n-1]);
    qsort(a,i);
    qsort(a+i+1,n-i-1);
}
//long long int mid;
/*long long int bsearch(long long int *a,long long int first,long long int last,long long int num)
{
    while(first<=last)
    {
        mid=(first+last)/2;
    if(a[mid]<=num&&(first==last||a[mid+1]>num))
        return mid;
    else if(a[mid]>num)
        last=mid-1;
    else
        first=mid+1;
    }
    return -1;
}*/
int main()
{
    
    std::ios_base::sync_with_stdio(0);
    long long int t,i,j,p,q,r,res,ss1,ss2,h;
    cin>>t;
    while(t--)
    {
        cin>>p>>q>>r;
        res=0;
        ss1=0;
        ss2=0;
        //cout<<"b";
        long long int a[p],b[q],c[r],s1[p],s3[r],s2[q],s4[q],b1[q],b2[q];
        //cout<<"a";
        for(i=0;i<p;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<q;i++)
        {
            cin>>b[i];
            b1[i]=p-1;
            b2[i]=r-1;
        }
        for(i=0;i<r;i++)
        {
            cin>>c[i];
        }
        qsort(a,p);
        qsort(b,q);
        qsort(c,r);
        j=0;
        for(i=0;i<p;i++)
        {
            if(i==0)
                s1[i]=a[i];
            else
                s1[i]=s1[i-1]+a[i];
            if((j<q)&&(a[i]>b[j]))
            {
                if(i==0)
                    b1[j]=-1;
                else
                    b1[j]=i-1;
                i--;
                j++;
            }
        }
        j=0;
        for(i=0;i<r;i++)
        {
            if(i==0)
                s3[i]=c[i];
            else
                s3[i]=s3[i-1]+c[i];
            if((j<q)&&(c[i]>b[j]))
            {
                if(i==0)
                    b2[j]=-1;
                else
                    b2[j]=i-1;
                i--;
                j++;
            }
        }
        for(i=0;i<q;i++)
        {
            //pos=bsearch(a,ss1,p-1,b[i]);
            //ss1=pos;
            if(b1[i]==-1)
                s2[i]=0;
            else
                s2[i]=s1[b1[i]]+b[i]*(b1[i]+1);
            if(s2[i]>=1000000007)
                s2[i]=s2[i]%1000000007;
            //pos=bsearch(c,ss2,r-1,b[i]);
            //ss2=pos;
            if(b2[i]==-1)
                s4[i]=0;
            else
                s4[i]=s3[b2[i]]+b[i]*(b2[i]+1);
            if(s4[i]>=1000000007)
                s4[i]=s4[i]%1000000007;
            h=s2[i]*s4[i];
            if(h>=1000000007)
                h=h%1000000007;
            res=res+h;
            //if(res>=1000000007)
                //res=res%1000000007;
            //cout<<s1[i]<<" "<<s2[i]<<" "<<s3[i]<<" "<<s4[i]<<endl;
        }
        res=res%1000000007;
        cout<<res<<endl;
    }
    return 0;
} 