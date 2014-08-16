import java.util.*;
import java.math.*;

public class main {

  public static final BigInteger TEN = BigInteger.valueOf(10);

  public static void main(String[] args) {
    Map<List<Integer>, Set<BigInteger>> cubes = new HashMap<List<Integer>, Set<BigInteger>>();
  
    for (int n = 1; true; n++) {
      BigInteger cube = BigInteger.valueOf(n);
      cube = cube.multiply(cube).multiply(cube);

      List<Integer> hist = getDigitHist(cube);

      if (!cubes.containsKey(hist)) {
        cubes.put(hist, new TreeSet<BigInteger>());
      }

      Set<BigInteger> set = cubes.get(hist);
      set.add(cube);
      if (set.size() == 5) {
        for (BigInteger c : set) {
          System.out.println(c);
        }
        System.exit(0);
      }
    }
  }

  public static List<Integer> getDigitHist(BigInteger num) {
    int[] digits = new int[10];
    while (!num.equals(BigInteger.ZERO)) {
      int d = num.mod(TEN).intValue();
      digits[d]++;
      num = num.divide(TEN);
    }
    List<Integer> hist = new LinkedList<Integer>();
    for (int i = 0; i < 10; i++) {
      hist.add(digits[i]);
    }
    return hist;
  }

}
