import java.util.*;

public class main {

  public static final int FAMILY_SIZE = 5;
  public static Set<Integer> primes;

  public static Set<Set<Integer>> solutions = new HashSet<Set<Integer>>();

  public static void main(String[] args) {
    primes = getPrimes(10000);
    solve(new HashSet<Integer>(), 0);
  }

  public static void solve(Set<Integer> family, int lastAdded) {
    if (family.size() == FAMILY_SIZE) {
      Set<Integer> sol = new HashSet<Integer>();
      for (int p : family) sol.add(p);

      int sum = 0;
      System.out.println("Here is a solution: ");
      for (int p : sol) {
        sum += p;
        System.out.println(p);
      }
      System.out.println("Sum is " + sum);
      System.out.println();

      solutions.add(sol);
      return;
    }

    // Try to add another one
    for (int p : primes) {
      if (family.size() == 0 || p > lastAdded) {
        // check to see if p works
        boolean works = true;
        for (int f : family) {
          if (!works) break;
          int fp = concatenate(f, p);
          int pf = concatenate(p, f);
          if (!isPrime(fp) || !isPrime(pf)) {
            works = false;
          }
        }

        if (works) {
          family.add(p);
          solve(family, p);
          family.remove(p);
        }
      }
    }

  }

  public static int concatenate(int a, int b) {
    List<Integer> digitsA = getDigits(a);
    List<Integer> digitsB = getDigits(b);
    for (int d : digitsA) {
      digitsB.add(d);
    }
    return getNum(digitsB);
  }

  public static int getNum(List<Integer> digits) {
    int num = 0;
    int pow = 1;
    for (int d : digits) {
      num += pow * d;
      pow *= 10;
    }
    return num;
  }

  public static List<Integer> getDigits(int num) {
    List<Integer> digits = new LinkedList<Integer>();
    while (num != 0) {
      digits.add(num % 10);
      num /= 10;
    }
    return digits;
  }

  public static boolean isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) return false;
    }
    return true;
  }

  public static Set<Integer> getPrimes(int max) {
    Set<Integer> primes = new LinkedHashSet<Integer>();
    for (int n = 2; n < max; n++) {
      boolean isPrime = true;
      for (int p : primes) {
        if (!isPrime || p * p > n) break;
        if (n % p == 0) isPrime = false;
      }
      if (isPrime) primes.add(n);
    }
    return primes;
  }

}
