#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,i,j,m;
double k,t,N,c1,c2,cost,c;
double a;
scanf("%lf",&t);
while(t--)
{
    c=0.0;
    cost=0.0;
    scanf("%lld",&n);
    double x[n],y[n];
    double l[n];
    for(i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    for(i=0;i<n-1;i++)
    {
        l[i]=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
    }
    l[n-1]=sqrt((x[n-1]-x[0])*(x[n-1]-x[0])+(y[n-1]-y[0])*(y[n-1]-y[0]));
    scanf("%lld",&m);
    double le[m],co[m];
    for(i=0;i<m;i++)
    {
        scanf("%lf %lf",&le[i],&co[i]);
    }
    if(m==1)
    {
         for(i=0;i<n;i++)
    {
    while(l[i]>le[0])
    {
        l[i]=l[i]-le[0];
        c++;
    }
    }
      printf("%lld\n",(long long int)((c+n)*co[0]));
    }
    if(m==2)
    {
    for(i=0;i<n;i++)
    {
        c1=1,c2=1;
        a=l[i];
    while(a>le[0])
    {
        a=a-le[0];
        c1++;
    }
    while(l[i]>le[1])
    {
        l[i]=l[i]-le[1];
        c2++;
    }
    if(c1*co[0]>c2*co[1])
        cost=cost+c2*co[1];
    else
        cost=cost+c1*co[0];
    }
 
    printf("%lld\n",(long long int)cost);
    }
}
    return 0;
}