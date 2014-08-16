import java.util.*;

public class main {

  public static void main(String[] args) {
    Set<Integer> primes = getPrimes(10000);
    for (int i = 9; true; i += 2) {
      if (!primes.contains(i) && !works(i, primes)) {
        System.out.println(i);
        System.exit(0);
      }
    }
  }

  /*
   * Check to see if n can be written as the sum of a prime and twice a square.
   */
  public static boolean works(int n, Set<Integer> primes) {
    if (primes.contains(n)) return false;
    
    for (int p : primes) {
      int m = n - p;
      if (m % 2 == 1) continue;
      m /= 2;
      int r = (int) Math.sqrt(m);
      if (r * r == m) return true;
    }

    return false;
  }

  public static Set<Integer> getPrimes(int num) {
    Set<Integer> primes = new LinkedHashSet<Integer>();
    for (int i = 2; primes.size() < num; i++) {
      boolean isPrime = true;
      for (int p : primes) {
        if (!isPrime || p * p > i) break;
        if (i % p == 0) isPrime = false;
      }
      if (isPrime) primes.add(i);
    }
    return primes;
  }

}
