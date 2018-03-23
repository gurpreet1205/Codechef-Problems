#include<stdio.h>
#include<string.h>
int main()
{
    char S[26],W[26];
    int i,N,j=0,k,p,q;
    scanf("%s",S);
    fflush(stdin);
    j=strlen(S);
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
    scanf("%s",W);
    fflush(stdin);
    k=strlen(W);
    for(p=0;p<k;p++)
    {
        for(q=0;q<j;q++)
        {
            if(W[p]==S[q])
                break;
        }
            if(q==j)
            {
                printf("No\n");
                break;
            }
    }
        if(p==k)
        printf("Yes\n");
    }
    return 0;
    }