class Solution {
  int mod = 1000000007;
  int[] memo;

  private int countGoodStrings(int low, int high, int zero, int one, int i) {
    if (i > high) return 0;
    
    if (memo[i] != -1) return memo[i];

    memo[i] = i >= low && i <= high ? 1 : 0;

    memo[i] = (memo[i] + countGoodStrings(low, high, zero, one, i + zero)) % mod;
    memo[i] = (memo[i] + countGoodStrings(low, high, zero, one, i + one)) % mod;

    return memo[i];
  }

  public int countGoodStrings(int low, int high, int zero, int one) {
    memo = new int[high + 1];
    Arrays.fill(memo, -1);

    return countGoodStrings(low, high, zero, one, 0);
  }
}