import java.math.*;

public class Main {

  public static void main(String[] args) {
    int numDigits = 100;
    BigDecimal epsilon = new BigDecimal(0.001);
    for (int i = 0; i < numDigits; i++) {
      epsilon = epsilon.divide(BigDecimal.valueOf(10));
    }

    int digitSum = 0;
    int numSquares = 1;
    int nextSquare = 1;
    for (int n = 1; n <= 100; n++) {
      if (n == nextSquare) {
        System.out.println("Skipping n = " + n);
        nextSquare += 2 * numSquares + 1;
        numSquares++;
      } else {
        System.out.println("Computing square root for n = " + n);
        BigDecimal r = squareRoot(n, epsilon);
        digitSum += decimalDigitSum(r, numDigits);
      }
    }
    System.out.println(digitSum);
  }

  public static int squareRootLowerBound(int n) {
    int s = 0;
    int i = 0;
    for (; true; i++) {
      int next = s + 2 * i + 1;
      if (next <= n) {
        s = next;
      } else {
        break;
      }
    }
    return i;
  }

  public static int decimalDigitSum(BigDecimal x, int numDigits) {
    String s = x.toPlainString();
    int sum = 0;
    int numCounted = 0;
    int i = 0;
    while (numCounted < numDigits) {
      char c = s.charAt(i);
      if (c != '.') {
        sum += (c - '0');
        numCounted++;
      }
      i++;
    }
    return sum;
  }

  public static BigDecimal squareRoot(int n, BigDecimal epsilon) {
    BigDecimal target = new BigDecimal(n);
    int s = squareRootLowerBound(n);
    BigDecimal low = new BigDecimal(s);
    BigDecimal high = new BigDecimal(s + 1);

    BigDecimal TWO = new BigDecimal(2);

    while (high.subtract(low).compareTo(epsilon) > 0) {
      BigDecimal mid = high.add(low).divide(TWO);
      BigDecimal mid2 = mid.multiply(mid);
      if (mid2.compareTo(target) < 0) {
        low = mid;
      } else {
        high = mid;
      }
    }

    return low;
  }

}
