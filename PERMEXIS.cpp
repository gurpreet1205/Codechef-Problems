#include<stdio.h>
int main()
{
    int t,n,i,j,k,min,max,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            min=a[0];
            max=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
        if((max-min+1)>n)
            printf("NO\n");
            else
            {
        for(i=min;i<=max;i++)
        {
            x=0;
            for(j=0;j<n;j++)
            {
            if(i==a[j])
            {
                x++;
                break;
            }
        }
        if(x==0)
            break;
    }
    if(i==max+1)
        printf("YES\n");
    else
        printf("NO\n");
}
}
return 0;
}