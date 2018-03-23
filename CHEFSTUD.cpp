#include<stdio.h>
#include<string.h>
int main()
{
    long long int t,i,j,k,l,p;
    char s[100001];
    scanf("%lld",&t);
    while(t--)
    {
        p=0;
        fflush(stdin);
        scanf("%s",s);
        l=strlen(s);
        for(i=1;i<l-1;i++)
        {
            if((s[i]=='<')&&(s[i+1]=='>'))
                p++;
        }
        printf("%lld\n",p);
    }
    return 0;
}