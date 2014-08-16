import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    Set<BigInteger> nums = new HashSet<BigInteger>();

    for (int a = 2; a <= 100; a++) {
      BigInteger aa = new BigInteger("" + a);
      for (int b = 2; b <= 100; b++) {
        nums.add(aa.pow(b));
      }
    }

    System.out.println(nums.size());
  }

}
