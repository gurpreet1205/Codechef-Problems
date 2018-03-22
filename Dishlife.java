import java.util.*;
import java.io.*;
class Dishlife
{
    public static void main(String args[])throws Exception
    {
        Scanner sc=new Scanner(System.in);
        int t,i,j,n,k,x,y;
        t=sc.nextInt();
        while((t--)!=0)
        {
            x=0;
            y=0;
            n=sc.nextInt();
            k=sc.nextInt();
            int a[]=new int[n];
            int b[]=new int[k];
            for(i=0;i<k;i++)
                b[i]=0;
            int c[]=new int[1000001];
            for(i=0;i<n;i++)
            {
                a[i]=sc.nextInt();
                for(j=0;j<a[i];j++)
                {
                    c[x]=sc.nextInt();
                    b[c[x]-1]++;
                    x++;
                }
            }
            x=0;
            for(i=0;i<k;i++)
            {
                if(b[i]==0)
                    break;
            }
            if(i!=k)
                System.out.println("sad");
            else
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<a[i];j++)
                    {
                        if(b[c[x]-1]==1)
                            break;
                        x++;
                    }
                    if(j==a[i])
                        break;
                    x=y+a[i];
                    //System.out.println(x+" "+c[3]);
                    y=x;
                }
                if(i==n)
                    System.out.println("all");
                else
                    System.out.println("some");
            }
        }
    }
}