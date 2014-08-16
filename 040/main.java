import java.util.Scanner;

public class main {

  public static void main(String[] args) {
    int prod = 1;
    for (int n = 1; n <= 1000000; n *= 10) {
      prod *= getDigit(n);
    }
    System.out.println(prod);
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

  static int getDigit(int n) {
    n--;
    for (int i = 1; true; i++) {
      int d = numDigits(i);
      if (n < d) {
        return getDigits(i)[d - n - 1];
      } else {
        n -= d;
      }
    }
  }

}
