import java.util.*;
import java.io.*;
class Simdish
{
    public static void main(String args[])throws Exception
    {
        Scanner sc=new Scanner(System.in);
        int t,i,j,n,c;
        String ing1[]=new String[4];
        String ing2[]=new String[4];
        t=sc.nextInt();
        while((t--)!=0)
        {
            c=0;
            for(i=0;i<4;i++)
                ing1[i]=sc.next();
            for(i=0;i<4;i++)
                ing2[i]=sc.next();
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(ing1[i].equals(ing2[j]))
                    {
                        c++;
                        break;
                    }
                }
                if(c==2)
                {
                    System.out.println("similar");
                    break;
                }
            }
            if(c!=2)
                System.out.println("dissimilar");
        }
    }
}
 