#include<stdio.h>
#include<math.h>
int main()
{
    int R,a,b,c,i=0,j,k,arr[50],brr[50],crr[50];
    double s,r;
    scanf("%d",&R);
    a=1,b=1,c=1;
    for(a=1;a<=200;a++)
    {
        for(b=a;b<=200;b++)
        {
            for(c=b;c<=200;c++)
            {
                if((a<b+c)&&(c>a-b))
                {
                    s=(a+b+c)/2.0;
                    r=sqrt(((s-a)*(s-b)*(s-c))/s);
                    if(r==R)
                    {
                        arr[i]=a;
                        brr[i]=b;
                        crr[i]=c;
                        i++;
                    }
                }
            }
        }
    }
    printf("%d\n",i);
    for(j=0;j<i;j++)
        printf("%d %d %d\n",arr[j],brr[j],crr[j]);
    return 0;
}
 