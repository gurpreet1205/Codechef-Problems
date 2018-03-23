#include<stdio.h>
int main()
{
    float n,i,j,k,a,b,dist,sp,gs,gf;
    float t,s,sg,fg,d,ti;
    scanf("%f",&t);
    while(t--)
    {
        scanf("%f %f %f %f %f",&s,&sg,&fg,&d,&ti);
        dist=d*50;
        sp=s+((dist/ti)*(18.0/5.0));
        b=(sg+fg)/2;
        if(sg==fg)
            printf("DRAW\n");
        else if(sp>b)
        {
            if(sg>fg)
                printf("SEBI\n");
            else if(sg<fg)
                printf("FATHER\n");
            else
                printf("DRAW\n");
        }
        else if(sp<b)
        {
            if(sg<fg)
                printf("SEBI\n");
            else if(sg>fg)
                printf("FATHER\n");
            else
                printf("DRAW\n");
        }
        else
            printf("DRAW\n");
    }
    return 0;
}