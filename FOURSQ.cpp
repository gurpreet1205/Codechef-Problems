#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,n,q,p,i,j,k,c,l,r,prod,b,d,e,g,arr[10000][4],s,x,sum;
    scanf("%lld",&t);
    while(t--)
    {
        g=0;
        scanf("%lld %lld %lld",&n,&q,&p);
        long long int a[n];
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<q;i++)
        {
            scanf("%lld %lld %lld",&c,&l,&r);
            if(c==1)
                a[l-1]=r;
            if(c==2)
            {
                prod=1;
                for(j=l-1;j<r;j++)
                    prod=((prod%p)*(a[j]%p))%p;
                //printf("%lld\n",prod);
                d=0;
                e=0;
                if(prod==0)
                {
                    arr[g][0]=0;
                    arr[g][1]=0;
                    arr[g][2]=0;
                    arr[g][3]=0;
                }
                else
                {
                x=0;
                b=(long long int)sqrt(prod);
                for(j=0;j<=b;j++)
                {
                    for(k=0;k<=b;k++)
                    {
                        for(l=0;l<=b;l++)
                        {
                            for(s=0;s<=b;s++)
                            {
                                sum=s*s+j*j+k*k+l*l;
                                if(sum==prod)
                                {
                                    arr[g][0]=j;
                                    arr[g][1]=k;
                                    arr[g][2]=l;
                                    arr[g][3]=s;
                                    x=1;
                                    break;
                                }
                            }
                            if(x==1)
                                break;
                        }
                        if(x==1)
                            break;
                    }
                    if(x==1)
                        break;
                }
                if(x==0)
                    arr[g][0]=-1;
                }
                g++;
            }
        }
        for(i=0;i<g;i++)
        {
            if(arr[i][0]==-1)
                printf("-1\n");
            else
                printf("%lld %lld %lld %lld\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3]);
        }
    }
    return 0;
}