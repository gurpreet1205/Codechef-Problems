#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,j,b,l;
    scanf("%d",&T);
    while(T--)
    {
        b=0;
        char str[12346];
        fflush(stdin);
        scanf("%s",str);
        l=strlen(str);
        for(i=0;i<l/2;i++)
        {
            if((str[i]=='.')&&(str[l-i-1]=='.'))
            {
                str[i]='a';
                str[l-i-1]='a';
            }
            else if((str[i]=='.')&&(str[l-i-1]!='.'))
                str[i]=str[l-i-1];
            else if((str[i]!='.')&&(str[l-i-1]=='.'))
                str[l-i-1]=str[i];
            else if(str[i]!=str[l-i-1])
            {
                b=-1;
                printf("%d\n",b);
                break;
            }
        }
         if(b==0)
         {
             if((l%2!=0)&&(str[i]=='.'))
                str[i]='a';
             printf("%s\n",str);
         }
    }
    return 0;
}