import java.math.*;

public class main {

  public static final BigInteger TEN = BigInteger.valueOf(10);

  public static void main(String[] args) {
    long start = System.currentTimeMillis();

    BigInteger n = BigInteger.ONE;
    BigInteger d = BigInteger.valueOf(2);

    int count = 0;
    
    for (int i = 0; i < 1000; i++) {
      BigInteger nn = n.add(d);

      if (numDigits(nn) > numDigits(d)) {
        count++;
      }

      nn = n;
      n = d;
      d = d.add(d).add(nn);
    }

    long end = System.currentTimeMillis();
    System.out.println(count);
    System.out.println("Runtime was " + (end - start) + " ms.");
  }

  public static int numDigits(BigInteger n) {
    int count = 0;
    while (!n.equals(BigInteger.ZERO)) {
      count++;
      n = n.divide(TEN);
    }
    return count;
  }

}
