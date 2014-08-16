import java.util.*;

public class main {

  public static List<Map<Integer, Set<Integer>>> nums;
  
  private static interface FigurateFormula {
    public int compute(int n);
  }

  private static FigurateFormula[] formulas = {
    null, // 0
    null, // 1
    null, // 2
    new FigurateFormula() { // 3
      public int compute(int n) {
        return n * (n + 1) / 2;
      }
    },
    new FigurateFormula() { // 4
      public int compute(int n) {
        return n * n;
      }
    },
    new FigurateFormula() { // 5
      public int compute(int n) {
        return n * (3 * n - 1) / 2;
      }
    },
    new FigurateFormula() { // 6
      public int compute(int n) {
        return n * (2 * n - 1);
      }
    },
    new FigurateFormula() { // 7
      public int compute(int n) {
        return n * (5 * n - 3) / 2;
      }
    },
    new FigurateFormula() { // 8
      public int compute(int n) {
        return n * (3 * n - 2);
      }
    }
  };


  public static void main(String[] args) {
    long t0 = System.currentTimeMillis();

    initializeNums();

    long t1 = System.currentTimeMillis();
    
    Iterable<Integer> solution = solve();

    long t2 = System.currentTimeMillis();

    int sum = 0;
    for (int n : solution) {
      System.out.print(n + " ");
      sum += n;
    }
    System.out.println();
    System.out.println(sum);

    long t3 = System.currentTimeMillis();

    System.out.println("Initialization took " + (t1 - t0) + " ms.");
    System.out.println("Depth first search took " + (t2 - t1) + " ms.");
    System.out.println("Summing and printing took " + (t3 - t2) + " ms.");
    System.out.println("Total time was " + (t3 - t0) + " ms.");
  }

  public static Iterable<Integer> solve() {
    Deque<Integer> list = new LinkedList<Integer>();
    boolean[] used = new boolean[9];
    if (solve(list, used)) {
      return list;
    }
    return null;
  }

  public static boolean solve(Deque<Integer> list, boolean[] used) {
    if (list.isEmpty()) {
      for (int k : nums.get(3).keySet()) {
        for (int s : nums.get(3).get(k)) {
          list.addFirst(s);
          used[3] = true;
          if (solve(list, used)) {
            return true;
          } else {
            list.removeFirst();
            used[3] = false;
          }
        }
      }
      return false;
    }

    int cur = list.peekLast();
    int curLastTwo = lastTwoDigits(cur);
    boolean allUsed = true;
    for (int p = 3; p <= 8; p++) {
      if (!used[p]) {
        allUsed = false;
        if (nums.get(p).containsKey(Integer.valueOf(curLastTwo))) {
          used[p] = true;
          for (int n : nums.get(p).get(curLastTwo)) {
            list.addLast(n);
            if (solve(list, used)) {
              return true;
            } else {
              list.removeLast();
            }
          }
          used[p] = false;
        }
      }
    }
    if (allUsed && firstTwoDigits(list.peekFirst()) == lastTwoDigits(list.peekLast())) {
      return true;
    } else {
      return false;
    }
  }

  public static void initializeNums() {
    nums = new ArrayList<Map<Integer, Set<Integer>>>(9);

    for (int p = 0; p < 3; p++) {
      nums.add(null);
    }

    for (int p = 3; p <= 8; p++) {
      nums.add(new HashMap<Integer, Set<Integer>>());
      for (int n = 1; true; n++) {
        int f = formulas[p].compute(n);
        if (numDigits(f) == 4) {
          int firstTwo = firstTwoDigits(f);
          if (!nums.get(p).containsKey(Integer.valueOf(firstTwo))) {
            nums.get(p).put(firstTwo, new HashSet<Integer>());
          }
          nums.get(p).get(firstTwo).add(f);
        } else if (numDigits(f) > 4) {
          break;
        }
      }
    }
  }

  public static int numDigits(int num) {
    int count = 0;
    while (num != 0) {
      count++;
      num /= 10;
    }
    return count;
  }

  public static int firstTwoDigits(int num) {
    while (num > 100) {
      num /= 10;
    }
    return num;
  }

  public static int lastTwoDigits(int num) {
    int last = num % 10;
    int second = (num / 10) % 10;
    return 10 * second + last;
  }

}
