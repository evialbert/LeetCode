class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        // lo -> min bananas/hour, hi -> max bananas/hour
        int lo = 1, hi = maximum(piles);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    private int hoursNeeded(int[] piles, int eatPerHour) {
        int hoursNeeded = 0;
        for (int bananas : piles) {
            hoursNeeded += bananas / eatPerHour;
            if (bananas % eatPerHour != 0) {
                hoursNeeded++;
            }
        }
        return hoursNeeded;
    }
    
    private int maximum(int[] piles) {
        int maxBananaPile = 0;
        for (int bananas : piles) {
            maxBananaPile = Math.max(maxBananaPile, bananas);
        }
        return maxBananaPile;
    }
}
