#include<stdio.h>
int main()
{
    int T,n,j;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        char a[3];
        scanf("%d %c %c %c",&n,&a[0],&a[1],&a[2]);
        int b[n];
        fflush(stdin);
        for(j=0;j<n;j++)
            scanf("%d",&b[j]);
            if((n==1)&&(b[0]%2==0))
            {
                if((a[0]=='D')&&(a[1]=='e')&&(a[2]=='e'))
                printf("Dee\n");
                else
                    printf("Dum\n");
            }
            else
                printf("Dum\n");
    }
    return 0;
}