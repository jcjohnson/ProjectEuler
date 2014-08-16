import java.util.*;

public class main {

  private static final int SIZE = 80;

  public static void main(String[] args) {
    int answer = solve(readMatrix(SIZE));
    System.out.println(answer);
  }

  private static int[][] readMatrix(int size) {
    Scanner sc = new Scanner(System.in);
    int[][] matrix = new int[size][size];
    int i = 0;
    while (sc.hasNextLine()) {
      String s = sc.nextLine();
      StringTokenizer st = new StringTokenizer(s, ",");
      int j = 0;
      while (st.hasMoreTokens()) {
        matrix[i][j] = Integer.parseInt(st.nextToken());
        j++;
      }
      i++;
    }
    return matrix;
  }

  private static int solve(int[][] matrix) {
    int height = matrix.length;
    int width = matrix[0].length;
    int[][] dp = new int[height][width];
    for (int i = 0; i < height; i++) {
      dp[i][width - 1] = matrix[i][width - 1];
    }
    for (int j = width - 2; j >= 0; j--) {
      dp[0][j] = matrix[0][j] + dp[0][j + 1];
      for (int i = 1; i < height; i++) {
        dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j + 1]);
      }
      for (int i = height - 2; i >= 0; i--) {
        dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j]);
      }
    }
    int answer = Integer.MAX_VALUE;
    for (int i = 0; i < height; i++) {
      answer = min(dp[i][0], answer);
    }
    return answer;
  }

  private static int min(int a, int b) {
    return a < b ? a : b;
  }

}
