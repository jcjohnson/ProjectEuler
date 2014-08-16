import java.math.*;

public class main {

  public static final BigInteger TEN = BigInteger.valueOf(10);

  public static void main(String[] args) {
    int max = 0;
    for (int a = 1; a < 100; a++) {
      for (int b = 0; b < 100; b++) {
        BigInteger num = BigInteger.valueOf(a).pow(b);
        int sum = digitSum(num);
        max = sum > max ? sum : max;
      }
    }
    System.out.println(max);
  }

  public static int digitSum(BigInteger num) {
    int sum = 0;
    while (!num.equals(BigInteger.ZERO)) {
      sum += num.mod(TEN).intValue();
      num = num.divide(TEN);
    }
    return sum;
  }

}
