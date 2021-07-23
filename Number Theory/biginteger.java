import java.util.Scanner;
import java.math.BigInteger;


class biginteger
{
    public static void main(String[] args)
    {
        java.util.Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
           int N = in.nextInt();
           BigInteger A = in.nextBigInteger();
           
           BigInteger sum = BigInteger.ZERO;

           for(int i=1;i<=N;++i)
           {
               sum = sum.add(A.pow(i).multiply(BigInteger.valueOf(i)));
           }         
           System.out.println(sum.toString());
        }
    }
}