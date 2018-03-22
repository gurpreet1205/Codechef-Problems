#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int co,ci;
    struct node *next;
}*start[100001];
long long int N,K,M,X,S;
long long int label[100001];
long long int state[100001];
void dijikistra()
{
    long long int cost[N+1];
   long long int i,j,k,c,x,y,z=0;
    multimap<long long int,long long int>mymap1;
    multimap<long long int,long long int>mymap2;
    multimap<long long int,long long int>::iterator it;
    //multimap<int,char>::iterator it2;
    long long int src=S;
    long long int curr=S;
    state[S]=1;
    mymap1.insert(pair<long long int,long long int>(0,S));
    cost[S]=0;
    for(k=1;k<N;k++)
    {
        x=curr;
    //for(i=0;i<n;i++)
    //{
        //if((a[x][i]!=0)&&(state[i]==0))
        //{
          //  if(label[i]==0)
            //{
              //  label[i]=label[x]+a[x][i];
                //mymap2.insert(pair<int,char>(label[i],(char)(i+65)));
            //}
            //else
            //{
              //  label[i]=min(label[i],label[x]+a[x][i]);
                //if(label[i]==label[x]+a[x][i])
                  //  mymap2.insert(pair<int,char>(label[i],(char)(i+65)));
            //}
       // }
    //}
    struct node *p=start[x-1];
    while(p!=NULL)
    {
        if(state[p->ci]==0)
        {
            if(label[p->ci]==0)
            {
                label[p->ci]=label[x]+p->co;
                mymap2.insert(pair<long long int,long long int>(label[p->ci],p->ci));
            }
            else
            {
                label[p->ci]=min(label[p->ci],label[x]+p->co);
                if(label[p->ci]==label[x]+p->co)
                mymap2.insert(pair<long long int,long long int>(label[p->ci],p->ci));
            }
        }
        p=p->next;
    }
    if((x<=K)&&(z==0))
    {
        z=1;
        for(i=1;i<=K;i++)
        {
            if(i!=x)
            {
                if(state[i]==0)
                {
                if(label[i]==0)
                {
                label[i]=label[x]+X;
                //cout<<label[i]<<" "<<x<<" "<<label[x]<<" ";
                mymap2.insert(pair<long long int,long long int>(label[i],i));
                }
                else
                {
                label[i]=min(label[i],label[x]+X);
                if(label[i]==label[x]+X)
                mymap2.insert(pair<long long int,long long int>(label[i],i));
                }
            }
            }
        }
    }
    //if(mymap2.empty())
      //  break;
        it=mymap2.begin();
        while(state[((*it).second)]==1)
        {
            mymap2.erase(it);
            it=mymap2.begin();
        }
        mymap1.insert(pair<long long int,long long int>((*it).first,(*it).second));
        state[((*it).second)]=1;
        curr=(*it).second;
        //cost=cost+(*it).first;
        cost[(*it).second]=(*it).first;
        //cout<<(*it).second<<" "<<(*it).first<<" "<<k<<endl;
        mymap2.erase(it);
    }
    //for(it=mymap1.begin();it!=mymap1.end();it++)
      //  cout<<(*it).second<<" "<<(*it).first<<endl;
    //cout<<cost;
    for(i=1;i<=N;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
}
int main()
{
    long long int t,n,k,m,x,s,i,j,y,z,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>N>>K>>X>>M>>S;
        //(struct node *p)[n];
        for(i=0;i<100001;i++)
        {
            state[i]=0;
            label[i]=0;
            start[i]=NULL;
        }
        for(i=0;i<M;i++)
        {
            cin>>a>>b>>c;
            struct node *q=(struct node *)malloc(sizeof(struct node));
            struct node *r=(struct node *)malloc(sizeof(struct node));
            q->ci=a;
            q->co=c;
            q->next=start[b-1];
            start[b-1]=q;
            r->ci=b;
            r->co=c;
            r->next=start[a-1];
            start[a-1]=r;
        }
        dijikistra();
    }
}