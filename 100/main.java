import java.math.BigInteger;

public class main {

  private static final BigInteger ONE = BigInteger.valueOf(1);
  private static final BigInteger TWO = BigInteger.valueOf(2);

  public static void main(String[] args) {
    BigInteger z = ONE;
    BigInteger t = ONE;
    BigInteger zz = BigInteger.valueOf(17);
    BigInteger tt = ONE;
    while (true) {
      if (zz.equals(tt)) {
        BigInteger x = z.add(ONE);
        BigInteger y = t.add(ONE).divide(TWO);
        System.out.println("x = " + x + "\ty = " + y);
      }
      if (zz.compareTo(tt) < 0) {
        z = z.add(ONE);        
        zz = zz.add(z.multiply(BigInteger.valueOf(16)));
      } else {
        tt = tt.add(t.add(ONE).multiply(BigInteger.valueOf(4)));
        t = t.add(TWO);
      }
    }
  }

}
