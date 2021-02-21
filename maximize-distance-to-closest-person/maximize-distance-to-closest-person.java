class Solution {
    public int maxDistToClosest(int[] seats) {
        int max = 0, left = -1, len = seats.length;
        for (int i = 0; i < len; i++) {
            if (seats[i] == 1) {
                if (left == -1) max = Math.max(max, i);
                else max = Math.max(max, (i-left)/2);
                left = i;
            }
        }
        if (seats[len-1] == 0) max = Math.max(max, len-1-left);
        return max;
    }
}