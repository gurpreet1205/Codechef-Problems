#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int arr[26];
    long long int w,x,y,z;
};
struct node a1[10000]={0},a2[10000]={0};
int main()
{
    long long int N1,N2,i,j,brr[26],n,d,c=0,k,len;
    char str1[1001],str2[1001];
    scanf("%lld %lld",&N1,&N2);
    for(i=0;i<N1;i++)
    {
        a1[i].x=0;
        a1[i].y=0;
        a1[i].w=0;
        a1[i].z=0;
        fflush(stdin);
        scanf("%s",str1);
        len=strlen(str1);
        for(j=0;j<len;j++)
        {
            n=(int)str1[j]-65;
            a1[i].arr[n]=1;
        }
        for(j=0;j<7;j++)
        {
            a1[i].w=a1[i].w+a1[i].arr[j]*pow(2,(6-j));
        }
        for(j=7;j<14;j++)
        {
            a1[i].x=a1[i].x+a1[i].arr[j]*pow(2,(13-j));
        }
        for(j=14;j<20;j++)
        {
            a1[i].y=a1[i].y+a1[i].arr[j]*pow(2,(19-j));
        }
         for(j=20;j<26;j++)
        {
            a1[i].z=a1[i].z+a1[i].arr[j]*pow(2,(25-j));
        }
    }
    for(i=0;i<N2;i++)
    {
        a2[i].x=0;
        a2[i].y=0;
        a2[i].w=0;
        a2[i].z=0;
        fflush(stdin);
        scanf("%s",str2);
        len=strlen(str2);
        for(j=0;j<len;j++)
        {
            n=(int)str2[j]-65;
            a2[i].arr[n]=1;
        }
        for(j=0;j<7;j++)
        {
            a2[i].w=a2[i].w+a2[i].arr[j]*pow(2,(6-j));
        }
        for(j=7;j<14;j++)
        {
            a2[i].x=a2[i].x+a2[i].arr[j]*pow(2,(13-j));
        }
        for(j=14;j<20;j++)
        {
            a2[i].y=a2[i].y+a2[i].arr[j]*pow(2,(19-j));
        }
        for(j=20;j<26;j++)
        {
            a2[i].z=a2[i].z+a2[i].arr[j]*pow(2,(25-j));
        }
    }
    for(i=0;i<N1;i++)
    {
        for(j=0;j<N2;j++)
        {
            //printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",a1[i].w,a2[j].w,a1[i].x,a2[j].x,a1[i].y,a2[j].y,a1[i].z,a2[j].z);
            //printf("%d %d %d %d\n",(a1[i].w|a2[j].w),(a1[i].x|a2[j].x),(a1[i].y|a2[j].y),(a1[i].z|a2[j].z));
            if(((a1[i].w|a2[j].w)==127)&&((a1[i].x|a2[j].x)==127)&&((a1[i].y|a2[j].y)==63)&&((a1[i].z|a2[j].z)==63))
                c++;
            //d=0;
           // for(k=0;k<26;k++)
           // {
               // brr[k]=(a1[i].arr[k])|(a2[j].arr[k]);
                //if(brr[k]==0)
                //{
                //    d++;
               //     break;
                //}
            //}
        }
    }
    printf("%lld",c);
    return 0;
}