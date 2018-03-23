#include<stdio.h>
long long int count;
double comb(long long int n,long long int r)
{
    long long int i,j;
    double pro=1;
    count=0;
    for(i=0;i<r;i++)
    {
        pro=pro*(n-i);
        pro=pro/(r-i);
        while(pro>1000000)
        {
            pro=pro*0.5;
            count++;
        }
        //printf("%lfa",pro);
    }
    //printf("%lf %lld\n",pro,count);
    return pro;
}
int main()
{
    long long int t,n,m,p,k,i,j,p1,p3,p2,p4;
    double a,sum,prob,pro,c,x;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&n,&m,&p,&k);
        if((n%2==0)&&(m%2==0))
        {
            p1=1;
            p2=0;
        }
        else
        {
            p1=0;
            p2=1;
        }
        if((n%2==0)||(m%2==0))
        {
            p3=1;
            p4=0;
        }
        else
        {
            p3=0;
            p4=1;
        }
        a=(p1+p3)*0.5;
        if(p==0)
            printf("1.000000\n");
        else if(a!=0.500000)
            printf("%lf\n",a);
        else
        {
            if(p>=k/2)
            {
            sum=0;
            pro=1;
            c=comb(k,p);
             sum=c;
             x=1;
            for(i=p+1;i<=k;i++)
            {
                c=(c*(k-i+1))/i;
                sum=sum+c*x;
                //printf("a\n");
                while(sum>1000000)
                {
                    sum=sum*0.5;
                    x=x*0.5;
                    count++;
                }
            }
           // printf("%lf\n",sum);
            if(count>k)
            {
                for(i=k;i<count;i++)
                    sum=sum/0.5;
            }
            else
            {
                for(i=count;i<k;i++)
                    sum=sum*0.5;
            }
            //printf("%lf\n",c);
            //sum=c;
            //for(i=p+1;i<=k;i++)
           // {
             //   sum=sum+(c*(k-i+1))/i;
            //}
        //prob=sum*pow(a,k);
        printf("%lf\n",sum);
            }
            else
            {
                sum=0;
            pro=1;
            c=comb(k,p-1);
             sum=c;
             x=1;
            for(i=p-2;i>0;i--)
            {
                c=(c/(k-i))*(i+1);
                sum=sum+c*x;
                //printf("a\n");
                while(sum>1000000)
                {
                    sum=sum*0.5;
                    x=x*0.5;
                    count++;
                }
            }
            //printf("%lf\n",sum);
            if(count>k)
            {
                for(i=k;i<count;i++)
                    sum=sum/0.5;
            }
            else
            {
                for(i=count;i<k;i++)
                    sum=sum*0.5;
            }
            //printf("%lf\n",c);
            //sum=c;
            //for(i=p+1;i<=k;i++)
           // {
             //   sum=sum+(c*(k-i+1))/i;
            //}
        //prob=sum*pow(a,k);
        printf("%lf\n",(1-sum));
            }
        }
    }
    return 0;
}