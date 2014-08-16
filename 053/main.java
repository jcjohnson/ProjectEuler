import java.util.*;
import java.math.BigInteger;

public class main {

  public static final int N = 100;
  public static final BigInteger T = BigInteger.valueOf(1000000);

  public static void main(String[] args) {
    BigInteger[][] ncr = new BigInteger[N + 1][N + 1];

    for (int n = 0; n <= N; n++) ncr[n][0] = BigInteger.ONE;
    for (int k = 1; k <= N; k++) ncr[0][k] = BigInteger.ZERO;

    int count = 0;
    for (int n = 1; n <= N; n++) {
      for (int k = 1; k <= N; k++) {
        ncr[n][k] = ncr[n - 1][k - 1].add(ncr[n - 1][k]);
        if (ncr[n][k].compareTo(T) > 0) {
          count++;
        }
      }
    }

    System.out.println(count);
  }

}
