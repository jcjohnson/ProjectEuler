public class main {

  public static void main(String[] args) {
    int[] coins = {1, 2, 5, 10, 20, 50, 100, 200};
    int answer = solve(coins, 200);
    System.out.println(answer);
  }

  static int solve(int[] coins, int val) {
    int[][] dp = new int[coins.length][val + 1];

    for (int i = 0; i <= val; i++) {
      dp[0][i] = 1;
    }

    for (int c = 1; c < coins.length; c++) {
      for (int i = 0; i <= val; i++) {
        for (int j = i; j >= 0; j -= coins[c]) {
          dp[c][i] += dp[c - 1][j];
        }
      }
    }

    return dp[coins.length - 1][val];
  }

}
