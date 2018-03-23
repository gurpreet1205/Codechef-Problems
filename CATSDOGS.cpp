#include<stdio.h>
int main()
{
    long long int t,i,c,d,l;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&c,&d,&l);
        if(c<=2*d)
        {
            if((l%4==0)&&(l>=4*d)&&(l<=4*(c+d)))
                printf("yes\n");
            else
                printf("no\n");
        }
        else
        {
            if((l%4==0)&&(l>=4*(c-2*d+d))&&(l<=4*(c+d)))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}