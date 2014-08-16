import java.util.*;

public class main {

  public static void main(String[] args) {
    Set<Integer> primes = getPrimes(1000000);

    int[] pow10 = new int[7];
    pow10[0] = 1;
    for (int i = 1; i < pow10.length; i++) {
      pow10[i] = pow10[i - 1] * 10;
    }

    int sum = 0;
    for (int p : primes) {
      if (p > 10 && isTruncatable(p, primes, pow10)) {
        System.out.println(p);
        sum += p;
      }
    }

    System.out.println("sum = " + sum);
  }

  public static boolean isTruncatable(int p, Set<Integer> primes, int[] pow10) {
    int[] digits = getDigits(p);

    if (!primes.contains(p)) return false;
    
    for (int i = 1; i < digits.length; i++) {
      // Remove digits from the left
      int num = 0;
      for (int j = 0; j + i < digits.length; j++) {
        num += digits[i + j] * pow10[j];
      }

      if (!primes.contains(num)) return false;

      num = 0;
      for (int j = 0; j < i; j++) {
        num += digits[j] * pow10[j];
      }

      if (!primes.contains(num)) return false;
    }

    return true;
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
