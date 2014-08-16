import java.util.*;

public class main {

  public static void main(String[] args) {
    Set<Integer> primes = getPrimes(1000000);

    int[] pow10 = new int[7];
    pow10[0] = 1;
    for (int i = 1; i < pow10.length; i++) {
      pow10[i] = 10 * pow10[i - 1];
    }

    int numCircular = 0;

    for (int p : primes) {
      int[] digits = getDigits(p);
      
      boolean isCircular = true;

      // Try all digit rotations
      for (int i = 0; i < digits.length; i++) {
        int n = 0;
        for (int j = 0; j < digits.length; j++) {
          n += digits[(i + j) % digits.length] * pow10[j];
        }
        if (!primes.contains(n)) isCircular = false;
      }

      if (isCircular) numCircular++;
    }

    System.out.println(numCircular);
  }

  public static Set<Integer> getPrimes(int max) {
    Set<Integer> primes = new LinkedHashSet<Integer>();

    if (2 < max) primes.add(2);
    for (int n = 3; n < max; n++) {
      boolean isPrime = true;

      for (int p : primes) {
        if (p * p > n) break;

        if (n % p == 0) {
          isPrime = false;
          break;
        }
      }

      if (isPrime) primes.add(n);
    }
    return primes;
  }

  public static int[] getDigits(int num) {
    int numDigits = (int)Math.ceil(Math.log10(num));

    int[] digits = new int[numDigits];

    for (int i = 0; i < numDigits; i++) {
      digits[i] = num % 10;
      num /= 10;
    }

    return digits;
  }

}
