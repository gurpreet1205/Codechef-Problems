import java.util.*;
class UNICOURS
{
    public static void main(String ss[])
    {
        int t,n,i,j,max,res;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        while(t-->0)
        {
            n=sc.nextInt();
            int a[]=new int[n];
            for(i=0;i<n;i++)
            {
                a[i]=sc.nextInt();
            }
            max=a[0];
            for(i=1;i<n;i++)
            {
                if(max<a[i])
                    max=a[i];
            }
            res=n-max;
            System.out.println(res);
        }
    }
}