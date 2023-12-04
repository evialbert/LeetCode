class Solution {
    public int minimumAddedCoins(int[] coins, int target) {
        Arrays.sort(coins);
        int n = coins.length, pos = 0, res = 0, x = 1;
        while (x <= target)	{
        	if (pos >= n || x < coins[pos]) {
        		res++;
        		x += x;
        	} else {
        		x += coins[pos++];
        	}
        }
        return res;
    }
}