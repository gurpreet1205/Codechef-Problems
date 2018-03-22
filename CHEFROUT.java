import java.util.*;
class CHEFROUT
{
    public static void main(String ss[])
    {
        int t,n,i,j,k,c,s,e,l;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        while(t-->0)
        {
            String str=sc.next();
            c=0;
            s=0;
            e=0;
            l=str.length();
            for(i=0;i<l;i++)
            {
                if(str.charAt(i)=='C')
                {
                    if(c==1)
                        break;
                }
                if(str.charAt(i)=='E')
                {
                    if(e==1)
                        break;
                    c=1;
                }
                if(str.charAt(i)=='S')
                {
                    c=1;
                    e=1;
                }
            }
            if(i==l)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}
 