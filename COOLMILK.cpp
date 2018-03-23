#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,j,t,n,k,e;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        char s[n][7];
        for(i=0;i<n;i++)
            scanf("%s",s+i);
        e=0;
        if(s[n-1][0]=='c')
            printf("NO\n");
        else
        {
        for(i=0;i<n-1;i++)
        {
            //printf("%c %c\n",s[i][0],s[i+1][0]);
            if((s[i][0]=='c')&&(s[i+1][0]=='c'))
            {
                e=1;
                break;
            }
        }
        if(e==0)
            printf("YES\n");
        else
            printf("NO\n");
        }
    }
    return 0;
}