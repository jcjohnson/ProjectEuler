import java.math.BigInteger;

public class main {

  public static void main(String[] args) {
    BigInteger ten = new BigInteger("10");
    BigInteger tenten = ten.pow(10);
    BigInteger sum = BigInteger.ZERO;

    BigInteger num = BigInteger.ONE;
    for (int i = 1; i <= 1000; i++) {
      sum = sum.add(num.modPow(num, tenten));
      sum = sum.mod(tenten);
      num = num.add(BigInteger.ONE);
    }

    System.out.println(sum);
  }

}
