import java.math.*;

public class main {

  public static void main(String[] args) {
    BigInteger e = BigInteger.valueOf(7830457);
    BigInteger f = BigInteger.valueOf(28433);
    BigInteger m = BigInteger.valueOf(10).pow(10);
    BigInteger TWO = BigInteger.valueOf(2);

    BigInteger p = TWO.modPow(e, m).multiply(f).add(BigInteger.ONE).mod(m);
    System.out.println(p);
  }

}
