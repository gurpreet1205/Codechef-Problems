import java.io.*;
import java.util.*;
import java.math.BigInteger;
class GCDMOD
{
	public static void main(String args[])throws IOException
	{
		int t;
		BigInteger a,b,n,x,y,z,p,pp=new BigInteger("1000000007");
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t-->0)
		{
			a=sc.nextBigInteger();
			b=sc.nextBigInteger();
			n=sc.nextBigInteger();
			p=a.subtract(b);
			if(a.compareTo(b)==0)
			{
				x=power(a,n,pp);
				y=power(b,n,pp);
				z=(x.add(y)).mod(pp);
				System.out.println(z);
			}
			else
			{
				x=power(a,n,p);
				y=power(b,n,p);
				z=(x.add(y)).mod(p);
				System.out.println(gcd(p,z).mod(pp));
			}
		}	


	}
	public static BigInteger power(BigInteger a,BigInteger b,BigInteger p)
	{
		BigInteger y=new BigInteger("2");
		BigInteger z;
		if(b.compareTo(new BigInteger("0"))==0)
		{
			z=new BigInteger("1");
			return z;
		}
		if(b.mod(y).compareTo(new BigInteger("0"))==0)
		{
			z=(power((a.multiply(a)).mod(p),b.divide(y),p)).mod(p);
			return z;
		}
		else
		{
			z=a.multiply(power((a.multiply(a)).mod(p),(b.subtract(new BigInteger("1"))).divide(y),p)).mod(p);
			return z;
		}
	}
	public static BigInteger gcd(BigInteger a,BigInteger b)
	{
		if(b.compareTo(new BigInteger("0"))==0)
			return a;
		if(a.mod(b).compareTo(new BigInteger("0"))==0)
			return b;
		return gcd(b,a.mod(b));
	}
}