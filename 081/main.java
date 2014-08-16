import java.util.*;

public class main {

  private static final int size = 80;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[][] matrix = new int[size][size];
    int i = 0;
    while (sc.hasNextLine()) {
      String s = sc.nextLine();
      StringTokenizer st = new StringTokenizer(s, ",");
      int j = 0;
      while (st.hasMoreTokens()) {
        int num = Integer.parseInt(st.nextToken());
        matrix[i][j] = num;
        j++;
      }
      i++;
    }
    // printMatrix(matrix);
    System.out.println(solve(matrix));
  }

  private static void printMatrix(int[][] matrix) {
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }

  private static int solve(int[][] matrix) {
    int height = matrix.length;
    int width = matrix[0].length;
    int[][] dp = new int[height][width];
    dp[height - 1][width - 1] = matrix[height - 1][width - 1];
    for (int i = height - 2; i >= 0; i--) {
      dp[i][width - 1] = matrix[i][width - 1] + dp[i + 1][width - 1];
    }
    for (int j = width - 2; j >= 0; j--) {
      dp[height - 1][j] = matrix[height - 1][j] + dp[height - 1][j + 1];
    }
    for (int i = height - 2; i >= 0; i--) {
      for (int j = width - 2; j >= 0; j--) {
        dp[i][j] = matrix[i][j];
        int d = dp[i + 1][j];
        int r = dp[i][j + 1];
        dp[i][j] += d < r ? d : r;
      }
    }
    return dp[0][0];
  }

}
