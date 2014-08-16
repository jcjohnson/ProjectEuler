import java.math.BigInteger;
import java.util.*;

public class main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int maxB = 1;
    int maxE = 1;
    int maxLineNum = -1;
    int lineNum = 1;
    while (sc.hasNextLine()) {
      StringTokenizer st = new StringTokenizer(sc.nextLine(), ",");
      int b = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      if (greater(b, e, maxB, maxE)) {
        maxB = b;
        maxE = e;
        maxLineNum = lineNum;
      }
      lineNum++;
    }
    System.out.println(maxLineNum);
  }

  public static boolean greater(int b1, int e1, int b2, int e2) {
    return e1 * Math.log(b1) > e2 * Math.log(b2);
  }

}
