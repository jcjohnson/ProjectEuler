import java.util.Scanner;

public class main {

  public static void main(String[] args) {
    long max = 0;
    boolean flag = true;
    for (int num = 1; flag; num++) {
      flag = false;
      for (int n = 2; true; n++) {
        long prod = concatenatedProduct(num, n);

        if (numDigits(prod) > 9) {
          break;
        }

        flag = true;

        if (isPandigital(prod)) {
          System.out.println(prod);
          max = prod > max ? prod : max;
        }
      }
    }
    System.out.println("max is " + max);
  }

  static int[] getDigits(long num) {
    assert (num >= 0) : "bad number: " + num;
    int[] digits = new int[numDigits(num)];

    for (int i = 0; i < digits.length; i++) {
      digits[i] = (int)(num % 10);
      assert (0 <= digits[i] && digits[i] <= 9) : "bad digit in " + num;
      num /= 10;
    }

    return digits;
  }

  static int numDigits(long num) {
    int numDigits = 0;
    while (num != 0) {
      num /= 10;
      numDigits++;
    }
    return numDigits;
  }

  static long concatenate(long a, long b) {
    long factor = 1;
    for (int i = 0; i < numDigits(b); i++) {
      factor *= 10;
    }
    return factor * a + b;
  }

  static long concatenatedProduct(int num, int n) {
    long prod = 0;
    for (int i = 1; i <= n; i++) {
      prod = concatenate(prod, i * num);
    }
    return prod;
  }

  static boolean isPandigital(long num) {
    int[] digits = getDigits(num);
    boolean[] seen = new boolean[10];
    seen[0] = true;

    for (int i = 0; i < digits.length; i++) {
      if (seen[digits[i]]) return false;
      seen[digits[i]] = true;
    }

    for (int i = 0; i < seen.length; i++) {
      if (!seen[i]) return false;
    }

    return true;
  }

}
