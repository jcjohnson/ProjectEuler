public class main {

  public static final int N = 10001;

  public static void main(String[] args) {
    int[] primes = new int[N];
    primes[0] = 2;

    int nextIndex = 1;

    int i = 3;
    while (nextIndex < N) {
      boolean isPrime = true;
      for (int j = 0; j < nextIndex && primes[j] * primes[j] <= i; j++) {
        if (i % primes[j] == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) primes[nextIndex++] = i;
      i++;
    }

    System.out.println(primes[N - 1]);
  }

}
