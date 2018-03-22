#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int arr[51];
};
int main()
{
    long long int t,i,j,k,n,x,y,c,u,w,e,z,v;
    cin>>t;
    while(t--)
    {
        u=0;
        e=0;
        cin>>n>>k;
        //long long int a[n][2500];
        struct node obj[n]={0};
        long long int l[n];
        for(i=0;i<n;i++)
        {
            cin>>l[i];
            for(j=0;j<l[i];j++)
            {
                cin>>x;
                //x=j+1;
                y=(x-1)/50;
                z=(x-1)%50;
                obj[i].arr[y]=obj[i].arr[y]+pow(2,z);
            }
            //cout<<obj[i].arr[0]<<" "<<obj[i].arr[1]<<obj[i].arr[2]<<endl;
        }
        w=pow(2,k%50);
        v=pow(2,50);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                e=0;
                for(x=0;x<k/50;x++)
                {
                    if((obj[i].arr[x]|obj[j].arr[x])!=v-1)
                    {
                        //cout<<(obj[i].arr[x]|obj[j].arr[x])<<endl;
                        e=1;
                        break;
                    }
                }
               // cout<<e<<endl;
                if(e==0)
                {
                    if(k%50==0)
                        u++;
                    //cout<<obj[i].arr[x]<<" "<<obj[j].arr[x]<<" "<<(obj[i].arr[x]|obj[j].arr[x])<<endl;
                    else if((obj[i].arr[x]|obj[j].arr[x])==w-1)
                    {
                        //cout<<obj[i].arr[x]<<" "<<obj[j].arr[x]<<" "<<(obj[i].arr[x]|obj[j].arr[x])<<endl;
                        u++;
                    }
                    else;
                }
            }
        }
        //cout<<w<<" "<<obj[0].arr[0]<<" "<<obj[1].arr[0]<<endl;
        cout<<u<<endl;
    }
    return 0;
}
 