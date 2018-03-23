#include<stdio.h>
int main()
{
    int T,i,a,b;
    scanf("%d",&T);
    while(T--)
    {
        a=0;
        b=0;
        i=0;
        char str[100001];
        fflush(stdin);
        scanf("%s",str);
        while(str[i]!='\0')
        {
            if(str[i]=='0')
                a++;
            if(str[i]=='1')
                b++;
            if((a>1)&&(b>1))
                break;
            i++;
        }
        if((a==1)||(b==1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}