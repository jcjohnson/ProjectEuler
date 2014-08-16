import java.util.*;
import java.math.*;

public class main {

  public static final BigInteger TEN = BigInteger.valueOf(10);
  
  public static final int MAX_ITERATIONS = 50;
    
  public static void main(String[] args) {
    int count = 0;
    for (int num = 1; num <= 10000; num++) {
      if (isLychrel(num)) count++;
    }
    System.out.println(count);
  }

  public static boolean isLychrel(int num) {
    BigInteger sum = BigInteger.valueOf(num);
    List<Integer> digits = getDigits(sum);
    List<Integer> reversed = reverse(digits);
    for (int i = 0; i < MAX_ITERATIONS; i++) {
      sum = sum.add(getValue(reversed));
      digits = getDigits(sum);
      reversed = reverse(digits);
      if (sameList(digits, reversed)) {
        // System.out.println(num + " took " + (i + 1) + " iterations.");
        return false;
      }
    }
    System.out.println(num + " might be a Lychrel number!");
    return true;
  }

  public static <T> List<T> reverse(List<T> list) {
    LinkedList<T> reversed = new LinkedList<T>();
    for (T elem : list) {
      reversed.addFirst(elem);
    }
    return reversed;
  }

  public static <T> boolean sameList(List<T> list1, List<T> list2) {
    Iterator<T> it1 = list1.iterator();
    Iterator<T> it2 = list2.iterator();
    while (it1.hasNext() && it2.hasNext()) {
      if (it1.next() != it2.next()) {
        return false;
      }
    }
    return !it1.hasNext() && !it2.hasNext();
  }

  public static List<Integer> getDigits(BigInteger num) {
    List<Integer> digits = new LinkedList<Integer>();
    while (!num.equals(BigInteger.ZERO)) {
      digits.add(num.mod(TEN).intValue());
      num = num.divide(TEN);
    }
    return digits;
  }

  public static BigInteger getValue(List<Integer> digits) {
    BigInteger val = BigInteger.ZERO;
    BigInteger pow = BigInteger.ONE;
    for (int d : digits) {
      val = val.add(BigInteger.valueOf(d).multiply(pow));
      pow = pow.multiply(TEN);
    }
    return val;
  }

}
