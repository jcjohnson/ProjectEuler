import java.math.BigInteger;

public class main {

  public static class BigFrac {
    private BigInteger num;
    private BigInteger den;

    public BigFrac(BigInteger num, BigInteger den) {
      BigInteger g = gcd(num, den);
      this.num = num.divide(g);
      this.den = den.divide(g);
    }

    public BigFrac(int num, int den) {
      this(BigInteger.valueOf(num), BigInteger.valueOf(den));
    }

    private static BigInteger gcd(BigInteger a, BigInteger b) {
      if (b.equals(BigInteger.ZERO)) {
        return a;
      } else {
        return gcd(b, a.mod(b));
      }
    }

    public BigInteger getNumerator() {
      return num;
    }

    public BigInteger getDenominator() {
      return den;
    }

    public BigFrac add(BigFrac other) {
      BigInteger n = num.multiply(other.den).add(den.multiply(other.num));
      BigInteger d = den.multiply(other.den);
      return new BigFrac(n, d);
    }

    public BigFrac add(BigInteger other) {
      BigInteger n = num.add(other.multiply(den));
      return new BigFrac(n, den);
    }

    public BigFrac add(int other) {
      return add(BigInteger.valueOf(other));
    }

    public BigFrac multiply(BigFrac other) {
      BigInteger n = num.multiply(other.num);
      BigInteger d = den.multiply(other.den);
      return new BigFrac(n, d);
    }

    public BigFrac inverse() {
      return new BigFrac(den, num);
    }

    public String toString() {
      return "" + num + " / " + den;
    }
  }

  public static void main(String[] args) {
    BigFrac f = getConvergent(99);
    System.out.println(digitSum(f.getNumerator()));
  }

  public static BigInteger digitSum(BigInteger n) {
    BigInteger sum = BigInteger.ZERO;
    while (!n.equals(BigInteger.ZERO)) {
      sum = sum.add(n.mod(BigInteger.valueOf(10)));
      n = n.divide(BigInteger.valueOf(10));
    }
    return sum;
  }

  public static BigFrac getConvergent(int n) {
    BigFrac f = new BigFrac(getA(n), 1);

    for (int k = n - 1; k >= 0; k--) {
      f = f.inverse().add(getA(k));
    }

    return f;
  }

  public static int getA(int k) {
    if (k == 0) return 2;
    if (k % 3 == 2) return 2 * ((k + 1) / 3);
    return 1;
  }

}
