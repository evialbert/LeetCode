class Solution {
    // Time: O(nlogN) where N is range of binary search
    // Space: O(1)
    public int shipWithinDays(int[] weights, int days) {
        // error checking
        int n = weights.length;
        int high = 0;
        int low = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            high += weights[i];
            low = Math.max(low, weights[i]);
        }
        return binarySearch(weights, low, high, days);
    }
    
    private int binarySearch(int[] weights, int low, int high, int days) {
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, mid, days)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    
    private boolean canShip(int[] weights, int minWeight, int days) {
        int daysTaken = 0;
        int currWeight = 0;
        for (int i = 0; i < weights.length; i++) {
            if (currWeight + weights[i] <= minWeight) {
                currWeight += weights[i];
            } else {
                daysTaken++;
                currWeight = weights[i];
            }
        }
        return daysTaken + 1 <= days;
    }

}