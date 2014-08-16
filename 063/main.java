import java.math.*;

public class main {

  public static final BigInteger TEN = BigInteger.valueOf(10);

  public static void main(String[] args) {
    int count = 0;
    for (int b = 1; b <= 30; b++) {
      BigInteger a = BigInteger.ONE;
      int d = numDigits(a.pow(b));
      while (d <= b) {
        if (d == b) {
          System.out.println(a + "^" + b + " has " + d + " digits");
          count++;
        }
        a = a.add(BigInteger.ONE);
        d = numDigits(a.pow(b));
      }
    }

    System.out.println(count);
  }

  public static int numDigits(BigInteger num) {
    int digits = 0;
    while (!num.equals(BigInteger.ZERO)) {
      num = num.divide(TEN);
      digits++;
    }
    return digits;
  }

}
