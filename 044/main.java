import java.util.*;

public class main {

  public static void main(String[] args) {
    Set<Integer> pents = new LinkedHashSet<Integer>();
    for (int n = 1; n <= 10000; n++) {
      pents.add(n * (3 * n - 1) / 2);
    }

    int minDiff = -1;

    for (int p1 : pents) {
      for (int p2 : pents) {
        if (p2 >= p1) break;
        int sum = p1 + p2;
        int diff = p1 - p2;
        if (pents.contains(sum) && pents.contains(diff)) {
          if (minDiff < 0 || diff < minDiff) {
            System.out.println(p1 + " " + p2);
            minDiff = diff;
          }
        }
      }
    }

    System.out.println(minDiff);
  }

}
