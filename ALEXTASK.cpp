#include<stdio.h>
 long long int hc(long long int a,long long int b)
 {
     long long int temp;
     while((a%b)!=0)
     {
         temp=a;
         a=b;
         b=temp%b;
     }
     return b;
 }
 int main()
 {
    long long int t,n,i,j,k,temp,c,h,min;
    scanf("%lld",&t);
     while(t--)
     {
         scanf("%lld",&n);
         long long int a[n];
         for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                  a[j+1]=temp;
                }
            }
        }
        min=a[0]*a[1];
         for(i=0;i<n-1;i++)
         {
             for(j=i+1;j<n;j++)
             {
                 h=hc(a[j],a[i]);
                 c=(a[i]*a[j])/h;
                 if(min>c)
                    min=c;
             }
         }
         printf("%lld\n",min);
     }
     return 0;
 }