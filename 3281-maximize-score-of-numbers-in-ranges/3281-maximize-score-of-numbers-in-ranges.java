class Solution {
    public int maxPossibleScore(int[] start, int d) {
        int n = start.length;
        Arrays.sort(start);

        int low = 0;
        int high = Integer.MAX_VALUE;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(start, d, mid)) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }

    private boolean isPossible(int[] start, int d, int diff) {
        int prev = start[0];
        
        for(int i = 1; i < start.length; i++) {
            if(prev + diff > start[i] + d) return false;
            prev = Math.max(start[i], prev + diff);
        }

        return true;
    }
}