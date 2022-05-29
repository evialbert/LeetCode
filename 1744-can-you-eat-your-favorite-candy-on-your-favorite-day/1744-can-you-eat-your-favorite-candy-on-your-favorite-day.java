class Solution {
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        boolean[] result = new boolean[queries.length];
        long[] candiesComm = new long[candiesCount.length + 1];
        for (int i = 1; i <= candiesCount.length; i++) {
            candiesComm[i] = candiesComm[i - 1] + candiesCount[i - 1];
        }
        for (int i = 0; i < queries.length; i++) {
            int type = queries[i][0];
            long day = queries[i][1];
            long cap = queries[i][2];
            result[i] = ((day + 1) * cap > candiesComm[type]) && day < candiesComm[type + 1];
        }

        return result;
    }
}