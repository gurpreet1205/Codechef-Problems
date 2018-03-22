#include<bits/stdc++.h>
using namespace std;
long long int comb(long long int n,long long int r,long long int *brr)
{
    if(brr[r]!=0)
        return brr[r];
    long long int i,j,c=1;
    for(i=1;i<=r;i++)
        c=(c*(n-i+1))/i;
    brr[r]=c;
    return c;
}
int main()
{
    long long int t,n,k,m,i,j,a,b,c,d,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        a=n/k;
        b=n%k;
        if(b==0)
            cout<<a<<" "<<1<<endl;
        else
        {
            s=0;
            a=a+1;
            long long int arr[a+1],brr[a+1],crr[a+1];
            for(i=0;i<a+1;i++)
            {
                brr[i]=0;
                arr[i]=0;
                crr[i]=0;
            }
            //arr[0]=0;
            arr[1]=1;
            cout<<a<<" ";
            for(i=1;i<=k-b;i++)
            {
                for(j=1;j<=i&&j<=a-1;j++)
                {
                    c=comb(a-1,j,brr);
                    s=s+c*arr[j];
                    //if(j!=1)
                    crr[j]=arr[j]+arr[j-1];
                    //cout<<s<<endl;
                }
                crr[j]=1;
                    for(j=0;j<a+1;j++)
                    {
                        arr[j]=crr[j];
                        //cout<<arr[i]<<endl;
                    }
                //arr[j]=1;
                //if(i==3)
                  //  cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<endl;
                //cout<<s<<endl;
            }
            s=s+1;
            cout<<s%m<<endl;
        }
    }
    return 0;
}
 