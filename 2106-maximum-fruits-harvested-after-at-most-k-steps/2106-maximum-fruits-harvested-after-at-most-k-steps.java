class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        Map<Integer, Integer> fruitMap = new HashMap<>();
        for (int[] fruit : fruits) {
            fruitMap.put(fruit[0], fruit[1]);
        }

        int[] maxToLeft = new int[k + 1];
        int[] maxToRight = new int[k + 1];
        
        maxToLeft[0] = fruitMap.getOrDefault(startPos, 0);
        maxToRight[0] = fruitMap.getOrDefault(startPos, 0);
        int maxResult = maxToLeft[0];
        for (int i = 1; i <= k; i++) {
            if (startPos - i >= 0) {
                maxToLeft[i] = maxToLeft[i - 1] + fruitMap.getOrDefault(startPos - i, 0);
            } else {
                maxToLeft[i] = maxToLeft[i - 1];
            }
            maxResult = Math.max(maxResult, maxToLeft[i]);
            maxToRight[i] = maxToRight[i - 1] + fruitMap.getOrDefault(startPos + i, 0);
            maxResult = Math.max(maxResult, maxToRight[i]);
        }
        
        for (int j = 1; j < (k + 1) / 2; j++) {
            maxResult = Math.max(maxResult, maxToLeft[j] + maxToRight[k - 2 * j] - maxToRight[0]);
            maxResult = Math.max(maxResult, maxToRight[j] + maxToLeft[k - 2 * j] - maxToRight[0]);
        }
        
        return maxResult;
    }
}